#include <cstdio>
#include <algorithm>
const int Maxn=200000;
int n,m;
int a[Maxn+5],b[Maxn+5],c[Maxn+5],d[Maxn+5];
int fa[20][Maxn+5],val[20][Maxn+5];
int e[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1],va[Maxn<<1|5],tot;
void add_edge(int from,int to,int _val){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	va[tot]=_val;
	head[from]=tot;
}
std::pair<int,int> lis_a[Maxn+5],lis_b[Maxn+5];
int s[Maxn+5],t[Maxn+5];
int dep[Maxn+5];
int ans[Maxn+5][2];
void init_dfs(int u){
	dep[u]=dep[fa[0][u]]+1;
	for(int i=1;fa[i-1][fa[i-1][u]];i++){
		fa[i][u]=fa[i-1][fa[i-1][u]];
		val[i][u]=std::max(val[i-1][u],val[i-1][fa[i-1][u]]);
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[0][u]){
			continue;
		}
		fa[0][v]=u;
		val[0][v]=va[i];
		init_dfs(v);
	}
}
int find_val(int u,int v){
	int ans=0;
	if(dep[u]<dep[v]){
		std::swap(u,v);
	}
	for(int i=19;i>=0;i--){
		if(dep[fa[i][u]]>=dep[v]){
			ans=std::max(ans,val[i][u]);
			u=fa[i][u];
		}
	}
	if(u==v){
		return ans;
	}
	for(int i=19;i>=0;i--){
		if(fa[i][u]!=fa[i][v]){
			ans=std::max(ans,val[i][u]),ans=std::max(ans,val[i][v]);
			u=fa[i][u],v=fa[i][v];
		}
	}
	ans=std::max(ans,val[0][u]),ans=std::max(ans,val[0][v]);
	return ans;
}
namespace DSU{
	int fa[Maxn+5];
	int g[Maxn+5];
	int find(int x){
		if(x==fa[x]){
			return x;
		}
		return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		int fa_x=find(x),fa_y=find(y);
		if(fa_x==fa_y){
			return;
		}
		if(e[fa_x]<e[fa_y]){
			std::swap(fa_x,fa_y);
			std::swap(x,y);
		}
		if(e[fa_x]==e[fa_y]){
			g[fa_x]=std::max(std::max(g[fa_x],g[fa_y]),find_val(fa_x,fa_y));
		}
		fa[fa_y]=fa_x;
	}
	void init(){
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&e[i]);
	}
	for(int i=1;i<n;i++){
		int u,v,z,w;
		scanf("%d%d%d%d",&u,&v,&z,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
		a[i]=u,b[i]=v,c[i]=z;
		lis_a[i]=std::make_pair(z,i);
	}
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		t[i]=u,s[i]=v;
		lis_b[i]=std::make_pair(u,i);
	}
	init_dfs(1);
	std::sort(lis_a+1,lis_a+n);
	std::sort(lis_b+1,lis_b+1+m);
	DSU::init();
	for(int i=n-1,j=m;i>0||j>0;){
		if(lis_a[i].first>=lis_b[j].first){
			int id=lis_a[i].second;
			DSU::merge(a[id],b[id]);
			i--;
		}
		else{
			int id=lis_b[j].second;
			int x=s[id],y=DSU::find(x);
			ans[id][0]=e[y];
			ans[id][1]=std::max(DSU::g[y],find_val(x,y));
			j--;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
}