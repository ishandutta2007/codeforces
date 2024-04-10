#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;

long long P=998244353,n,k,tem[4000001],R[4000001];
long long qsm(long long a,long long b){
	long long ans=1;
	while(b){
		if(b&1)(ans*=a)%=P;
		(a*=a)%=P;
		b>>=1; 
	}
	return ans;
}
void NTT(long long *a,int Lim,int flag){
	for(int i=0;i<Lim;i++)if(i<R[i])swap(a[i],a[R[i]]);
	for(int i=1;i<Lim;i<<=1)
		for(int j=0,T=qsm(flag,(P-1)/(i<<1));j<Lim;j+=(i<<1))
			for(int k=0,t=1;k<i;++k,(t*=T)%=P){
				int Nx=a[j+k],Ny=a[i+j+k]*t%P;
				a[j+k]=(Nx+Ny)%P;
				a[i+j+k]=(Nx+P-Ny)%P;
			}
}
signed main(){
	scanf("%I64d%I64d",&n,&k);
	for(int i=1,t;i<=k;i++)scanf("%I64d",&t),tem[t]=1;
	int Lim=1,l=-1;
	n>>=1;
	while(Lim<=(n*10))Lim<<=1,++l;
	for(int i=0;i<Lim;i++)R[i]=(R[i>>1]>>1)|((i&1)<<l);
	NTT(tem,Lim,3);
	for(int i=0;i<Lim;i++)tem[i]=qsm(tem[i],n);
	NTT(tem,Lim,(P+1)/3);
	int inv=qsm(Lim,P-2),ans=0;
	for(int i=0;i<Lim;i++)(ans+=qsm((tem[i]*inv)%P,2))%=P;
	printf("%I64d",ans);
}