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
const int mxN = 5e5+2, oo = 1e9;
vi adj[mxN], dpth[mxN];
vi::iterator it[mxN];
bitset<mxN> vis;
int par[mxN], head[mxN];
pi best;
void dfs(int at, int n) {
    vi st = {at};
    st.reserve(n);
    vis[at]=true;
    it[1] = adj[1].begin();
    int d=0;
    while(!st.empty()) {
        at = st.back(); 
        while(it[at]!=adj[at].end() and vis[*it[at]]) ++it[at];
        if(it[at]==adj[at].end()) st.pop_back(), d--;
        else {
            d++;
            int to = *it[at];
            par[to]=at;
            dpth[d].push_back(to);
            best = max(best, {d,to});
            vis[to]=true;
            st.push_back(to);
            it[to] = adj[to].begin();

        }
    }
}
void solve() {
    int n,m; cin >> n>> m;
    for(int i=0;i<=n;++i) adj[i].clear(), dpth[i].clear(), vis[i]=false;
    for(int i=0;i<m;++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    best = {-oo,oo};
    dfs(1,n);
    int want = (n+1)/2;
    if(best.first >=want) {
        // biggest
        vi ans;
        int at = best.second;
        while(at) {
            ans.push_back(at);
            at= par[at];
        }
        cout << "PATH\n";
        cout << ans.size() << '\n';
        cout << ans << '\n';
    } else {
        vi q;
        vector<pi> ans;
        for(int i=0;i<=n;++i) {
            for(int j=0;j+1<(int)dpth[i].size();j+=2) {
                ans.emplace_back(dpth[i][j],dpth[i][j+1]);
            }
        }
        cout << "PAIRING\n";
        cout << ans.size() << '\n';
        for(auto [a,b]: ans) cout << a << ' ' << b << '\n';
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}