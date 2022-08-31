#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <algorithm>
#define double long double

typedef std::vector<int> poly;
int P=490019;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int qsm(int a,long long b,int p=P){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int R[2000001],lim,n,m,a[2000001],b[2000001],c,Pow[490019];
int t1[2000001],t2[2000001],w[2000001];
int Ans[2][2000001];
void NTT(int *a){
	for(int i=0;i<lim;i++)if(i<R[i])std::swap(a[i],a[R[i]]);
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;k++){
				const int Ny=mul(a[i+j+k],w[i+k]);
				a[i+j+k]=sub(a[j+k],Ny);
				a[j+k]=add(a[j+k],Ny);
			}
}
void solve(int P,int g,int *Ans){
	::P=P;
	for(int i=1;(i<<1)<(2000000);i<<=1){
		long long wn=qsm(g,(P-1)/(i<<1));
		w[i]=1;
		for(int j=1;j<i;j++)w[i+j]=mul(w[i+j-1],wn);
	}
	lim=1;
	while(lim<=1000000)lim<<=1;
	for(int i=0;i<lim;i++)R[i]=(R[i>>1]>>1)|((i&1)?lim>>1:0);
	for(int i=0;i<lim;i++)t1[i]=a[i];
	for(int i=0;i<lim;i++)t2[i]=b[i];
	NTT(t1);
	NTT(t2);
	for(int i=0;i<lim;i++)t1[i]=mul(t1[i],t2[i]);
	NTT(t1);
	std::reverse(t1+1,t1+lim);
	int inv=qsm(lim,P-2);
	for(int i=0;i<lim;i++)Ans[i]=mul(t1[i],inv);
}
void exgcd(int a,int b,long long &x,long long &y){
	if(!b){
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	long long t=x;
	x=y;
	y=t-(a/b)*y;
}
int main(){
	scanf("%d%d%d",&n,&m,&c);
	for(int i=0,tem;i<n;i++){
		scanf("%d",&tem);
		a[1ll*i*i%(P-1)]=add(a[1ll*i*i%(P-1)],tem);
	}
	for(int i=0,tem;i<m;i++){
		scanf("%d",&tem);
		b[1ll*i*i*i%(P-1)]=add(b[1ll*i*i*i%(P-1)],tem);
	}
	Pow[0]=1;
	for(int i=1;i<=P-1;i++)Pow[i]=mul(Pow[i-1],c);
	for(int i=0;i<P-1;i++)a[i]=mul(a[i],Pow[P-1-((1ll*i*(i-1))>>1ll)%(P-1)]);
	for(int i=0;i<P-1;i++)b[i]=mul(b[i],Pow[P-1-((1ll*i*(i-1))>>1ll)%(P-1)]);
	solve(998244353,3,Ans[0]);
	solve(1004535809,3,Ans[1]);
	long long ans=0;
	int Inv=qsm(998244353,P-2);
	P=490019;
	for(int i=0;i<((P-1)<<1);i++){
		int x=(Ans[1][i]-Ans[0][i]);
		if(x<0)x+=1004535809;
		x=1ll*x*Inv%1004535809;
		long long val=Ans[0][i]+1ll*x*998244353;
		ans+=mul(val%P,Pow[((1ll*i*(i-1))>>1ll)%(P-1)]);
	}
	printf("%d\n",ans%P);
}