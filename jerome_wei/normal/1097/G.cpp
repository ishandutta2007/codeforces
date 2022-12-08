#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
int mul(int a,int b){return (ll)a*b%mod;}
int qpow(int a,int b){ int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret; }
/* math */ 
const int N=1e5+5;
int n,k;
int f[N][201];
int g[N][201];
int hed[N],to[N*2],nxt[N*2],cnt;
inline void adde(int u,int v){
	++cnt;to[cnt]=v,nxt[cnt]=hed[u];hed[u]=cnt;
}
int S[210][210];
int sz[N];
int ans[210];

inline void dfs(int x,int pre){
	f[x][0]=1;
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(v==pre)continue;
		dfs(v,x);
		for(int t=0;t<=min(k,sz[x]+sz[v]+1);t++){
			g[x][t] = add(f[x][t], f[v][t]);
			if(t)g[x][t] = add(g[x][t], f[v][t-1]);
		}
		for(int i=min(k,sz[v]);~i;i--){
			for(int j=min(k-i,sz[x]);~j;j--){
				g[x][i+j] = add(g[x][i+j], mul(f[x][j], f[v][i]));
				g[x][i+j+1] = add(g[x][i+j+1], mul(f[x][j], f[v][i]));
				ans[i+j] = add(ans[i+j], mul(f[x][j], f[v][i])); 
				ans[i+j+1] = add(ans[i+j+1], mul(f[x][j], f[v][i]));
			}
		}
		for(int t=0;t<=min(k,sz[x]+sz[v]+1);t++){
			f[x][t]=g[x][t]; g[x][t]=0;
		}
		sz[x]+=sz[v] + 1;
	}
}
int fac[N];

int main()
{
	cin >> n >> k;
	S[0][0]=1;
	for(int i=1;i<=k;i++)for(int j=1;j<=k;j++){
		S[i][j]=add(S[i-1][j-1],mul(S[i-1][j],j));
	}
	fac[0]=1;for(int i=1;i<=k;i++)fac[i]=mul(fac[i-1],i);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		adde(u,v);adde(v,u);
	}
	dfs(1,0);
	int ret=0;
	for(int i=1;i<=k;i++)ret=add(ret,mul(ans[i],mul(S[k][i],fac[i])));
	cout << ret << endl;
}