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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,l; cin >> n >> k >> l;
    vector<bool> a(n);
    {
        string tmp; cin >> tmp;
        for(int i=0;i<n;++i) {
            a[i]=isupper(tmp[i]);
        }
    }
    int ans= 2e9;
    for(int rep=0;rep<2;++rep) {
        // make all zero
        auto doDP = [&](int lamb) {
            vi dp(n+1,oo), cnt(n+1,0);
            dp[0]=0;
            for(int i=0;i<n;++i) {
                dp[i+1]=dp[i]+a[i];
                cnt[i+1]=cnt[i];
                int f = max(0,i+1-l);
                if(dp[f]+lamb<dp[i+1]) {
                    dp[i+1] = dp[f]+lamb;
                    cnt[i+1] = cnt[f]+1;
                }
            }
            return pi{dp[n],cnt[n]};
        };

        int lo = 0,hi  = n+10;
        while(lo<hi) {
            auto mid = (lo+hi)/2;
            auto [res,cnt] = doDP(mid);
            if(cnt>k) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        auto [res,cnt] = doDP(lo);
        ans = min(ans,res-lo*k);
        for(int i=0;i<n;++i) a[i]=!a[i];
    }
    cout << ans << '\n';
}