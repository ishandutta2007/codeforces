#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
const ll mod=1e6+3;
int s[mn];
vector<int>g[mn];
ll i2=(mod+1)/2;
ll po(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
ll hail(ll x){
    ll ans=0;
    while(x/=2)ans+=x;
    return ans;
}
int main(){
    ll n,k;
    scanf("%lld%lld",&n,&k);
    if(63-__builtin_clzll(k-1)>=n){
        printf("1 1");
        return 0;
    }
    ll nn=po(2,n);
    ll a=1;
    for(ll i=0;i<=min(mod,k-1);i++)a*=nn-i,a%=mod;
    ll b=po(nn,k);
    a=b-a;
    ll num=n+hail(k-1);
    a*=po(i2,num),a%=mod;
    b*=po(i2,num),b%=mod;
    if(a<0)a+=mod;
    printf("%lld %lld",a,b);
}