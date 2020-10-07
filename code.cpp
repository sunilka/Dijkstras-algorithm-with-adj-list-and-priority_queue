// Implementing the diji algo
// with the help of adj list
// and min priority queue

#include<bits/stdc++.h>
using namespace std;

const int sizz = 1e+5;
vector<pair<int,int>> adj[sizz];
vector<int> d;

void diji(int source,int n)
{
    d.assign(n,INT_MAX);
    d[source] = 0;

    priority_queue<pair<int,int>> q;
    q.push({0,source});

    while(!q.empty()){
        int u = q.top().second;
        int w = q.top().first;

        if(u == n) break;
        int sizz = adj[u].size();
        for(int i=0;i<sizz;i++){
            int to = adj[u][i].first;
            int we = adj[u][i].second;

            // relaxation step
            if(d[to] > d[u]+we){
                d[to] = d[u]+we;
                q.push({-d[to],to});
            }
        }
        q.pop();
    }
}

int main()
{
   int n;
   cin>>n;

   int m;
   cin>>m;

   while(m--){
       int u,v,w;
       cin>>u>>v>>w;
       adj[u].push_back({v,w});
   }

   int source;
   cin>>source;
   diji(source,n);

   printf("\n printing the result after the diji algorithm \n");
   for(int i=0;i<n;i++){
        cout<<source<<" --> "<<i<<" = "<<d[i]<<endl;
   }
   cout<<endl;
}


