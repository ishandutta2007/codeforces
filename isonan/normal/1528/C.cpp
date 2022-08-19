#include <cstdio>
#include <vector>
#include <set>

std::set<int>set;
int t,n;
std::vector<int>vec[300001];
int now,f[300001],g[300001];
int ord[300001];
struct tree{
	int head[300001],nxt[300001],b[300001],k;
	int dfn[300001],mx[300001],fa[300001],now,ord[300001];
	void push(int s,int t){
		nxt[++k]=head[s];
		head[s]=k;
		b[k]=t;
	}
	void dfs(int x){
		dfn[x]=++now;
		ord[now]=x;
		for(int i=head[x];i;i=nxt[i])
			dfs(b[i]);
		mx[x]=now;
	}
	void build(){
		for(int i=1;i<=n;++i)head[i]=0;
		k=0;
		for(int i=2,tem;i<=n;++i){
			scanf("%d",fa+i);
			push(fa[i],i);
		}
		now=0;
		dfs(1);
	}
}t1,t2;
int ans;
void solve(int x){
	int u=t2.ord[*--set.lower_bound(t2.dfn[x])];
	if(t2.mx[u]>=t2.mx[x]){
		set.erase(t2.dfn[u]);
	}
	set.insert(t2.dfn[x]);
	ans=std::max(ans,(int)set.size());
	for(int i=t1.head[x];i;i=t1.nxt[i])
		solve(t1.b[i]);
	set.erase(t2.dfn[x]);
	if(t2.mx[u]>=t2.mx[x]){
		set.insert(t2.dfn[u]);
	}
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		t1.build();
		t2.build();
		set.clear();
		set.insert(0);
		ans=0;
		solve(1);
		printf("%d\n",ans-1);
	}
}