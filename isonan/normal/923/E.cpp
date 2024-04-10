#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using std::swap;
typedef std::vector<int> poly;

int n,w[1000001],lim,t1[1000001],t2[1000001],fac[1000001],invfac[1000001],R[1000001];
long long m;
poly f,g,tem;
const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
void NTT(int *a){
	for(int i=0;i<lim;i++)if(i<R[i])swap(a[i],a[R[i]]);
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;k++){
				const int Ny=mul(a[i+j+k],w[i+k]);
				a[i+j+k]=(a[j+k]+P-Ny)%P;
				a[j+k]=(a[j+k]+Ny)%P;
			}
}
poly mul(poly A,poly B){
	int size=A.size()+B.size()-1;
	lim=1;
	while(lim<=size)lim<<=1;
	for(int i=0;i<lim;i++)R[i]=(R[i>>1]>>1)|((i&1)?(lim>>1):0);
	memset(t1,0,(lim+1)<<2);
	memset(t2,0,(lim+1)<<2);
	for(int i=A.size()-1;~i;--i)t1[i]=A[i];
	for(int i=B.size()-1;~i;--i)t2[i]=B[i];
	NTT(t1);
	NTT(t2);
	for(int i=0;i<lim;i++)t1[i]=mul(t1[i],t2[i]);
	std::reverse(t1+1,t1+lim);
	NTT(t1);
	A.resize(size);
	int inv=qsm(lim,P-2);
	for(int i=0;i<size;i++)A[i]=mul(t1[i],inv);
	return A;
}
int main(){
	scanf("%d%I64d",&n,&m);
	for(int i=1,wn;i<((n+1)<<2);i<<=1){
		w[i]=1;wn=qsm(3,(P-1)/(i<<1));
		for(int j=1;j<i;j++)w[i+j]=mul(w[i+j-1],wn);
	}
	f.resize(n+1),tem.resize(n+1),g.resize(n+1);
	fac[0]=fac[1]=1,invfac[0]=invfac[1]=1;
	for(int i=2;i<=n;i++)fac[i]=mul(fac[i-1],i);
	for(int i=2;i<=n;i++)invfac[i]=mul(P-P/i,invfac[P%i]);
	for(int i=2;i<=n;i++)invfac[i]=mul(invfac[i-1],invfac[i]);
	for(int i=0;i<=n;i++)scanf("%d",&f[i]),f[i]=mul(f[i],fac[i]);
	for(int i=0;i<=n;i++)tem[i]=invfac[n-i];
	f=mul(f,tem);
	for(int i=0;i<=n;i++)g[i]=mul(f[i+n],qsm(qsm(i+1,P-2),m%(P-1)));
	for(int i=n-1;i>=0;i-=2)tem[i]=P-tem[i];
	g=mul(g,tem);
	for(int i=0;i<=n;i++)printf("%d ",mul(g[i+n],invfac[i]));
}