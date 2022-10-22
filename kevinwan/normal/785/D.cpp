#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int mn=2e5+10;
ll fact[mn];
int l[mn],r[mn];
ll inv(ll x){
    ll ans=1;
    for(ll i=mod-2;i;i>>=1,x=x*x%mod)if(i&1)ans=ans*x%mod;
    return ans;
}
ll ch(ll a,ll b){
    if(a<0||b<0||b>a)return 0;
    return fact[a]*inv(fact[a-b])%mod*inv(fact[b])%mod;
}
int main()
{
    string s;
    cin>>s;
    int n=s.size(),i;
    fact[0]=1;
    for(i=1;i<=n;i++)fact[i]=fact[i-1]*i%mod;
    l[0]=(s[0]=='(');
    r[n-1]=(s[n-1]==')');
    for(i=1;i<n;i++)l[i]=l[i-1]+(s[i]=='(');
    for(i=n-2;i>=0;i--)r[i]=r[i+1]+(s[i]==')');
    ll ans=0;
    for(i=0;i<n-1;i++)if(s[i]=='(')ans+=ch(l[i]+r[i+1],l[i])-ch(l[i]+r[i+1]-1,l[i]-1);
    ans%=mod;
    if(ans<0)ans+=mod;
    printf("%lld",ans);
}