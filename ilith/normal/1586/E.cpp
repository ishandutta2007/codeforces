#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a;i<=b;++i)
typedef long long ll;
using namespace std;
const int N=300010;
int n,m,q,vis[N],u,v,fa[N][22],d[N];
vector<int>a[N],b[N];
int dfs(int x,int f){
	vis[x]=1,fa[x][0]=f,d[x]=d[f]+1;
	for(rgi to:a[x]){
		if(!vis[to])b[x].pbk(to),dfs(to,x);
	}
}
int LCA(int u,int v){
	if(d[u]<d[v])swap(u,v);
	for(rgi i=20;~i;--i)if(d[u]-(1<<i)>=d[v])u=fa[u][i];
	if(u==v)return u;
	for(rgi i=20;~i;--i)if(fa[v][i]!=fa[u][i])v=fa[v][i],u=fa[u][i];
	return fa[u][0];
}
int l[N],r[N],D[N],ans;
vector<int>x[2];
void work(int u,int v,int w){
	while(u!=v)x[w].pbk(u),u=fa[u][0];
}
void w0rk(int u,int v){
	while(u!=v)++D[u],u=fa[u][0];
}
signed main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,m)scanf("%d%d",&u,&v),a[u].pbk(v),a[v].pbk(u);
	dfs(1,0);
	for(rgi w=1;(1<<w)<n;++w)FOR(i,1,n)fa[i][w]=fa[fa[i][w-1]][w-1];
	scanf("%d",&q);
	FOR(i,1,q){
		scanf("%d%d",l+i,r+i);
		int w=LCA(l[i],r[i]);
		w0rk(l[i],w),w0rk(r[i],w);
	}
	FOR(i,1,n){
		int g=(D[i]&1);
		for(rgi to:b[i])if(to!=fa[i][0])g+=(1&D[to]);
		if(g&1)++ans;
	}
	if(ans)printf("NO\n%d",ans/2),exit(0);
	puts("YES");
	FOR(i,1,q){
		int w=LCA(l[i],r[i]);
		x[0].clear(),x[1].clear();
		work(l[i],w,0),work(r[i],w,1);
		reverse(x[1].begin(),x[1].end());
		printf("%d\n",x[0].size()+x[1].size()+1);
		for(rgi k:x[0])printf("%d ",k);
		printf("%d ",w);
		for(rgi k:x[1])printf("%d ",k);
		puts("");
	}
	return 0;
}
//?