#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()

const int MOD =998244353 ;
const int N = 507;
int dp[N][N];
ll binpow(ll x,int power){
    ll mult = x%MOD;
    x = 1;
    while(power){
        if (power&1)
            x = x*mult%MOD;
        mult = mult*mult%MOD;
        power = power>>1;
    }
    return x;
}
ll fact[N],rev[N];
int C(int n,int k){
    return fact[n]*rev[k]%MOD*rev[n-k]%MOD;
}
void solve(){
    int n,x;
    cin>>n>>x;
    dp[0][n] = 1;
    int res = 0;
    for(int dmg = 0;dmg<=x;++dmg){
        for(int left = n;left>1;--left){
            if (!dp[dmg][left])
                continue;
            for(int left1 = left;left1>=0;--left1){
                if (left1==1)
                    continue;
                int delta = left-left1;
                int ndmg = dmg+left-1;
                if (ndmg>x){
                    if (left1>0)
                        continue;
                    ndmg = x;
                }

                dp[ndmg][left1] += (binpow(ndmg-dmg,delta)*C(left,delta)%MOD*dp[dmg][left])%MOD;
                dp[ndmg][left1]%=MOD;

            }
        }
        res = (res+dp[dmg][0])%MOD;
    }
    cout<<res<<endl;
}
void calc_fact(){
    fact[0] = 1;
    for(int i = 1;i<N;++i)
        fact[i] = fact[i-1]*i%MOD;
    rev[N-1] = binpow(fact[N-1],MOD-2);
    for(int i = N-2;i>=0;--i)
        rev[i] = rev[i+1]*(i+1)%MOD;

}
signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    calc_fact();
    while(t--)
        solve();
}