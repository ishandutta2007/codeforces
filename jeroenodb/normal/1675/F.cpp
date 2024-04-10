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
const int mxN = 1e5+1, oo = 1e9;
vvi adj;
vi par;
void bfs(vi q) {
    fill(all(par),-2);
    for(auto& i : q) par[i]=-1;
    for(int i=0;i<q.size();++i) {
        int at = q[i];
        for(auto to : adj[at]) {
            if(par[to]==-2) {
                par[to]=at;
                q.push_back(to);
            }
        }
    }
}
void solve() {
    int n,k; cin >> n >> k;
    int x,y; cin >> x >> y;
    --x,--y;
    adj.assign(n,{});
    vi a(k); for(auto& i : a) cin >> i,--i;
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v;
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    par.resize(n);
    bfs({x});
    vi path;
    for(int at=y;at!=-1;at=par[at]) {
        path.push_back(at);
    }
    bfs(path);
    // calculate subtree
    vector<bool> vis(n);
    int ans=0;
    for(auto i : a) {
        while(!vis[i] and par[i]!=-1) {
            vis[i]=true;
            i=par[i];
            
            ans+=2;
        }
    }
    cout << ans+path.size()-1 << '\n';


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}