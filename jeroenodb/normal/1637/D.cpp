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
const ll oo = 1e18;
void cmin(ll& a, ll b) {a=min(a,b);}
const int M = 101*101;
void solve() {
    int n; cin >> n;
    vi a(n),b(n);
    ll ans=0;
    for(auto& i : a) cin >> i,ans+=(n-1)*i*i;
    for(auto& i : b) cin >> i,ans+=(n-1)*i*i;
    vector<ll> dp(M,oo);
    dp[0]=0;
    ll sm=0;
    for(int i=0;i<n;++i) {
        for(int j=M-1;j>=0;--j) {
            if(dp[j]==oo) continue;
            cmin(dp[j+a[i]], dp[j] + (j*a[i]+ (sm-j)*b[i]));
            cmin(dp[j+b[i]], dp[j] + (j*b[i]+ (sm-j)*a[i]));
            dp[j] = oo;
        }
        sm+=a[i]+b[i];
    }
    cout << ans + *min_element(all(dp))*2 << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}