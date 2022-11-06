#include <bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
    int t,x,y;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<vector<int>>adj(n+1);
    vector<vector<int>>g(n+1);
    vector<edge>edges(m);

    for(int i = 0; i<m; i++){
        int t,x,y;
        cin >> t >> x >> y;
        edges[i] = {t,x,y};
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<bool>vis(n+1);
    vector<int>dis(n+1);
    queue<int>q;
    for(int i = 1; i<=n; i++){
        if(vis[i])continue;
        vis[i] = true;q.push(i);
        while(q.size()){
            int cur = q.front(); q.pop();
            for(int nxt: g[cur]){
                if(vis[nxt])continue;
                vis[nxt] = true;
                dis[nxt] = dis[cur]+1;
                q.push(nxt);
            }
        }
    }
    bool f = true;
    for(int i = 1; i<=n; i++){
        dis[i]%=2;
        vis[i] = false;
    }
    vector<int>indegrees(n+1);
    for(int i = 0; i<m; i++){
        int t = edges[i].t; int x = edges[i].x; int y = edges[i].y;
        if((dis[x]^dis[y])!=1){
            cout << "NO\n";
            return 0;
        }
        if(dis[y]==0){
            swap(x,y);
        }
        if(t==1){
            adj[x].push_back(y);
            indegrees[y]++;
        }
        else{
            adj[y].push_back(x);
            indegrees[x]++;
        }
    }
    vector<int>ans(n+1);
    int idx = 1;
    for(int i = 1; i<=n; i++){
        if(indegrees[i]==0){
            q.push(i);
        }
    }
    while(q.size()){
        int cur = q.front(); q.pop();
        ans[cur] = idx; idx++;
        for(int nxt: adj[cur]){
            indegrees[nxt]--;
            if(indegrees[nxt]==0){
                q.push(nxt);
            }
        }
    }
    for(int i = 1; i<=n; i++){
        if(ans[i]==0){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for(int i = 1; i<=n; i++){
        if(dis[i]==0)cout << "L ";
        else cout << "R ";
        cout << ans[i] << "\n";
    }
    return 0;
}