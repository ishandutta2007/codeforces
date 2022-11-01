//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N = 50+7;
const ll MOD = 1e9+7;
ll dp[2][N][N][N][N],po[N];
void solve(){
    int n,p;
    cin>>n>>p;
    dp[0][0][0][0][0] = 1;
    for(int i = 1;i<=n;++i){
        int col;
        cin>>col;
        for(int mod = 0;mod<=1;++mod){
            for(int cnt10 = 0;cnt10<i;++cnt10){
                for(int cnt11 = 0;cnt10+cnt11<i;++cnt11){
                    for(int cnt00 = 0;cnt10+cnt11+cnt00<i;++cnt00){
                        int cnt01 = i-1-cnt00-cnt11-cnt10;
                        if (!dp[mod][cnt10][cnt11][cnt00][cnt01])
                            continue;
                        if (col==0 || col==-1){
                            ll add = dp[mod][cnt10][cnt11][cnt00][cnt01]*po[cnt10]%MOD*po[cnt00]%MOD*po[cnt01]%MOD; // 10 -> 01
                            if (cnt11!=0){
                                add = add*po[cnt11-1]%MOD;
                            }
                            else {
                                dp[mod^1][cnt10][cnt11][cnt00][cnt01+1] = (dp[mod^1][cnt10][cnt11][cnt00][cnt01+1]+add)%MOD;
                                add = 0;
                            }
                            dp[mod][cnt10][cnt11][cnt00+1][cnt01] = (dp[mod][cnt10][cnt11][cnt00+1][cnt01]+add)%MOD;
                            dp[mod^1][cnt10][cnt11][cnt00][cnt01+1] = (dp[mod^1][cnt10][cnt11][cnt00][cnt01+1]+add)%MOD;

                        }
                        if (col==1 || col==-1){
                            ll add = dp[mod][cnt10][cnt11][cnt00][cnt01]*po[cnt00]%MOD*po[cnt11]%MOD*po[cnt10]%MOD; // 10 -> 01
                            if (cnt01!=0){
                                add = add*po[cnt01-1]%MOD;
                            }
                            else {
                                dp[mod^1][cnt10][cnt11+1][cnt00][cnt01] = (dp[mod^1][cnt10][cnt11+1][cnt00][cnt01]+add)%MOD;
                                add = 0;
                            }
                            dp[mod][cnt10+1][cnt11][cnt00][cnt01] = (dp[mod][cnt10+1][cnt11][cnt00][cnt01]+add)%MOD;
                            dp[mod^1][cnt10][cnt11+1][cnt00][cnt01] = (dp[mod^1][cnt10][cnt11+1][cnt00][cnt01]+add)%MOD;
                        }

                    }
                }
            }
        }

    }
    ll res = 0;
    for(int cnt10 = 0;cnt10<=n;++cnt10){
        for(int cnt11 = 0;cnt10+cnt11<=n;++cnt11){
            for(int cnt00 = 0;cnt10+cnt11+cnt00<=n;++cnt00){
                int cnt01 = n-cnt00-cnt11-cnt10;
                    res = (res+dp[p][cnt10][cnt11][cnt00][cnt01])%MOD;

            }
        }
    }
    cout<<res<<endl;

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    po[0] = 1;
    for(int i = 1;i<N;++i){
        po[i] = po[i-1]*2%MOD;
    }
    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}