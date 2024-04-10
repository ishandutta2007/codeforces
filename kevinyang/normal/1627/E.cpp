#include <bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
    int a,b,c,d,w;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        vector<int>arr(n+1);
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
        }
        vector<edge>edges(k);
        vector<pair<int,int>>sorted;
        sorted.push_back({0,0});
        sorted.push_back({1,1});
        sorted.push_back({n,m});
        vector<vector<int>>ind(n+1);
        ind[1].push_back(1);
        ind[n].push_back(m);
        for(int i = 0; i<k; i++){
            int a,b,c,d,w;
            cin >> a >> b >> c >> d >> w;
            edges[i] = {a,b,c,d,w};
            ind[a].push_back(b);
            ind[c].push_back(d);
            sorted.push_back({a,b});
            sorted.push_back({c,d});
        }
 
        sort(sorted.begin(),sorted.end());
        int start = lower_bound(sorted.begin(),sorted.end(),make_pair(1LL,1LL))-sorted.begin();
        int end = lower_bound(sorted.begin(),sorted.end(),make_pair(n,m))-sorted.begin();
        int nodes = sorted.size();
        vector<vector<pair<int,int>>>adj(nodes+5);
        vector<vector<pair<int,int>>>adj2(nodes+5);
        for(int i = 0; i<k; i++){
            int a = edges[i].a; int b = edges[i].b; int c = edges[i].c; int d = edges[i].d; int w = edges[i].w;
            int x = lower_bound(sorted.begin(),sorted.end(),make_pair(a,b))-sorted.begin();
            int y = lower_bound(sorted.begin(),sorted.end(),make_pair(c,d))-sorted.begin();
            adj2[x].push_back({w,y});
        }
        for(int i = 1; i<=n; i++){
            set<int>s;
            for(int nxt: ind[i]){
                s.insert(nxt);
            }
            ind[i].clear();
            for(int nxt: s){
                ind[i].push_back(nxt);
            }
            for(int j = 1; j<ind[i].size(); j++){
                int x = lower_bound(sorted.begin(),sorted.end(),make_pair(i,ind[i][j-1]))-sorted.begin();
                int y = lower_bound(sorted.begin(),sorted.end(),make_pair(i,ind[i][j]))-sorted.begin();
                adj[x].push_back({-1*(ind[i][j]-ind[i][j-1])*arr[i],y});
                adj[y].push_back({-1*(ind[i][j]-ind[i][j-1])*arr[i],x});
            }
        }
        vector<bool>vis(nodes+5);
        vector<int>dis(nodes+5,-(int)1e18);
        dis[start] = 0;
        for(int i = 1; i<=n; i++){
            priority_queue<pair<int,int>>pq;
            for(int j = 0; j<ind[i].size(); j++){
                int x = lower_bound(sorted.begin(),sorted.end(),make_pair(i,ind[i][j]))-sorted.begin();
                pq.push({dis[x],x});
            }
            while(pq.size()){
                pair<int,int>cur = pq.top(); pq.pop();
                if(vis[cur.second])continue;
                vis[cur.second] = true;
                for(pair<int,int>nxt: adj[cur.second]){
                    if(dis[nxt.second]<nxt.first+cur.first){
                        dis[nxt.second] = nxt.first+cur.first;
                        pq.push({dis[nxt.second],nxt.second});
                    }
                }
            }
            for(int j = 0; j<ind[i].size(); j++){
                int x = lower_bound(sorted.begin(),sorted.end(),make_pair(i,ind[i][j]))-sorted.begin();
                for(pair<int,int>nxt: adj2[x]){
                    dis[nxt.second] = max(dis[nxt.second],dis[x]+nxt.first);
                }
            }
        }
        /*
        for(int i = 1; i<nodes; i++){
            cout << dis[i] << " ";
        }
        */
        if(!vis[end]||dis[end]< -(int)1e17){
            cout << "NO ESCAPE\n";
        }
        else{
            cout << dis[end]*-1 << "\n";
        }
    }
    return 0;
}