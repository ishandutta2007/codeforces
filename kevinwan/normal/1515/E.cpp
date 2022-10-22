#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
const int mn=2e5+10;

ll dp[410][410];
ll n,mod;
ll fact[mn],ifact[mn];
ll p2[mn];
ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>mod;
    fact[0]=ifact[0]=p2[0]=1;
    for(int i=1;i<=n+1;i++)fact[i]=fact[i-1]*i%mod,ifact[i]=po(fact[i]),p2[i]=p2[i-1]*2,p2[i]%=mod;
    dp[0][0]=1;
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=i;j++){
            for(int k=0;k<i-1;k++){
                dp[i][j]+=dp[k][j-1]*p2[i-k-2]%mod*ifact[i-k-1];
                dp[i][j]%=mod;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n+1;i++)ans+=dp[n+1][i]*fact[n+1-i],ans%=mod;
    if(ans<0)ans+=mod;
    printf("%lld\n",ans);
}