#include<bits/stdc++.h>
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
const int N=200010,LOG=18;
int n,c[N],u,v,ch[N],fa[N][LOG+1],dep[N],ans,id[N],C,g;
vector<int>a[N],s[N],pri,t[N];
void dfs(int x,int f){
	fa[x][0]=f,dep[x]=dep[f]+1,id[x]=++C;
	for(rgi to:a[x])if(to!=f)dfs(to,x);
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(rgi i=LOG;~i;--i){
		if(dep[u]-(1<<i)>=dep[v])u=fa[u][i];
	}
	if(u==v)return u;
	for(rgi i=LOG;~i;--i){
		if(fa[v][i]!=fa[u][i])v=fa[v][i],u=fa[u][i];
	}
	return fa[u][0];
}
int d[N],vis[N];
int far(int x,int f){
	d[x]=d[f]+1;
	int res=x;
	for(rgi to:t[x])if(to!=f){
		int u=far(to,x);
		if(d[res]<d[u])res=u;
	}
	return res;
}
void solve(vector<int>&v){
	int S=v.size();
	if(S<=ans)return;
	for(rgi k:v)vis[k]=1;
	sort(v.begin(),v.end(),[&](int x,int y){return id[x]<id[y];});
	for(rgi i=1;i<S;++i)v.pbk(LCA(v[i],v[i-1]));
	sort(v.begin(),v.end(),[&](int x,int y){return id[x]<id[y];});
	v.erase(unique(v.begin(),v.end()),v.end());
	for(rgi i=1;i<v.size();++i){
		int to=LCA(v[i],v[i-1]);
		if(vis[v[i]]&&vis[to]&&to==fa[v[i]][0])t[to].pbk(v[i]),t[v[i]].pbk(to);
	}
	for(rgi k:v)if(vis[k]&&!d[k])ans=max(ans,d[far(far(k,0),0)]);
	for(rgi k:v)t[k].clear(),vis[k]=0;
}
signed main(){
	ch[1]=1;
	for(rgi i=1;i<=200000;i++){
		if(!ch[i])pri.pbk(i);
		for(rgi j:pri){
			ch[i*j]=1;
			if(i%j==0||i*j>200000)break;
		}
	}
	read(n);
	for(rgi i=1;i<=n;++i){
		read(c[i]),g=c[i];
		for(rgi k:pri){
			if(k*k>c[i])break;
			if(g%k==0)s[k].pbk(i);
			while(g%k==0)g/=k;
		}
		if(g!=1)s[g].pbk(i);
	}
	for(rgi i=1;i<n;++i)read(u,v),a[u].pbk(v),a[v].pbk(u);
	dfs(1,0);
	for(rgi w=1;w<=LOG;++w){
		for(rgi i=1;i<=n;++i)fa[i][w]=fa[fa[i][w-1]][w-1];
	}
	for(rgi k:pri)solve(s[k]);
	write(ans);
	return 0;
}