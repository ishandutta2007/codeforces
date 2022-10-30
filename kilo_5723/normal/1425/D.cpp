#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=1e3+5,maxm=2e3+5;
int a[maxn][maxn],x[maxm],y[maxm],w[maxm];
ll fact[maxm],_fact[maxm];
void adjust(int &n){
    if (n<0) n=0;
    if (n>=maxn) n=maxn-1;
}
int query(int x1,int x2,int y1,int y2){
    adjust(x1); adjust(x2); adjust(y1); adjust(y2);
    if (x1>=x2||y1>=y2) return 0;
    return a[x2][y2]-a[x2][y1]-a[x1][y2]+a[x1][y1];
}
ll qpow(ll a,ll b){
    ll ans=1;
    while (b){
        if (b&1) ans=ans*a%mod;
        a=a*a%mod; b>>=1;
    }
    return ans;
}
ll inv(ll n){ return qpow(n,mod-2); }
ll C(int n,int m){
    if (n<m) return 0;
    return fact[n]*_fact[m]%mod*_fact[n-m]%mod;
}
int main(){
    int n,m,r;
    ll ans=0;
    fact[0]=1;
    for (int i=1;i<maxm;i++) fact[i]=fact[i-1]*i%mod;
    _fact[maxm-1]=inv(fact[maxm-1]);
    for (int i=maxm-1;i;i--) _fact[i-1]=_fact[i]*i%mod;
    scanf("%d%d%d",&n,&m,&r);
    for (int i=0;i<n;i++){
        scanf("%d%d%d",&x[i],&y[i],&w[i]);
        a[x[i]][y[i]]++;
    }
    for (int i=0;i<maxn;i++) for (int j=1;j<maxn;j++)
        a[i][j]+=a[i][j-1];
    for (int i=1;i<maxn;i++) for (int j=0;j<maxn;j++)
        a[i][j]+=a[i-1][j];
    for (int i=0;i<n;i++) for (int j=0;j<n;j++){
        int a=query(x[i]-r-1,x[i]+r,y[i]-r-1,y[i]+r);
        int b=query(x[j]-r-1,x[j]+r,y[j]-r-1,y[j]+r);
        int x1=max(x[i]-r-1,x[j]-r-1),x2=min(x[i]+r,x[j]+r);
        int y1=max(y[i]-r-1,y[j]-r-1),y2=min(y[i]+r,y[j]+r);
        int t=query(x1,x2,y1,y2);
        ans=(ans+(C(n,m)-C(n-a,m)-C(n-b,m)+C(n-a-b+t,m))%mod*w[i]%mod*w[j]%mod)%mod;
    }
    printf("%lld\n",(ans+mod)%mod);
    return 0;
}