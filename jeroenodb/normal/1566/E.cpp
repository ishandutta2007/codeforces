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
vi adj[mxN];
int buds=0,deg[mxN];
bool rootleaf=false;
void dfs(int at, int from) {
    for(int to: adj[at]) if(to!=from) {
        dfs(to,at);
    }
    bool ambud = deg[at]!=1 and at!=1;
    buds+=ambud;
    deg[from]-=ambud;
    if(!ambud and from==1) rootleaf=true;
}
void solve() {
    int n; cin >> n;
    for(int i=0;i<=n;++i) adj[i].clear(),deg[i]=0;
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v),adj[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    buds=0,rootleaf=false;
    dfs(1,0);
    cout << n-2*buds-rootleaf << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}