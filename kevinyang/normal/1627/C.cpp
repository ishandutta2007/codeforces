#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>>edges;
        vector<vector<int>>adj(n+1);

        for(int i = 1; i<n; i++){
            int x,y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            edges.push_back({x,y});
        }
        bool f = true;
        for(int i = 1; i<=n; i++){
            if(adj[i].size()>=3){
                f = false;
            }
        }
        if(!f){
            cout << "-1\n";
            continue;
        }
        map<pair<int,int>,int>hm;
        vector<bool>vis(n+1);
        queue<int>q;
        vector<int>dis(n+1);
        int start = 0;
        for(int i = 1; i<=n; i++){
            if(adj[i].size()==1){
                start = i;
                break;
            }
        }
        vis[start] = true;
        q.push(start);
        dis[start] = 5;
        while(q.size()){
            int cur = q.front(); q.pop();
            for(int nxt: adj[cur]){
                if(vis[nxt])continue;
                vis[nxt] = true;
                if(dis[cur]==2){
                    dis[nxt] = 5;
                }
                else{
                    dis[nxt] = 2;
                }
                q.push(nxt);
                hm[{cur,nxt}] = dis[nxt];
                hm[{nxt,cur}] = dis[nxt];
            }
        }
        for(pair<int,int>nxt: edges){
            cout << hm[nxt] << " ";
        }
        cout << "\n";
    }
    return 0;
}