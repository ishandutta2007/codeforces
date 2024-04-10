#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
//#define int ll
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'a')
const int N = 23;
const int AL = 26;
const ll MOD = 998244353;
const int MXL = 2e4+7;
int cnt[N][AL],lim[AL];
int dp[1<<N][2];
void solve() {
    int n;
    cin>>n;
    for(int i = 0;i<n;++i){
        string s;
        cin>>s;
        for(char to:s)
            cnt[i][gi(to)]++;
    }
    int masksz = 1<<n;
    ll res = 0;
    for(int mask = 1;mask<masksz;++mask){
        int sz = __builtin_popcount(mask);
        int mult = sz&1?1:-1;
        for(int i = 0;i<AL;++i)
            lim[i] = MXL;
        ll ind_sum = 0;
        for(int bit = 0;bit<n;++bit){
            if (mask&(1<<bit)) {
                ind_sum+=(bit+1);
                for (int i = 0; i < AL; ++i)
                    lim[i] = min(lim[i], cnt[bit][i]);
            }
        }
        ll r = 1;
        for(int i = 0;i<AL;++i)
            r = r*(lim[i]+1)%MOD;

        dp[mask][0] = r*mult;
        dp[mask][0] += MOD*(dp[mask][0]<0);

    }

    for(int bit = 1;bit<=n;++bit){
        for(int mask = 1;mask<masksz;++mask){
            dp[mask][1] = dp[mask][0] + dp[mask^(1<<(bit-1))][0]*((mask&(1<<(bit-1)))!=0);
            dp[mask][1] -= MOD*(dp[mask][1]>=MOD);
        }
        for(int mask = 1;mask<masksz;++mask){
            dp[mask][0] = dp[mask][1];
        }
    }
    for(int mask = 1;mask<masksz;++mask){
        int sz = __builtin_popcount(mask);
        ll ind_sum = 0;
        for(int bit = 0;bit<n;++bit){
            if (mask&(1<<bit)) {
                ind_sum+=(bit+1);
            }
        }
        res^=ind_sum*dp[mask][0]*sz;
    }
    cout<<res<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //+cin>>t;

    while(t--)
        solve();
}