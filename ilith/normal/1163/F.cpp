#include<bits/stdc++.h>
#define mid (l+r>>1)
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
#define rgi register int
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
const int N=200010;
const ll inf=1ll<<40;
int n,m,Q;
int u[N],v[N],w[N],vis[N],fa[N];
ll ds[N],dt[N];
vector<int>a[N];
struct node{
	ll id,d;
	bool operator<(node x)const{return d>x.d;}
};
priority_queue<node>q;
inline void dij(int s,ll* d){
	for(rgi i=1;i<=n;++i)d[i]=inf,vis[i]=0;
	d[s]=0,q.push(node{s,0});
	while(!q.empty()){
		int x=q.top().id;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(rgi i:a[x]){
			int to=u[i]^v[i]^x;
			if(w[i]+d[x]<d[to])d[to]=w[i]+d[x],q.push(node{to,d[to]}),fa[to]=x;
		}
	}
}
ll l[N],r[N],cnt,inr[N],mi[N<<2],f[N],key[N];
void upd(int x,int y,ll v,int k=1,int l=1,int r=n){
	if(l>y||r<x)return;
	if(l>=x&&r<=y)return void(mi[k]=min(mi[k],v));
	upd(x,y,v,k<<1,l,mid),upd(x,y,v,k<<1|1,mid+1,r);
}
void dfs(int k,int l,int r,ll v){
	v=min(v,mi[k]);
	if(l==r)return void(f[l]=v);
	dfs(k<<1,l,mid,v),dfs(k<<1|1,mid+1,r,v);
}
inline ll ps(int x){
	return w[x]+min(ds[u[x]]+dt[v[x]],ds[v[x]]+dt[u[x]]);
}
inline ll ups(int x){
	return inr[x]?f[max(l[u[x]],l[v[x]])]:ds[n];
}
signed main(){
	read(n,m,Q),memset(l,63,sizeof l),memset(mi,63,sizeof mi);
	for(rgi i=1;i<=m;++i){
		read(u[i],v[i],w[i]);
		a[u[i]].push_back(i),a[v[i]].push_back(i);
	}
	dij(1,ds),dij(n,dt);
	for(rgi x=1;x!=n;x=fa[x])l[x]=r[x]=++cnt,key[x]=1;
	l[n]=r[n]=++cnt,key[n]=1;
	for(rgi i=1;i<=n;++i)q.push(node{i,ds[i]});
	while(!q.empty()){
		int x=q.top().id;
		q.pop();
		for(rgi i:a[x]){
			int to=u[i]^v[i]^x;
			if(!key[to]&&w[i]+ds[x]==ds[to])l[to]=min(l[to],l[x]);
		}
	}
	for(rgi i=1;i<=n;++i)q.push(node{i,dt[i]});
	while(!q.empty()){
		int x=q.top().id;
		q.pop();
		for(rgi i:a[x]){
			int to=u[i]^v[i]^x;
			if(!key[to]&&w[i]+dt[x]==dt[to])r[to]=max(r[to],r[x]);
		}
	}
	for(rgi i=1;i<=m;++i){
		if(ds[u[i]]>ds[v[i]])swap(u[i],v[i]);
		if(key[u[i]]&&key[v[i]]&&ds[u[i]]+w[i]==ds[v[i]])inr[i]=1;
		if(!inr[i]){
			upd(l[u[i]]+1,r[v[i]],ds[u[i]]+dt[v[i]]+w[i]);
			upd(l[v[i]]+1,r[u[i]],ds[v[i]]+dt[u[i]]+w[i]);
		}
	}
	dfs(1,1,n,inf);
	while(Q--){
		ll t,v;
		read(t,v);
		write(min(ps(t)-w[t]+v,ups(t)),'\n');
	}
    return 0;
}