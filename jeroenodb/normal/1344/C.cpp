#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int mxN = 2e5+1, oo = 1e9;
struct Graph {
    vi adj[mxN];
    void add(int u,int v) {adj[u].push_back(v);}
    bitset<mxN> vis,mark;
    void dfs(int at) {
        vis[at]=mark[at]=true;
        for(int to :  adj[at]) {
            if(mark[to]) {
                cout << "-1\n";
                exit(0); // found cycle
            }
            if(!vis[to]) dfs(to);
        }
        mark[at]=false;
    }
} g,r;
int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int n,m; cin >> n >> m;
    while(m--) {
        int u,v; cin >> u >> v,--u,--v;
        g.add(u,v);
        r.add(v,u);
    }
    string ans(n,'E');
    int cnt=0;
    for(int i=0;i<n;++i) {
        if(!g.vis[i] and !r.vis[i]) ans[i]='A',cnt++;
        if(!g.vis[i]) g.dfs(i);
        if(!r.vis[i]) r.dfs(i);
    }
    cout << cnt << '\n';
    cout << ans << '\n';
}