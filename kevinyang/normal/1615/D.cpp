#include <bits/stdc++.h>
using namespace std;
#define int long long
struct DisjointSet{
    vector<int>parent,sz;
    int size;
    void init(int n){
        size = n;
        parent.resize(n+1); sz.resize(n+1);
        for(int i = 1; i<=n; i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x){
        if(parent[x]==x)return x;
        return find(parent[x]);
    }
    void Union(int x, int y){
        x = find(x); y = find(y);
        if(x==y)return;
        parent[x] = y;
        sz[y]+=sz[x];
    }
};
struct edge{
    int w,x,y;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<edge>edges(n);
        DisjointSet ds;
        ds.init(n);
        vector<vector<int>>sets(n+1);
        for(int i = 1; i<=n; i++){
            sets[i].push_back(i);
        }
        vector<int>group(n+1);
        bool f = true;
        for(int i = 0; i<n-1; i++){
            int x,y,w;
            cin >> x >> y >> w;
            edges[i] = {w,x,y};
            if(w==-1)continue;
            int v = __builtin_popcount(w)%2;
            if(true){
                int s1 = ds.find(x); int s2 = ds.find(y);
                if(s1==s2){
                    if(group[x]==group[y]&&v)f = false;
                    if(group[x]!=group[y]&&v==0)f = false;
                }
                else{
                    if(ds.sz[s1]<ds.sz[s2]){
                        int add = group[x]^group[y]^v;
                        for(int nxt: sets[s1]){
                            sets[s2].push_back(nxt);
                            group[nxt]^=add;
                        }
                        sets[s1].clear();
                        ds.Union(x,y);
                    }
                    else{
                        int add = group[x]^group[y]^v;
                        for(int nxt: sets[s2]){
                            sets[s1].push_back(nxt);
                            group[nxt]^=add;
                        }
                        sets[s2].clear();
                        ds.Union(y,x);
                    }
                }
            }
        }
        vector<edge>edges2(m);
        for(int i = 0; i<m; i++){
            int x,y,w;
            cin >> x >> y >> w;
            edges2[i] = {w,x,y};
            int v = __builtin_popcount(w)%2;
            if(true){
                int s1 = ds.find(x); int s2 = ds.find(y);
                if(s1==s2){
                    if(group[x]==group[y]&&v)f = false;
                    if(group[x]!=group[y]&&v==0)f = false;
                }
                else{
                    if(ds.sz[s1]<ds.sz[s2]){
                        int add = group[x]^group[y]^v;
                        for(int nxt: sets[s1]){
                            sets[s2].push_back(nxt);
                            group[nxt]^=add;
                        }
                        sets[s1].clear();
                        ds.Union(x,y);
                    }
                    else{
                        int add = group[x]^group[y]^v;
                        for(int nxt: sets[s2]){
                            sets[s1].push_back(nxt);
                            group[nxt]^=add;
                        }
                        sets[s2].clear();
                        ds.Union(y,x);
                    }
                }
            }
        }
        if(!f){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            for(int i = 0; i<n-1; i++){
                int x = edges[i].x; int y = edges[i].y;
                if(edges[i].w==-1)
                    cout << x << " " << y << " " << (group[x]^group[y]) << "\n";
                else{
                    cout << x << " " << y << " " << edges[i].w << "\n";
                }
            }
        }
    }
    return 0;
}