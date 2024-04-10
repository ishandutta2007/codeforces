#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=3e5+10;
const int inf=0x3f3f3f3f;
ll v[mn];
int f[mn];
bool p[mn];
ll po(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a*=a)if(b&1)ans*=a;
    return ans;
}
int main(){
    int tc;
    scanf("%d",&tc);
    fill(f,f+mn,1);
    fill(p,p+mn,1);
    for(int i=2;i<=60;i++)if(p[i]){
        for(int j=i*i;j<=60;j+=i)p[j]=0;
        for(int j=i;j<=60;j+=i){
            if(j%(i*i)==0)f[j]=0;
            else f[j]*=-1;
        }
    }
    while(tc--){
        ll x;
        scanf("%lld",&x);
        v[1]=x-1;
        for(ll i=2;i<=60;i++){
            ll a=pow((ld)x,((ld)1)/i)*(1+1e-15);
            ll b=po(a,i);
            if(b>x)a--;
            v[i]=a-1;
        }
        ll ans=0;
        for(ll i=1;i<=60;i++)ans+=v[i]*f[i];
        printf("%lld\n",ans);
    }
}