//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 400+7;
ll MOD;
ll dp[3][DIM][DIM];
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n>>MOD;
    dp[0][1][1] = 1;
    dp[1][2][1] = dp[1][2][2] = 1;
    for(ll i = 3;i<=n;++i){
        for(ll cnt = 1;cnt<=n;++cnt){
            ll sum = 0,s1 = 0;
            for(ll ord = cnt;ord>=1;--ord){
                sum = (sum+dp[0][cnt-1][ord]*(cnt-ord))%MOD;
                s1 = (s1+dp[0][cnt-1][ord]);
                dp[2][cnt+1][ord] = (dp[2][cnt+1][ord]-sum)%MOD;
                dp[2][cnt][ord] = (dp[2][cnt][ord]+s1)%MOD;
            }
            sum = 0;
            for(ll ord = 1;ord<=cnt;++ord){
                dp[2][cnt+1][ord] = (dp[2][cnt+1][ord]-sum*(cnt-ord+1))%MOD;
                dp[2][cnt][ord] = (dp[2][cnt][ord]+sum)%MOD;
                sum = (sum+dp[0][cnt-1][ord])%MOD;
            }
        }
        for(ll cnt = 1;cnt<=n;++cnt){
            ll sum = 0;
            for(ll ord = 1;ord<cnt;++ord){
                sum+=dp[1][cnt-1][ord];
            }
            for(ll ord = 1;ord<=cnt;++ord){
                dp[2][cnt][ord] = (dp[2][cnt][ord]+sum)%MOD;
                dp[2][cnt][ord] = (dp[2][cnt][ord]+MOD)%MOD;
            }
        }
        swap(dp[0],dp[1]);
        swap(dp[1],dp[2]);
        memset(dp[2],0,sizeof(dp[2]));
    }
    ll res = 0;
    for(ll cnt = 1;cnt<=n;++cnt){
        for(ll ord = 1;ord<=cnt;++ord)
            res = (res+dp[1][cnt][ord])%MOD;
    }
    cout<<res<<endl;
    return 0;
}