#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define pii pair<int,int>
#define mid (l+r>>1)
#define fi first
#define se second
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
typedef long long ll;
typedef unsigned int ui;
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
const ll N=300010,inf=1e18;
ui n,m,c[N],u,v,l,r,fa[20][N],dep[N];
mt19937 rnd(time(0));
vector<int>a[N];
map<ll,ll>mp;
ui rt[N],ls[N*170],rs[N*170],tot;
ll s[N],sum[N*170];
ui upd(ll x,ui k,ll l=1,ll r=inf){
	if(l>x||r<x)return k;
	int k1=++tot;
	sum[k1]=sum[k]^x;
	if(l==r)return k1;
	ls[k1]=upd(x,ls[k],l,mid),rs[k1]=upd(x,rs[k],mid+1,r);
	return k1;
}
int qry(ll x,ll y,ui k,ui k2,ll v,ll l=1,ll r=inf){
	if(v>r||v<l)v=0;
	if(l>y||r<x||!(sum[k]^sum[k2]^v))return -1;
	if(l==r)return mp[l];
	int res=qry(x,y,ls[k],ls[k2],v,l,mid);
	return ~res?res:qry(x,y,rs[k],rs[k2],v,mid+1,r);
}
void dfs(int x,int f){
	rt[x]=upd(s[c[x]],rt[f]),fa[0][x]=f,dep[x]=dep[f]+1;
	for(rgi to:a[x])if(to!=f)dfs(to,x);
}
int LCA(int u,int v){
	if(dep[u]>dep[v])swap(u,v);
	for(rgi w=18;~w;--w)if(dep[fa[w][v]]>=dep[u])v=fa[w][v];
	if(u==v)return u;
	for(rgi w=18;~w;--w)if(fa[w][v]!=fa[w][u])v=fa[w][v],u=fa[w][u];
	return fa[0][u];
}
signed main(){
	read(n,m);
	for(rgi i=1;i<=n;++i)read(c[i]),s[i]=(rnd()*(ll)rnd())%inf+1u;
	sort(s+1,s+n+1);
	for(rgi i=1;i<=n;++i){
		if(s[i]<=s[i-1])s[i]=s[i-1]+1;
		mp[s[i]]=i;
	}
	for(rgi i=1;i<n;++i)read(u,v),a[u].pbk(v),a[v].pbk(u);
	dfs(1,0);
	for(rgi w=1;w<=18;++w)for(rgi i=1;i<=n;++i)fa[w][i]=fa[w-1][fa[w-1][i]];
	while(m--)read(u,v,l,r),write(qry(s[l],s[r],rt[u],rt[v],s[c[LCA(u,v)]]),'\n');
	return 0;
}