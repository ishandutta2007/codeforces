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
const int mxN = 500+1, oo = 1e9;
char g[mxN][mxN];
int pref[mxN],dp[mxN];
void solve() {
    int n,m; cin >> n >> m;
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) cin >> g[i][j],g[i][j]-='0';
    }
    int ans = oo;
    for(int l=0;l<m;++l) {
        fill(pref,pref+n,0);
        for(int r=l+1;r<m;++r) {
            if(l+3<=r) {
                int change=0;
                for(int i=0;i<n;++i) {
                    int isend = r-l-1-pref[i];
                    if(i>=4) ans = min(ans,change+isend+dp[i-4]);
                    change+=pref[i]+!g[i][l]+!g[i][r];
                    dp[i] = isend-change;
                    if(i) dp[i] = min(dp[i-1],dp[i]);
                }
            }
            for(int i=0;i<n;++i) pref[i]+=g[i][r];
        }
    }
    cout << ans << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) solve();

}