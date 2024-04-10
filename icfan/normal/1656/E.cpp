#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=100000;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int deg[Maxn+5];
int n;
int dep[Maxn+5];
ll f[Maxn+5],sum[Maxn+5];
void init_dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		init_dfs(v,u);
	}
}
void work_dfs(int u,int fa){
	sum[u]=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		work_dfs(v,u);
		sum[u]+=sum[v];
	}
	if(u==1){
		f[u]=1-(sum[u]+1);
	}
	else{
		if(dep[u]&1){
			f[u]=1-sum[u];
		}
		else{
			f[u]=-1-sum[u];
		}
	}
	sum[u]+=f[u];
}
void solve(){
	scanf("%d",&n);
	tot=0;
	for(int i=1;i<=n;i++){
		head[i]=0;
		deg[i]=0;
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		deg[u]++,deg[v]++;
		add_edge(u,v),add_edge(v,u);
	}
	init_dfs(1,0);
	work_dfs(1,0);
	for(int i=1;i<=n;i++){
		printf("%lld ",f[i]);
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}