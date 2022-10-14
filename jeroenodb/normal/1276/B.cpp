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
int underb=0,undera=0;
int d[mxN],lo[mxN],a,b,sz[mxN];
bool hasb[mxN],vis[mxN];
vi adj[mxN];
void dfs(int at, int from) {
    sz[at]=1;
    lo[at]=d[at];
    vis[at]=true;
    hasb[at] = b==at;
    for(auto to : adj[at]) if(to!=from) {
        
        if(!vis[to]) {
            d[to]=d[at]+1;
            dfs(to,at);
            sz[at]+=sz[to];
            hasb[at]|=hasb[to];

            lo[at]  =min(lo[at],lo[to]);
            if(at==b and lo[to]>=d[at]) {
                underb+=sz[to];
            }
            if(at==a and !hasb[to]) {
                undera+=sz[to];
            }
        } else {
            lo[at] = min(d[to],lo[at]);
        }
    }
    

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m >> a >> b;
        for(int i=1;i<=n;++i) adj[i].clear(),vis[i]=false;
        while(m--) {
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        undera=underb=0;
        d[a]=0;
        dfs(a,-1);
        cout << ll(undera)*underb << '\n';

    }
    

}