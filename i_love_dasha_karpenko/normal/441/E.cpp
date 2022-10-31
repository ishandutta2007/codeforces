//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 307;
const ld MAXP = 100;
const ld eps = 0.00000000001;
ld dp[2][N][N];
void solve(){
    ll x,k;
    cin>>x>>k;
    ld p;
    cin>>p;
    for(int bit = 0;bit<32;++bit){
        ll need = x&((1<<(bit+1))-1);
        need = ((1<<(bit+1))-x)&((1<<(bit+1))-1);
        if (need>k)
            break;
        dp[0][bit+1][need] = 1;
    }
    for(int step = 1;step<=k;++step){
        dp[0][0][0] = 1;
       // cout<<dp[0][1][0]<<' '<<dp[0][1][1]<<endl;
        if (step==200){
            int h;
            ++h;
        }
        for(int power = 0;power<=250;++power){
            for(int need = 0;need<=k;++need){
                if (dp[0][power][need]<eps)
                    continue;
                if (need>0)
                    dp[1][power][need-1] += dp[0][power][need]*((MAXP-p)/MAXP);
                else if (power<32){
                    ll nd = (1 << power) - 1;
                    if (nd<=k-step)
                        dp[1][power][nd] += dp[0][power][need]*((MAXP-p)/MAXP);
                }
                if (need*2<=k-step) {
                    dp[1][power + 1][need * 2] += dp[0][power][need] * (p / MAXP);
                }
            }
        }
        swap(dp[0],dp[1]);
        memset(dp[1],0,sizeof(dp[1]));
    }
    ld res = 0;
    for(int power = 1;power<=250;++power){
        res+=dp[0][power][0];
    }
    cout<<fixed<<setprecision(10)<<res<<endl;
}

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}