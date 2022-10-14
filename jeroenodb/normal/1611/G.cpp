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
    vector<string> g(n);
    for(auto& i : g) cin >> i;
    vector<pi> have[2];
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(g[i][j]=='1') have[(i^j)&1].push_back({i-j, i+j});
        }
    }
    int ans = 0;
    for(auto& v : have) {
        sort(all(v));
        vi dp;
        for(auto& [a,b] : v) {
            b=-b;
            auto it = lower_bound(all(dp),b);
            if(it==dp.end()) dp.push_back(b);
            else *it=b;
        }
        ans+=dp.size();
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}