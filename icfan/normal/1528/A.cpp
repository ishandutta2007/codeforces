#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=100000;
int n;
ll f[Maxn+5][2];
int l[Maxn+5],r[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
void clear_all(){
	tot=0;
	for(int i=1;i<=n;i++){
		head[i]=0;
	}
}
void work_dfs(int u,int fa){
	f[u][0]=f[u][1]=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		work_dfs(v,u);
		f[u][0]+=std::max(f[v][1]+std::abs(l[u]-r[v]),f[v][0]+std::abs(l[u]-l[v]));
		f[u][1]+=std::max(f[v][1]+std::abs(r[u]-r[v]),f[v][0]+std::abs(r[u]-l[v]));
	}
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	work_dfs(1,0);
	printf("%lld\n",std::max(f[1][0],f[1][1]));
	clear_all();
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}