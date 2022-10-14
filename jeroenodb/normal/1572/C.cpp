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
const int mxN = 3e3+2, oo = 1e9;
int dp[mxN][mxN];
void solve() {
    int n; cin >> n;
    vi a(n); for(auto& i : a) cin >> i;
    vi last(n+1,-1);
    vi jmp(n+1);
    for(int i=0;i<=n+1;++i) {
        fill_n(dp[i],n+2,0);
    }
    for(int i=0;i<n;++i) {
        
        jmp[i+1] = last[a[i]];
        last[a[i]]=i+1;
    }
    for(int r=1;r<=n;++r) {
        for(int l=r-1;l>=1;--l) {
            dp[l][r] = max(dp[l+1][r],dp[l][r-1]);
            int at = jmp[r];
            while(at>=l) {
                dp[l][r] = max(dp[l][r],1+dp[l][at]+dp[at+1][r-1]);
                at = jmp[at];
            }
        }
    }
    cout << n-1-dp[1][n] << '\n';

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}