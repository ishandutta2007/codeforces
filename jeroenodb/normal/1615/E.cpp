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
const int mxN = 2e5+1;
const ll oo = 1e18;
vi adj[mxN];
bitset<mxN> vis;
int par[mxN], h[mxN], leaf[mxN];
void dfs(int at, int from=0) {
    if(from) adj[at].erase(find(all(adj[at]),from));
    leaf[at]=at;
    for(auto to : adj[at]) {
        dfs(to,at);
        par[to]=at;
        if(h[to]+1 > h[at]) {
            h[at] = h[to]+1;
            leaf[at] = leaf[to];
        }
    }
    
}
int main() {
    int n,k; cin >> n >> k;
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    vi cand(n); iota(all(cand),0); 
    sort(all(cand), [&](int i, int j) { return h[i]>h[j];});
    int blueleft=n;
    vis[0]=true;
    int redused=0;
    ll ans = -oo;
    for(auto i : cand) {
        if(vis[i]) continue;
        int at = leaf[i];
        blueleft-=h[i]+1;
        redused++;
        if(redused>k) break;
        // find minimum of f(x) = (n-r-x)*(r-x)
        ll cur =  ll(n-redused-blueleft)*(redused-blueleft);
        if(blueleft>=n/2) cur = min(cur, ll(n-redused-n/2)*(redused-n/2));
        if(blueleft> n/2) cur = min(cur, ll(n-redused-n/2 - 1)*(redused-n/2 - 1));
        ans = max(ans,cur);
        while(!vis[at]) {
            vis[at]=true;
            at = par[at];
        }
    }

    while(redused<k) {
        redused++;
        ans = max(ans, ll(redused)*(n-redused));
    }
    cout << ans << '\n'; 
    
}