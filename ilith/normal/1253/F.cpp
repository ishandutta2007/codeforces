#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#define rgi register int
#define pbk push_back
#define pii pair<int,int>
#define fi first
#define se second
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const int N=300010,L=19;
int n,m,k,q,u[N],v[N],w[N],p[N],vis[N];
ll d[N],val[N],c[N];
struct edge{int to,w;};
struct node{
	ll id,d;
	bool operator<(node k)const{return d>k.d;}
};
priority_queue<node>Q;
vector<edge>a[N];
int f[N],fa[N][20],dep[N],tot,x,y;
int find(int X){return f[X]==X?X:f[X]=find(f[X]);}
void link(int u,int v,int w){a[u].pbk(edge{v,w}),a[v].pbk(edge{u,w});}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(rgi i=L;~i;--i)if(dep[u]-(1<<i)>=dep[v])u=fa[u][i];
	if(u==v)return u;
	for(rgi i=L;~i;--i)if(fa[v][i]!=fa[u][i])v=fa[v][i],u=fa[u][i];
	return fa[u][0];
}
signed main(){
	read(n,m,k,q),memset(d,0x7f,sizeof d),tot=n;
	for(rgi i=1;i<(n<<1);++i)f[i]=i;
	for(rgi i=1;i<=m;++i)read(u[i],v[i],w[i]),link(u[i],v[i],w[i]),c[i]=p[i]=i;
	for(rgi i=1;i<=k;++i)Q.push(node{i,d[i]=0});
	while(!Q.empty()){
		int x=Q.top().id;
		Q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto k:a[x]){
			int to=k.to,val=k.w;
			if(d[x]+val<d[to])d[to]=d[x]+val,Q.push(node{to,d[to]});
		}
	}
	for(rgi i=1;i<=m;++i)c[i]=d[u[i]]+d[v[i]]+w[i];
	sort(p+1,p+m+1,[&](int x,int y){return c[x]<c[y];});
	for(rgi i=1;i<=m;++i){
		int fx=find(u[p[i]]),fy=find(v[p[i]]);
		if(fx!=fy)val[f[fx]=f[fy]=fa[fx][0]=fa[fy][0]=++tot]=c[p[i]];
	}
	for(rgi i=tot;i;--i)dep[i]=dep[fa[i][0]]+1;
	for(rgi w=1;w<=L;++w)for(rgi i=1;i<=tot;++i)fa[i][w]=fa[fa[i][w-1]][w-1];
	while(q--)read(x,y),write(val[lca(x,y)],'\n');
	return 0;
}