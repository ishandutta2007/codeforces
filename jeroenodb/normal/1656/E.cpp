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
vi w;
void dfs(int at, int from, int want) {
    w[at]=want;
    if(from==-1) w[at]--;
    for(int to : adj[at]) if(to!=from) {
        w[at]+=want;
        dfs(to,at,-want);
    }
}
void solve() {
    int n; cin >> n;
    adj.assign(n,{});
    w.assign(n,0);
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v;
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1,1);
    cout << w << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}