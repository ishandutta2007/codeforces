//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 fdgfdgf
#define y1 fdhfdgfdg
#define endl '\n'
const ll DIM = 1000+7;
const ll MOD = 1E9+7;
ll dp[2][DIM][DIM],pref[2][DIM][DIM];
int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;

        for(ll cur = 1;cur<=k;++cur){
            for(ll i = 1;i<=n;++i){
                dp[0][cur][i] = pref[1][cur-1][n]-pref[1][cur-1][i]+1;
                dp[1][cur][i] = pref[0][cur-1][i-1]+1;
                dp[0][cur][i]%=MOD;
                dp[1][cur][i]%=MOD;
            }
            for(ll i = 1;i<=n;++i){
                pref[0][cur][i] = (pref[0][cur][i-1]+dp[0][cur][i])%MOD;
                pref[1][cur][i] = (pref[1][cur][i-1]+dp[1][cur][i])%MOD;
            }
        }
        if (k==1){
            cout<<"1\n";
        }
        else{
            cout<<((1ll+dp[0][k][1])%MOD+MOD)%MOD<<endl;
        }
    }
    return 0;
}