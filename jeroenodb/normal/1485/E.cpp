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
const int mxN = 1e5+1;
const ll oo = 1e12;
void solve() {
    int n; cin >> n;
    vvi adj(n);
    for(int i=1;i<n;++i) {
        int v; cin >> v,--v;
        adj[i].push_back(v);
        adj[v].push_back(i);
    }
    vi q = {0};
    vi par(n),d(n);
    for(int i=0;i<n;++i) {
        int at = q[i];
        for(int to: adj[at]) {
            if(to and !d[to]) {
                d[to] = d[at]+1;
                par[to]=at;
                q.push_back(to);
            }
        }
    }
    vi a(n); for(int i=1;i<n;++i) cin >> a[i];
    vector<ll> dp(n);
    ll ans=0;
    for(int i=1,j=1;i<n;i=j) {
        while(j<n and d[q[i]]==d[q[j]]) ++j;
        // level is [i-j]
        ll mx[2] = {-oo,-oo}, mxa=-oo, mna=oo;
        for(int k=i;k<j;++k) {
            int at = q[k];
            auto curscore = dp[par[at]];
            mx[0] = max(mx[0],curscore+a[at]), mx[1] = max(mx[1],curscore-a[at]);
            mxa = max((ll)a[at],mxa),mna = min(mna,(ll)a[at]);
        }
        for(int k=i;k<j;++k) {
            int at = q[k];
            dp[at] = max({dp[par[at]] + max(mxa-a[at], a[at]-mna),mx[0]-a[at], mx[1]+a[at]});
            ans = max(ans,dp[at]);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}