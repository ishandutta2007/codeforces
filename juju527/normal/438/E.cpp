#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,mod=998244353,G=3,Gi=332748118;
int r[maxn<<2];
long long f[maxn<<2],g[maxn<<2];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
long long power(long long x,long long b){
	long long ans=1;
	while(b){
		if(b&1)ans=ans*x%mod;
		x=x*x%mod;
		b>>=1;
	}
	return ans;
}
void NTT(long long *f,int lim,int opt){
	for(int i=1;i<lim;i++)if(i<r[i])swap(f[i],f[r[i]]);
	for(int mid=1;mid<lim;mid<<=1){
		long long wn=power(opt==1?G:Gi,(mod-1)/(mid<<1));
		for(int j=0;j<lim;j+=(mid<<1)){
			long long w=1;
			for(int k=0;k<mid;k++,w=w*wn%mod){
				long long u=f[j+k],v=w*f[j+k+mid]%mod;
				f[j+k]=(u+v)%mod;
				f[j+k+mid]=(u-v+mod)%mod;
			}
		}
	}
	if(opt==1)return ;
	long long inv=power(lim,mod-2);
	for(int i=0;i<lim;i++)f[i]=f[i]*inv%mod;
	return ;
}
long long A[maxn<<2];
void inv(int n,long long *f,long long *g){
	if(n==1){g[0]=power(f[0],mod-2);return ;}
	inv((n+1)>>1,f,g);
	int lim=1,k=0;
	while(lim<(n<<1))lim<<=1,k++;
	for(int i=1;i<lim;i++)r[i]=r[i>>1]>>1|((i&1)<<k-1);
	for(int i=0;i<n;i++)A[i]=f[i];
	for(int i=n;i<lim;i++)g[i]=A[i]=0;
	NTT(g,lim,1);NTT(A,lim,1);
	for(int i=0;i<lim;i++)g[i]=(2ll*g[i]%mod-A[i]*g[i]%mod*g[i]%mod+mod)%mod;
	NTT(g,lim,-1);
	for(int i=n;i<lim;i++)g[i]=0;
	return ;
}
long long B[maxn<<2],C[maxn<<2];
long long inv2=power(2,mod-2);
void sqrt(int n,long long *f,long long *g){
	if(n==1){g[0]=1;return ;}
	sqrt((n+1)>>1,f,g);
	inv(n,g,B);
	int lim=1,k=0;
	while(lim<(n<<1))lim<<=1,k++;
	for(int i=1;i<lim;i++)r[i]=r[i>>1]>>1|((i&1)<<k-1);
	for(int i=0;i<n;i++)C[i]=f[i];
	for(int i=n;i<lim;i++)B[i]=C[i]=0;
	NTT(g,lim,1);NTT(B,lim,1);NTT(C,lim,1);
	for(int i=0;i<lim;i++)g[i]=(C[i]+g[i]*g[i]%mod)%mod*inv2%mod*B[i]%mod;
	NTT(g,lim,-1);
	for(int i=n;i<lim;i++)g[i]=0;
	return ;
}
int main(){
	int n,m;
	n=read();m=read();
	for(int i=1;i<=n;i++)g[read()]=1;
	for(int i=0;i<=1e5;i++)g[i]=(mod-4ll*g[i]%mod)%mod;
	g[0]++;
	sqrt(1e5+1,g,f);
	f[0]++;
	memset(g,0,sizeof(g));
	inv(1e5+1,f,g);
	for(int i=1;i<=m;i++)printf("%lld\n",2ll*g[i]%mod);
	return 0;
}