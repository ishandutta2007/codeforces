#include<bits/stdc++.h>
using namespace std;
const int md=998244353,N=600000,g3=(md+1)/3;
typedef long long LL;
int n,k,a[N],A[N],G[N],sb[N];
inline void upd(int&a){a+=a>>31&md;}
inline int pow(int a,int b){
	int r=1;
	for(;b;b>>=1,a=(LL)a*a%md)if(b&1)r=(LL)r*a%md;return r;
}
namespace poly{
	int lim,rev[N],inv[N];
	inline int poly_start(){
		inv[1]=1;
		for(int i=2;i<N;++i)inv[i]=(md-md/i)*(LL)inv[md%i]%md;
		return 1;
	}
	int __START__=poly_start();
	inline void init(int n){
		int l=-1;
		for(lim=1;lim<n;lim<<=1)++l;
		for(int i=1;i<lim;++i)rev[i]=(rev[i>>1]>>1)|((i&1)<<l);
	}
	void NTT(int*a,int f){
		for(int i=1;i<lim;++i)if(i<rev[i])std::swap(a[i],a[rev[i]]);
		for(int i=1;i<lim;i<<=1){
			const int gi=pow(f?3:g3,(md-1)/(i<<1));
			for(int j=0;j<lim;j+=i<<1)
			for(int k=0,g=1;k<i;++k,g=(LL)g*gi%md){
				const int x=a[j+k],y=a[j+k+i]*(LL)g%md;
				upd(a[j+k]+=y-md),upd(a[j+k+i]=x-y);
			}
		}
		if(!f){
			const LL iv=inv[lim];
			for(int i=0;i<lim;++i)a[i]=a[i]*iv%md;
		}
	}
}
LL jc[1005000],inv[1005000];
LL c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%md*inv[n-m]%md;}
int main(){
	int i,j,cur=1,l,r,len;
	jc[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%md;}
	inv[1000000]=490058372;
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%md;}
	scanf("%d",&n);
	a[0]=1;
	for(i=1;i<=n;i++){
		scanf("%d%d",&l,&r);
		memset(sb,0,sizeof(sb));
		len=cur+l-max(0,r-cur+1);
		for(j=0;j<len;j++)sb[len-1-j]=c(l+r,cur+l-1-j);
		poly::init((len+cur)<<1);
		poly::NTT(a,1);poly::NTT(sb,1);
		for(j=0;j<poly::lim;j++)a[j]=(LL)a[j]*sb[j]%md;
		poly::NTT(a,0);
		for(j=0;j<cur+l-r;j++)a[j]=a[len+cur-2-(cur-1)-(cur+l-1)+r+j];
		for(j=cur+l-r;j<=poly::lim;j++)a[j]=0;
		cur+=l-r;
	}
	LL res=0;
	for(i=0;i<cur;i++)res+=a[i];
	cout<<res%md;
}