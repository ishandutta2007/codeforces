#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=3e5+10;
const ll mod=1e9+7;
int f[mn];
bool p[mn];
ll fact[mn],ifact[mn];
ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
ll ch(ll a,ll b){
    if(b<0||b>a)return 0;
    return fact[a]*ifact[b]%mod*ifact[a-b]%mod;
}
int main(){
    int q;
    scanf("%d",&q);
    fill(f,f+mn,1);
    fact[0]=ifact[0]=1;
    for(int i=1;i<mn;i++)ifact[i]=po(fact[i]=fact[i-1]*i%mod);
    memset(p,1,sizeof(p));
    for(int i=2;i*i<mn;i++)if(p[i])for(int j=i*i;j<mn;j+=i)p[j]=0;
    for(int i=2;i<mn;i++)if(p[i]){
        for(int j=i;j<mn;j+=i){
            f[j]*=-1;
            if(j/i%i==0)f[j]=0;
        }
    }
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        vector<int>fact;
        ll ans=0;
        for(int i=1;i*i<=a;i++)if(a%i==0){
            fact.push_back(i);
            if(i*i!=a)fact.push_back(a/i);
        }
        for(int x:fact){
            ans+=f[x]*ch(a/x-1,b-1);
            ans%=mod;
        }
        if(ans<0)ans+=mod;
        printf("%lld\n",ans);
    }
}