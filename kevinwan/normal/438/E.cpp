#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=1<<17;
const ll mod=998244353;
vector<ll>w;
vector<int>ord;
ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
void getroots(int n){
    if(n<=w.size())return;
    if(!w.size())w={0,1};
    int len=w.size();
    w.resize(n);
    for(;len<n;len<<=1){
        ll mult=po(3,(mod-1)/(len<<1));
        w[len]=1;
        for(int i=1;i<len;i++)w[i+len]=w[i+len-1]*mult%mod;
    }
}
void reorder(int n,ll*a){
    if(ord.size()!=n){
        ord.assign(n,0);
        int len=__builtin_ctz(n);
        for(int i=1;i<n;i++)ord[i]=(ord[i>>1]>>1)|((i&1)<<(len-1));
    }
    for(int i=0;i<n;i++)if(i<ord[i])swap(a[i],a[ord[i]]);
}
void fft(int n,ll*a){
    getroots(n),reorder(n,a);
    for(int len=1;len<n;len<<=1)for(int i=0;i<n;i+=len<<1)for(int j=0;j<len;j++){
        ll u=a[i+j],v=a[i+j+len]*w[len+j]%mod;
        a[i+j]=(u+v)%mod,a[i+j+len]=(u-v)%mod;
    }
}
void ifft(int n,ll*a){
    reverse(a+1,a+n);
    ll m=po(n);
    for(int i=0;i<n;i++)a[i]*=m,a[i]%=mod;
    fft(n,a);
}
ll* inv(int n,ll*a){
    ll*r=(ll*)calloc(n,sizeof(ll));
    r[0]=1;
    for(int len=1;len<n;len<<=1){
        ll*p=(ll*)calloc(len*4,sizeof(ll));
        ll*q=(ll*)calloc(len*4,sizeof(ll));
        memcpy(p,a,sizeof(ll)*len*2);
        memcpy(q,r,sizeof(ll)*len);
        fft(len*4,p),fft(len*4,q);
        for(int i=0;i<len*4;i++)p[i]=p[i]*q[i]%mod*q[i]%mod;
        ifft(len*4,p);
        for(int i=0;i<len*2;i++)r[i]=(2*r[i]-p[i])%mod;
    }
    return r;
}
ll* sqrt(int n,ll*a){
    ll*r=(ll*)calloc(n,sizeof(ll));
    r[0]=1;
    for(int len=1;len<n;len<<=1){
        ll*p=(ll*)calloc(len*4,sizeof(ll));
        ll*q=(ll*)calloc(len*4,sizeof(ll));
        memcpy(p,a,sizeof(ll)*len*2);
        memcpy(q,r,sizeof(ll)*len);
        ll*t=inv(len*2,q);
        memcpy(q,t,sizeof(ll)*len*2);
        fft(len*4,p),fft(len*4,q);
        for(int i=0;i<len*4;i++)p[i]*=q[i],p[i]%=mod;
        ifft(len*4,p);
        for(int i=0;i<len*2;i++)r[i]=(mod+1)/2*(p[i]+r[i])%mod;
    }
    return r;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    ll*a=(ll*)calloc(mn,sizeof(ll));
    a[0]=1;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        a[x]-=4;
    }
    a=sqrt(mn,a);
    a[0]++;
    for(int i=0;i<mn;i++)a[i]*=(mod+1)/2,a[i]%=mod;
    a=inv(mn,a);
    for(int i=1;i<=m;i++)printf("%lld\n",a[i]+(a[i]<0?mod:0));
}