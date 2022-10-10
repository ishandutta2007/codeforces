#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1200010,mod=998244353,P=3;
int i,j,k,n,m,R[maxn];
ll a[maxn],b[maxn],tmp[maxn];
ll ksm(ll sum,int num){
    ll ans=1;
    while(num){
        if(num&1)ans=ans*sum%mod;
        sum=sum*sum%mod;
        num>>=1;
    }return ans;
}
const int P2=ksm(P,mod-2);
void FFT(int len,ll *A,bool op){
    for(int i=0;i<len;i++)tmp[R[i]]=A[i];
    for(int i=0;i<len;i++)A[i]=tmp[i];
    ll w=0,Wn=0;
    for(int i=1;i<len;i<<=1){
        Wn=ksm(op?P:P2,(mod-1)/(i*2));
        for(int j=0;j<len;j+=i*2){
            w=1;
            for(int k=0;k<i;k++,w=w*Wn%mod){
                int K=j+k;
                ll S1=A[K],S2=A[K+i]*w%mod;
                A[K]=(S1+S2)%mod; 
                A[K+i]=(S1-S2+mod)%mod;
            }
        }
    }
}
ll jc[maxn],ny[maxn],sjc[maxn];
ll C(int x,int y){
    if(y>x || y<0)return 0;
    return jc[x]*ny[y]%mod*ny[x-y]%mod;
}
ll Ans[maxn],Pow[maxn];
void FFT(ll *a,ll *b){
    int len=1,L=0;
    while(len<=(n+m))len<<=1,L++;
    for(i=0;i<len;i++)R[i]=(R[i/2]/2)+(i&1)*(1<<L-1);
    FFT(len,a,1);FFT(len,b,1);
    for(i=0;i<len;i++)a[i]=a[i]*b[i]%mod;
    FFT(len,a,0);
    ll Sum=ksm(len,mod-2);
    for(i=0;i<len;i++)a[i]=a[i]*Sum%mod;
}
int main(){
    jc[0]=1;for(i=1;i<maxn;i++)jc[i]=jc[i-1]*i%mod;
    ny[maxn-1]=ksm(jc[maxn-1],mod-2);for(i=maxn-2;i>=0;i--)ny[i]=ny[i+1]*(i+1)%mod;
    Pow[0]=1;for(i=1;i<maxn;i++)Pow[i]=Pow[i-1]*2%mod;
    sjc[1]=1;for(i=3;i<maxn;i+=2)sjc[i]=sjc[i-2]*i%mod;
    n=m=300000;
    for(i=0;i<=n;i++)a[i]=ny[i];
    for(i=0;i<=n;i++)b[i]=ny[i]*(!i?1:sjc[i-1]);
    FFT(a,b);
    for(i=0;i<=n;i++)Ans[i]=a[i]*jc[i]%mod;
    for(i=0;i<=n+n;i++)a[i]=b[i]=0;
    int T;cin>>T;
    while(T--){
        scanf("%d",&n);
        ll S=0;
        for(i=0;i<=n/4;i++)S+=C(n-i-i,i+i)*Pow[i]%mod*(i==0?1:sjc[i+i-1])%mod*Ans[n-i-i-i-i]%mod;
        printf("%lld\n",S%mod);
    }
}