#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,a,b;
        cin >> n >> a >> b;
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i = 1; i<n; i++){
            int x,y,w;
            cin >> x >> y >> w;
            adj[x].push_back({w,y});
            adj[y].push_back({w,x});
        }
        vector<bool>vis(n+1);
        vector<int>dis(n+1);
        queue<int>q;
        map<int,int>hm;
        vis[a] = true;
        q.push(a);
        hm[0] = 1;
        while(q.size()){
            int cur = q.front(); q.pop();
            for(pair<int,int> nxt: adj[cur]){
                if(vis[nxt.second])continue;
                if(nxt.second==b)continue;
                vis[nxt.second]  = true;
                dis[nxt.second] = dis[cur]^nxt.first;
                hm[dis[nxt.second]] = 1;
                q.push(nxt.second);
            }
        }
        q.push(b);
        for(int i = 1; i<=n; i++){
            dis[i] = 0;
            vis[i] = false;
        }
        bool f = false;
        vis[b] = true;
        while(q.size()){
            int cur = q.front(); q.pop();
            for(pair<int,int>nxt: adj[cur]){
                if(vis[nxt.second])continue;
                vis[nxt.second] = true;
                dis[nxt.second] = dis[cur]^nxt.first;
                if(hm[dis[nxt.second]])f = true;
                q.push(nxt.second);
            }
        }
        if(f)cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}