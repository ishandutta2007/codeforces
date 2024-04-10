#include<bits/stdc++.h>
using namespace std;
#define mid (l+r>>1)
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
ll mod=1e9+7;
const int mn=3e5+10;
ll fact[mn];
int main(){
    int n;
    scanf("%d%lld",&n,&mod);
    fact[0]=1;
    for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i%mod;
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=1LL*(n+1-i)*(n+1-i)%mod*fact[i]%mod*fact[n-i]%mod;;
        ans%=mod;
    }
    cout<<ans;
}