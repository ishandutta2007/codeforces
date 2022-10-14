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
    vvi g(2*n);
    for(auto& i : g) {
        i.resize(2*n);
        for(auto& j : i) cin >> j;
    }
    ll ans=0;
    #define rep(i,a,b) for(int i=a;i<b;++i)
    rep(i,n,2*n) rep(j,n,2*n) ans+=g[i][j];
    int cur = oo;
    for(auto i : {0,n-1}) for(auto j : {0,n-1}) {
        cur = min(cur, g[i+n][j]);
        cur = min(cur, g[i][j+n]);
    }
    cout << ans + cur << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}