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
    int n,m; cin >> n >> m;
    vi a(n),b(n); for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;
    vector<array<int,2>> ivs(m);
    for(auto& [l,r] : ivs) cin >> l >> r,--l;
    vector<ll> p(n+1);
    for(int i=0;i<n;++i) {
        p[i+1]=p[i]+a[i]-b[i];
    }
    set<int> nonzero;
    for(int i=0;i<=n;++i) if(p[i]) nonzero.insert(i);
    vi bad(m);
    vvi adj(n+1);
    queue<int> q;
    for(int i=0;i<m;++i) {
        auto [l,r] = ivs[i];
        adj[l].push_back(i);
        adj[r].push_back(i);
        bad[i] = (!!p[l]) + (!!p[r]);
        if(bad[i]==0) q.push(i);
    }
    while(!q.empty()) {
        auto at = q.front(); q.pop();
        auto [l,r] = ivs[at];
        auto it = nonzero.lower_bound(l);
        while(it!=nonzero.end() and *it<=r) {
            for(auto j : adj[*it]) {
                if(--bad[j]==0) {
                    q.push(j);
                }
            }
            it = nonzero.erase(it);
        }
    }
    cout << (nonzero.empty()?"YES\n":"NO\n");
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}