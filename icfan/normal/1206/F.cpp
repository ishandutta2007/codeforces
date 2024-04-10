#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define Maxn 1000
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int n;
int sz[Maxn+5],maxn[Maxn+5];
int rt,G;
int mx(int a,int b){
	return a>b?a:b;
}
void get_root(int root,int fa){
	sz[root]=1;
	for(int i=head[root];i;i=nxt[i]){
		if(arrive[i]==fa){
			continue;
		}
		get_root(arrive[i],root);
		sz[root]+=sz[arrive[i]];
		maxn[root]=mx(maxn[root],sz[arrive[i]]);
	}
	maxn[root]=mx(maxn[root],n-sz[root]);
	if(G>maxn[root]){
		G=maxn[root];
		rt=root;
	}
}
int fa[Maxn+5];
void init_dfs(int root){
	sz[root]=1;
	for(int i=head[root];i;i=nxt[i]){
		if(arrive[i]==fa[root]){
			continue;
		}
		fa[arrive[i]]=root;
		init_dfs(arrive[i]);
		sz[root]+=sz[arrive[i]];
	}
}
vector<int> edge[Maxn+5];
bool cmp(int x,int y){
	return sz[x]>sz[y];
}
int cnt=1,t=1;
void dfs_1(int root,int w){
	printf("%d %d %d\n",fa[root],root,cnt-w);
	int now=cnt;
	cnt++;
	for(int i=0;i<(int)edge[root].size();i++){
		if(edge[root][i]==fa[root]){
			continue;
		}
		dfs_1(edge[root][i],now);
	}
}
void dfs_2(int root,int w){
	printf("%d %d %d\n",fa[root],root,cnt*t-w);
	int now=cnt*t;
	t++;
	for(int i=0;i<(int)edge[root].size();i++){
		if(edge[root][i]==fa[root]){
			continue;
		}
		dfs_2(edge[root][i],now);
	}
}
int main(){
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	G=n;
	get_root(1,0);
	init_dfs(rt);
	sort(edge[rt].begin(),edge[rt].end(),cmp);
	for(int i=0;i<(int)edge[rt].size();i++){
		if(cnt*3<n){
			dfs_1(edge[rt][i],0);
		}
		else{
			dfs_2(edge[rt][i],0);
		}
	}
	return 0;
}