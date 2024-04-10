#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
int mul(int a,int b){return (ll)a*b%mod;}
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/* math */
const int N=3e5+5;
int n,k,col[N];
int anc[N][20],dep[N];
int hed[N],to[N*2],nxt[N*2],cnt;
inline void adde(int u,int v){++cnt;to[cnt]=v,nxt[cnt]=hed[u];hed[u]=cnt;}
inline void dfs(int x,int pre){
	dep[x]=dep[pre]+1;
	anc[x][0]=pre;for(int i=1;1<<i<=n;i++)anc[x][i]=anc[anc[x][i-1]][i-1];
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(v==pre)continue;
		dfs(v,x);
	}
}
inline int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=19;~i;i--)if(dep[anc[x][i]]>=dep[y])x=anc[x][i];
	if(x==y)return x;
	for(int i=19;~i;i--)if(anc[x][i]^anc[y][i])x=anc[x][i],y=anc[y][i];
	return anc[x][0];
}
vector<int> pit[N];
int f[N][2];
inline void dp(int x,int pre){
	if(!col[x])f[x][0]=1;
	else f[x][1]=1;
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(v==pre)continue;
		dp(v,x);
		if(col[x]){
			if(col[x]==col[v])f[x][1]=mul(f[x][1],f[v][1]);
			else f[x][1]=mul(f[x][1],add(f[v][1],f[v][0]));
		}
		else{
			f[x][1]=add(mul(f[x][1],add(f[v][1],f[v][0])),mul(f[x][0],f[v][1]));
			f[x][0]=mul(f[x][0],add(f[v][1],f[v][0]));
		}
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&col[i]);
		if(col[i])pit[col[i]].push_back(i);
	}
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		adde(u,v);adde(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=k;i++){
		int LCA=pit[i][0];
		for(size_t j=1;j<pit[i].size();j++)LCA=lca(LCA,pit[i][j]);
		if(col[LCA]!=i&&col[LCA]!=0){puts("0");return 0;}
		col[LCA]=i;
		for(size_t j=0;j<pit[i].size();j++){
			for(int id=pit[i][j];id!=LCA;id=anc[id][0]){
				if(col[id]!=0&&col[id]!=i){puts("0");return 0;}
				if(id!=pit[i][j]&&col[id]==i)break;
				col[id]=i;
			}
		}
	}
	dp(1,0);
	printf("%d",f[1][1]);
}