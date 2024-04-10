#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int mn=3e5+10;
ll fact[mn];
ll po(ll x,ll i=mod-2){
    ll ans=1;
    for(;i;i>>=1,x=x*x%mod)if(i&1)ans=ans*x%mod;
    return ans;
}
ll ch(ll a,ll b){
    if(b<0||b>a)return 0;
    return fact[a]*po(fact[b]*fact[a-b]%mod)%mod;
}
int main(){
    int n,k,i;
    scanf("%d%d",&n,&k);
    fact[0]=1;
    for(i=1;i<=n;i++)fact[i]=fact[i-1]*i%mod;
    string s;
    cin>>s;
    ll tot=0,ans=0;
    reverse(s.begin(),s.end());
    for(i=1;i<n;i++){
        tot+=po(10,i-1)*ch(n-i-1,k-1);
        tot%=mod;
        ans+=tot*(s[i]-'0');
        ans%=mod;
    }
    for(i=0;i<n;i++){
        ans+=po(10,i)*ch(n-i-1,k)%mod*(s[i]-'0');
        ans%=mod;
    }
    printf("%lld",ans);
}