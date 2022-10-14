#pragma GCC optimize "Ofast"
// #pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
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
const int mxN = 501, oo = 1e9;
short dp[mxN][mxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        for(int i=0;i<=n;++i) {
            for(int j=0;j<=m;++j) {
                dp[i][j] = 0;
            }
        }
        for(int i=0;i<n;++i) {
            string s; cin >> s;
            for(int j=0;j<m;++j) {
                dp[i][j] = s[j]=='*';
            }
        }

        int ans = 0;
        for(int i=n-1;i>=0;--i) {
            for(int j=0;j<m;++j) {
                if(dp[i][j]) {
                    dp[i][j] = 1+min({dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1]});
                }
                ans += dp[i][j];
            }
        }
        cout << ans << '\n';
    }

}