#include <bits/stdc++.h>
using namespace std;
int N,M,K,a,b,t,node;
int dist[200100];
bool vis[200100];
vector <int> adj[200100];
vector<int> rev_adj [200100];
int main(){
    for(int i = 0; i < 200100; i++){
        dist[i]=1000000;
        vis[i]=0;
    }
    cin >> N >> M;
    while(M--){
        cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }
    cin >> K;
    int path[K];
    for(int i = 0; i < K; i++){
        cin >> path[i];
    }
    queue <int> q;
    q.push(path[K-1]);
    dist[path[K-1]]=0;
    while(!q.empty()){
        node = q.front();
        q.pop();
        vis[node]=1;
        t = dist[node];
        for(auto x: rev_adj[node]){
            if(!vis[x]){
                q.push(x);
                dist[x]=t+1;
                vis[x]=1;
            }
        }
    }
    int maxx = 0;
    int minn = 0;
    int mm = 0;
    for(int i = 0; i < K-2; i++){
        mm = 1000000;
        for(auto x: adj[path[i]]){
            if(x!=path[i+1]){
                mm = min(mm,dist[x]);
            }
        }
        if(mm < dist[path[i+1]])minn++;
        if(mm <= dist[path[i+1]])maxx++;
    }
    //for(int i = 1; i <=N; i++)cout << dist[i]<<" ";
    cout << minn << " " << maxx<<"\n";
    return 0;
}