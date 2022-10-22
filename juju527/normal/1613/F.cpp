#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2.5e5+5;
const int G=3,Gi=332748118,mod=998244353;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
struct Edge{int to,nxt;}e[2*maxn];
int cnt;
int head[maxn];
int s[maxn];
void add(int u,int v){
	e[cnt]=(Edge){v,head[u]};
	head[u]=cnt++;
	return ;
}
void dfs(int x,int fa){
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		dfs(tmp,x);s[x]++;
	}
	return ;
}
int rev[3*maxn];
int f[3*maxn];
inline int add(int x){return x>=mod?x-mod:x;}
inline int sub(int x){return x<0?x+mod:x;}
inline int power(int x,int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		b>>=1;
	}
	return res;
}
int pw[2][3*maxn];
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
void NTT(int *f,int lim,int op){
	for(int i=0;i<lim;i++)if(i<rev[i])swap(f[i],f[rev[i]]);
	for(int mid=1;mid<lim;mid<<=1){
		for(int j=0;j<lim;j+=(mid<<1)){
			for(int k=0;k<mid;k++){
				int u=f[j+k],v=1ll*pw[op][mid+k]*f[j+k+mid]%mod;
				f[j+k]=add(u+v),f[j+k+mid]=sub(u-v);
			}
		}
	}
	if(!op)return ;
	int inv=power(lim,mod-2);
	for(int i=0;i<lim;i++)f[i]=1ll*f[i]*inv%mod;
	return ;
}
int lt[20][3*maxn],rt[20][3*maxn];
void divide(int d,int l,int r,int *f){
	if(l==r){f[1]=sub(-s[l]),f[0]=1;return ;}
	int mid=l+((r-l)>>1);
	divide(d+1,l,mid,lt[d]),divide(d+1,mid+1,r,rt[d]);
	int lim=1,k=0;
	while(lim<=(r-l+1))lim<<=1,k++;
	for(int i=1;i<lim;i++)rev[i]=rev[i>>1]>>1|((i&1)<<k-1);
	NTT(lt[d],lim,0),NTT(rt[d],lim,0);
	for(int i=0;i<lim;i++)f[i]=1ll*lt[d][i]*rt[d][i]%mod;
	NTT(f,lim,1);
	for(int i=r-l+2;i<lim;i++)f[i]=0;
	for(int i=0;i<lim;i++)lt[d][i]=rt[d][i]=0;
	return ;
}
int fc[maxn];
int main(){
//    freopen("CF1613F.in","r",stdin);
//    freopen("CF1613F.out","w",stdout);
	int n;
	n=read();
	memset(head,-1,sizeof(head));
	for(int i=1;i<n;i++){
		int u,v;
		u=read();v=read();
		add(u,v),add(v,u);
	}
	dfs(1,0);
	pre(1<<18);
	divide(0,1,n,f);
	fc[0]=1;for(int i=1;i<=n;i++)fc[i]=1ll*fc[i-1]*i%mod;
    int res=0;
//	for(int i=0;i<=n;i++)cerr<<f[i]<<" ";
//	cerr<<endl;
	for(int i=0;i<=n;i++)res=add(res+1ll*fc[n-i]*f[i]%mod);
	printf("%d\n",res);
	return 0;
}