#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int p=1e9+7;
const int N=8010;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int fac[N],ifac[N],n;
int inv(int x,int base=p-2){
	if(base<0)base+=p-1;
	int res=1;
	while(base){
		if(base&1)res=res*x%p;
		x=x*x%p;
		base>>=1;
	}return res;
}
void init(int n){
	fac[0]=1;rep(i,n)fac[i]=fac[i-1]*i%p;
	ifac[n]=inv(fac[n]);
	Rof(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%p;
	assert(ifac[2]*fac[2]%p==1);
}
struct edge{
	int pre,to;
}e[2*N];int last[N],cnt;
void add(int x,int y){e[++cnt].pre=last[x];e[cnt].to=y;last[x]=cnt;}
int C(int n,int m){return fac[n]*ifac[m]%p*ifac[n-m]%p;}
namespace std{
//	vector<int>dp[2][N];
	int id[N],idx;
	vector<int>dp[2][N];
	int tmp[2][N],sz[N],f[N],g[N],son[N];
	void clear(int x){
		for(int i=0;i<dp[0][x].size();i++)dp[0][x][i]=dp[1][x][i]=0;
	}
	void merge(int x,int to,int op=0){
		memset(tmp,0,sizeof tmp);
		For(i,0,sz[x])For(j,0,sz[to]){
			if(i+j)tmp[0][i+j-1]=(tmp[0][i+j-1]+dp[0][id[x]][i]*dp[0][id[to]][j])%p;
			tmp[0][i+j]=(tmp[0][i+j]+dp[0][id[x]][i]*dp[1][id[to]][j])%p;
			if(i+j)tmp[1][i+j-1]=(tmp[1][i+j-1]+dp[1][id[x]][i]*dp[0][id[to]][j])%p;
			if(i+j)tmp[1][i+j-1]=(tmp[1][i+j-1]+dp[0][id[x]][i]*dp[1][id[to]][j])%p;
			tmp[1][i+j]=(tmp[1][i+j]+dp[1][id[x]][i]*dp[1][id[to]][j])%p;
		}
		if(op)id[x]=op;
		sz[x]+=sz[to];
		dp[0][id[x]].resize(sz[x]+1);dp[1][id[x]].resize(sz[x]+1);clear(id[x]);
		For(i,0,sz[x])dp[0][id[x]][i]=tmp[0][i],dp[1][id[x]][i]=tmp[1][i];
	}
	void prepare(int x,int fa){
		for(int i=last[x];i;i=e[i].pre){
			int to=e[i].to;if(to==fa)continue;
			prepare(to,x);sz[x]+=sz[to];
			if(sz[to]>sz[son[x]])son[x]=to; 
		}sz[x]++;
	}
	void dfs(int x,int fa){
		dp[0][++idx].resize(2);dp[1][idx].resize(2);clear(idx);
		id[x]=idx;dp[0][id[x]][1]=1;dp[1][id[x]][1]=1;sz[x]=1;
		if(son[x]){dfs(son[x],x);merge(x,son[x],id[son[x]]);}
		for(int i=last[x];i;i=e[i].pre){
			int to=e[i].to;if(to==fa||to==son[x])continue;
			dfs(to,x);merge(x,to);
		}
	}
	void solve(){
		prepare(1,0);memset(sz,0,sizeof sz);dfs(1,0);
		For(i,0,n-1)f[i]=dp[1][id[1]][n-i]*inv(n,n-i-2)%p;
		For(i,0,n-1)For(j,i,n-1)
			g[i]=(g[i]+(((j-i)%2)?-1:1)*C(j,i)%p*f[j])%p;
		For(i,0,n-1)printf("%lld ",(g[i]+p)%p);
	}
}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();init(n);
	rep(i,n-1){int x=read(),y=read();add(x,y),add(y,x);}
	std::solve();
	return 0;
}