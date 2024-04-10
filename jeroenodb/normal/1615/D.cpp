#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 2e5+1, oo = 1e9;
vector<pi> adj2[mxN];
vector<pair<int,bool>> adj[mxN];
bitset<mxN> vis, col;
bool bad=false;
void dfs(int at) {
    vis[at]=true;
    for(auto [to,b] : adj[at]) {
        if(vis[to]) {
            if((int(col[to])^b)!=col[at]) bad=true;
        } else {
            col[to] = col[at]!=b;
            dfs(to);
        }
    }
}
vector<array<int,3>> ans;
void dfs2(int at) {
    vis[at]=true;
    for(auto [to,w] : adj2[at]) if(!vis[to]) {
        ans.push_back(array<int,3>{at,to,w==-1?int(col[at])^col[to]:w});
        dfs2(to);
    }
}
void solve() {
    int n,m; cin >> n >> m;
    for(int i=0;i<=n;++i) {
        vis[i]=false,col[i]=false;
        adj[i].clear();
        adj2[i].clear();
    }
    for(int i=0;i<n-1;++i) {
        int x,y,v; cin >> x >> y >> v;
        adj2[x].push_back({y,v});
        adj2[y].push_back({x,v});
        if(v!=-1) {
            v = __builtin_popcount(v)%2;
            adj[x].push_back({y,v});
            adj[y].push_back({x,v});
        }
       
    }
    while(m--) {
        int x,y,v; cin >> x >> y >> v;
        adj[x].push_back({y,v});
        adj[y].push_back({x,v});
    }
    bad=false;
    for(int i=1;i<=n;++i) if(!vis[i]) {
        dfs(i);
    }
    if(bad) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i=1;i<=n;++i) vis[i]=false;
    ans.clear();
    dfs2(1);
    for(auto i : ans) cout << i << '\n';

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}