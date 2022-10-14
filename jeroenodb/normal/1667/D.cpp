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
void solve() {
    int n; cin >> n;
    vvi adj(n);
    for(int i=1;i<n;++i) {
        int u,v; cin >> u >> v;
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<list<pi>> dp(n);
    bool bad=false;
    auto dfs = [&](auto self, int at, int from)->bool { // returns parity of subtree
        vi cs[2] = {};
        for(int to : adj[at]) if(to!=from) {
            cs[self(self,to,at)].push_back(to);
            if(bad) return false;
        }
        bool cur = adj[at].size()%2, used = from==-1;
        bool parity=false;
        while(!cs[0].empty() or !cs[1].empty() or !used) {
            if(cs[cur].empty()) {
                if(used) {
                    bad=true;
                    return false;
                }
                parity = cur;
                used=true;
                dp[at].push_back({from,at});
            } else {
                auto to = cs[cur].back();
                dp[at].splice(dp[at].end(),dp[to]);
                cs[cur].pop_back();
            }
            cur=!cur;
        }
        return parity;
    };
    dfs(dfs,0,-1);
    if(bad) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(auto [u,v] : dp[0]) {
        cout << u+1 << ' ' << v+1 << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}