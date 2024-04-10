//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int K = 5000+7;
const ll MOD = 1E9+7;
ll dp[K][K],n;
ll binpow(ll x,int power){
    ll mult = x%MOD;
    x = 1;
    while(power){
        if (power&1)
            x = x*mult%MOD;
        power = power>>1;
        mult = mult*mult%MOD;
    }
    return x;
}
ll F(int k,int a){
    if (dp[k][a]!=-1)
        return dp[k][a];
    if (k==0){
        return binpow(2,n-a);
    }
    dp[k][a] = 0;
    if (a!=0)
        dp[k][a] += F(k-1,a)*a%MOD;
    if (n-a!=0)
        dp[k][a]+=F(k-1,a+1)*(n-a)%MOD;
    dp[k][a]%=MOD;
    return dp[k][a];
}
void solve(){
    memset(dp,-1,sizeof(dp));
    int k;
    cin>>n>>k;
    cout<<F(k,0)<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}