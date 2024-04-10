#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<complex>
using namespace std;
typedef complex<double> comp;
typedef long long ll;
const int B=32768;
int n,tr[550005],mod,f[550005],g[550005],miu[550005],prime[550005],vst[550005];
comp wk[550005],a0[550005],a1[550005],b0[550005],b1[550005],p[550005],q[550005];
int Power(int x,int y,int mod) {
    int ret=1;
    while(y) {
        if(y&1)ret=1ll*ret*x%mod;
        x=1ll*x*x%mod,y>>=1;
    }
    return ret;
}
void GetTr(int l) {
    for(int i=0; i<l; i++)tr[i]=(tr[i>>1]>>1)|((i&1)?(l>>1):0);
}
void FFT(comp a[],int n,int flag){
    for(int i=0;i<n;i++)if(tr[i]<i)swap(a[i],a[tr[i]]);
    for(int i=1;i<n;i<<=1){
        for(int j=0;j<n;j+=(i<<1)){
            for(int k=0;k<i;k++){
                comp t;
                if(flag==1)t=a[i+j+k]*wk[262144/i*k];
                else t=a[i+j+k]/wk[262144/i*k];
                a[i+j+k]=a[j+k]-t,a[j+k]+=t;
            }
        }
    }
    if(flag==-1)for(int i=0;i<n;i++)a[i]/=n;
}
const comp I=comp(0,1);
void Mul(int a[],int b[],int l){
    for(int i=0;i<l;i++)a0[i]=comp(a[i]/B,a[i]%B),b0[i]=comp(b[i]/B,b[i]%B);
    FFT(a0,l,1);
    for(int i=0;i<l;i++)a1[i]=conj(a0[i?l-i:0]);
    for(int i=0;i<l;i++){
        comp p=a0[i],q=a1[i];
        a0[i]=(p+q)/2.0,a1[i]=I*(q-p)/2.0;
    }
    FFT(b0,l,1);
    for(int i=0;i<l;i++)b1[i]=conj(b0[i?l-i:0]);
    for(int i=0;i<l;i++){
        comp p=b0[i],q=b1[i];
        b0[i]=(p+q)/2.0,b1[i]=I*(q-p)/2.0;
    }
    for(int i=0;i<l;i++)p[i]=a0[i]*b0[i]+I*a1[i]*b0[i],q[i]=a0[i]*b1[i]+I*a1[i]*b1[i];
    FFT(p,l,-1),FFT(q,l,-1);
    for(int i=0;i<l;i++){
        ll a1b1=(ll)(p[i].real()+0.5),a3b3=(ll)(p[i].imag()+q[i].real()+0.5),a2b2=(ll)(q[i].imag()+0.5);
        a[i]=(a1b1%mod*B%mod*B+a3b3%mod*B+a2b2)%mod;
    }
}
void Calcinv(int a[],int b[],int l){
    if(l==1){
        b[0]=Power(a[0],mod-2,mod);
        return ;
    }
    Calcinv(a,b,(l+1)/2);
    int len=1;
    while(len<l*2)len<<=1;
    GetTr(len);
    static int tmp[550005]={0};
    memcpy(tmp,a,sizeof(int)*l);
    for(int i=l;i<len;i++)tmp[i]=0;
    Mul(tmp,b,len);
    Mul(tmp,b,len);
    for(int i=0;i<l;i++)b[i]=(2ll*b[i]-tmp[i]+mod)%mod;
}
void Calcln(int a[],int b[],int l){
    static int tmp[550005]={0};
    memcpy(tmp,a,sizeof(int)*l);
    for(int i=1;i<l;i++)tmp[i-1]=1ll*tmp[i]*i%mod;
    tmp[l-1]=0;
    Calcinv(a,b,l);
    int len=1;
    while(len<l*2)len<<=1;
    GetTr(len);
    for(int i=l;i<len;i++)tmp[i]=0;
    Mul(b,tmp,len);
    for(int i=l;i<len;i++)b[i]=0;
    for(int i=l-1;i>0;i--)b[i]=1ll*b[i-1]*Power(i,mod-2,mod)%mod;
    b[0]=0;
}
void Calcexp(int a[],int b[],int l){
    if(l==1){
        b[0]=1;
        return ;
    }
    static int tmp[400005]={0},ln[400005]={0};
    Calcexp(a,b,(l+1)/2);
    Calcln(b,ln,l);
    memcpy(tmp,a,sizeof(int)*l);
    int len=1;
    while(len<=l*1.5)len<<=1;
    GetTr(len);
    tmp[0]=(1-ln[0]+tmp[0]+mod)%mod;
    for(int i=1;i<len;i++)tmp[i]=(tmp[i]-ln[i]+mod)%mod;
    Mul(b,tmp,len);
    fill(b+l,b+len,0);
    fill(tmp,tmp+len,0);
    fill(ln,ln+len,0);
}
const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
long long N,K;
int _mul[200001],invmul[200001];
int main() {
	scanf("%lld%lld",&N,&K);
	if(N>K){
		puts("0");
		return 0;
	}
	_mul[0]=_mul[1]=invmul[0]=invmul[1]=1;
	for(int i=2;i<=K+1;i++)_mul[i]=mul(_mul[i-1],i);
	for(int i=2;i<=K+1;i++)invmul[i]=mul(P-P/i,invmul[P%i]);
	for(int i=2;i<=K+1;i++)invmul[i]=mul(invmul[i-1],invmul[i]);
    double pi=acos(-1);
    for(int i=1;i<262144;i++)wk[i]=exp(comp(0,pi/262144*i));
    wk[0]=1,mod=1000000007;
    for(int i=0;i<=K-N;i++)g[i]=invmul[i+1];
    Calcln(g,f,K-N+1);
    for(int i=1;i<=K-N;i++)f[i]=mul(f[i],mul(sub(qsm(2,N*i),1),qsm(sub(qsm(2,i),1),P-2)));
    memset(g,0,sizeof g);
    Calcexp(f,g,K-N+1);
    int ans=0;
    for(int i=N;i<=K;i++)ans=add(ans,mul(g[i-N],invmul[K-i]));
    printf("%d\n",mul(ans,mul(_mul[K],qsm(2,(1ll*N*(N-1))>>1ll))));
}