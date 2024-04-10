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
    int n,k; cin >> n >> k;
    vi p(n,-1);
    vvi adj(n);
    for(int i =1;i<n;++i) {
        cin >> p[i]; --p[i];
        adj[p[i]].push_back(i);
    }
    vi s(n); for(auto& i : s) cin >> i;
    // divide it by deg[root], those paths are always gonna be there
    // remainder needs be distributed
    // only need to calculate a DP for two values of the path
    vector<array<ll,2>> dp(n);
    auto dfs = [&](auto&& self, int at, int total) -> void{
        if(adj[at].empty()) {
            dp[at][0] = ll(total)*s[at];
            dp[at][1] = dp[at][0]+s[at];
            return;
        }
        int atleast = total/adj[at].size();
        for(int to : adj[at]) {
            self(self,to,atleast);
        }
        auto& my = dp[at];
        for(int extra : {0,1}) {
            total+=extra;
            int need = total-atleast*adj[at].size();
            // those are the extras, sort on how good of improvement it gives
            vi ord = adj[at];
            sort(all(ord),[&](int i, int j) {
                return dp[i][1]-dp[i][0]>dp[j][1]-dp[j][0];
            });
            my[extra] = total*ll(s[at]);
            for(int to : adj[at]) {
                my[extra]+=dp[to][0];
            }
            for(int o=0;o<need;++o) {
                int j = ord[o];
                my[extra]+=dp[j][1]-dp[j][0];
            }
            total-=extra;
        }
    };
    dfs(dfs,0,k);
    cout << dp[0][0] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}