#include <cstdio>
typedef long long ll;
const int Maxn=200000;
int n;
int fa[Maxn+5];
int head[Maxn+5],nxt[Maxn+5];
void add_edge(int from,int to){
	nxt[to]=head[from],head[from]=to;
}
int ans;
int l[Maxn+5],r[Maxn+5];
int init_dfs(int u){
	ll sum=0;
	for(int v=head[u];v;v=nxt[v]){
		sum+=init_dfs(v);
	}
	if(sum>=r[u]){
		return r[u];
	}
	if(sum<l[u]){
		ans++;
		return r[u];
	}
	return sum;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		head[i]=0;
	}
	for(int i=2;i<=n;i++){
		scanf("%d",&fa[i]);
		add_edge(fa[i],i);
	}
	for(int i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
	}
	ans=0;
	init_dfs(1);
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}