#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 2048;
const ll mod=998244353;
ll binpow(ll a,ll b){
    ll res=1;
    while (b){
        if (b%2) res=res*a%mod;
        b/=2;
        a=a*a%mod;
    }
    return res;
}
ll dp[N][N];
ll inv[N];
void solve(){
    ll n,m,k;cin>>n>>m>>k;
    ll C=1;
    ll res=0ll;
    ll invm=binpow(m,mod-2);
    ll mult=1;
    for (int cnt=1;cnt<=min(n,k);cnt++){
        mult*=(m+1)/2;
        mult%=mod;
        mult*=invm;
        mult%=mod;
        C*=(n-cnt+1);
        C%=mod;
        C*=inv[cnt];
        C%=mod;
        res+=C*dp[k][cnt]%mod*mult%mod;
        res%=mod;
    }
    res*=binpow(m,n);
    res%=mod;
    cout<<res<<'\n';

}
int main()
{
    for (int i=0;i<N;i++) inv[i]=binpow(i,mod-2);

    dp[0][0]=1;
    for (int i=1;i<N;i++){
        for (int j=1;j<=i;j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])*j%mod;
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}