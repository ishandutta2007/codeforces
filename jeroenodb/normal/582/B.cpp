#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
// template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
int main() {
    int n,t; cin >> n >> t;
    vi a(n);
    for(auto& i : a) cin >> i;
    vi cnt(301);
    for(int i=0;i<n;++i) {
        cnt[a[i]]++;
    }
    // prefix same suffix
    vi dp(301);
    int times = min(300,t/2);
    for(int rep=0;rep<times;++rep) {
        for(int i=0;i<n;++i) {
            int nw=1;
            for(int j=0;j<=a[i];++j) {
                nw = max(nw,dp[j]+1);
            }
            dp[a[i]]= max(dp[a[i]],nw);
        }
    }
    vi dp2(301);
    int times2 = min(300,(t+1)/2);
    for(int rep=0;rep<times2;++rep) {
        for(int i=n-1;i>=0;--i) {
            int nw=1;
                for(int j=a[i];j<=300;++j) {
                nw = max(nw,dp2[j]+1);
            }
            dp2[a[i]]= max(dp2[a[i]],nw);
        }
    }
    int ans=0;
    for(int i=299;i>=0;--i) dp2[i] = max(dp2[i],dp2[i+1]);
    for(int i=0;i<=300;++i) {
        if(i) dp[i] = max(dp[i],dp[i-1]);
        ans = max(ans, dp[i]+cnt[i]*(t-times-times2) + dp2[i]);
    }
    cout << ans << '\n';


}