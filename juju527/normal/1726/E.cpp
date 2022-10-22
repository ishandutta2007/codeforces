//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=6e5+5,N=3e5,mod=998244353,G=3,Gi=(mod+1)/3;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return (x>=mod)?x-mod:x;}
inline void add(int &x,int y){x=add(x+y);return ;}
inline int sub(int x){return (x<0)?x+mod:x;}
inline int power(int x,int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		b>>=1;
	}
	return res;
}
int fc[maxn],ifc[maxn];
inline int binom(int n,int m){
	if(n==m)return 1;
	if(n<m||m<0)return 0;
	return 1ll*fc[n]*ifc[m]%mod*ifc[n-m]%mod;
}
int rev[2*maxn];
int pw[2][2*maxn];
void pre(int lim){
	for(int i=1;i<lim;i<<=1){
		pw[0][i]=pw[1][i]=1;
		pw[0][i+1]=power(G,(mod-1)/(i<<1));
		pw[1][i+1]=power(Gi,(mod-1)/(i<<1));
		for(int j=2;j<i;j++){
			pw[0][i+j]=1ll*pw[0][i+j-1]*pw[0][i+1]%mod;
			pw[1][i+j]=1ll*pw[1][i+j-1]*pw[1][i+1]%mod;
		}
	}
	return ;
}
void NTT(int *f,int lim,bool op){
	for(int i=0;i<lim;i++)if(rev[i]>i)swap(f[i],f[rev[i]]);
	for(int mid=1;mid<lim;mid<<=1){
		int *Pw=pw[op]+mid;
		for(int j=0;j<lim;j+=(mid<<1)){
			int *a=f+j,*b=f+j+mid;
			for(int k=0;k<mid;k++,a++,b++){
				int u=*a,v=1ll*Pw[k]**b%mod;
				*a=add(u+v),*b=sub(u-v);
			}
		}
	}
	if(!op)return ;
	int inv=power(lim,mod-2);
	for(int i=0;i<lim;i++)f[i]=1ll*f[i]*inv%mod;
	return ;
}
int w[maxn];
int f[2*maxn],g[2*maxn];
int val[2*maxn];
int main(){
    int T;
	T=read();
	fc[0]=1;for(int i=1;i<=N;i++)fc[i]=1ll*fc[i-1]*i%mod;
	ifc[N]=power(fc[N],mod-2);for(int i=N-1;i>=0;i--)ifc[i]=1ll*ifc[i+1]*(i+1)%mod;
	val[0]=val[1]=1;for(int i=2;i<=N;i++)val[i]=1ll*val[i-2]*i%mod;
	for(int i=0;i<=N/2;i++)f[2*i]=1ll*ifc[2*i]*(i==0?1:val[2*i-1])%mod;
	for(int i=0;i<=N;i++)g[i]=ifc[i];
	int lim=1,k=0;
	while(lim<=N+N)lim<<=1,k++;
	pre(lim);
	for(int i=0;i<lim;i++)rev[i]=rev[i>>1]>>1|((i&1)<<(k-1));
	NTT(f,lim,0);NTT(g,lim,0);
	for(int i=0;i<lim;i++)f[i]=1ll*f[i]*g[i]%mod;
	NTT(f,lim,1);
	for(int i=0;i<=N;i++)f[i]=1ll*f[i]*fc[i]%mod;
	w[0]=1;for(int i=1;i<=N;i++)w[i]=add(w[i-1]+w[i-1]);
	while(T--){
		int n;
		n=read();
		int res=0;
		for(int i=0;i<=n/4;i++)add(res,1ll*binom(n-2*i,2*i)*((i==0)?1:val[2*i-1])%mod*f[n-4*i]%mod*w[i]%mod);
		printf("%d\n",res);
	}
    return 0;
}