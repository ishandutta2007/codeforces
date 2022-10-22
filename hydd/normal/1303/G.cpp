#include<bits/stdc++.h>
#define ls now<<1
#define rs now<<1|1
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
vector<int> vec[810000];
int n; ll ans;
int rt,mn,all,sz[810000],val[810000],tree[1610000];
bool vis[810000];
struct node{
	ll k,b;
	node(){}
	node(ll _k,ll _b):k(_k),b(_b){}
} a[810000],b[810000]; int tot;
ll calc(int p,int x){
	return a[p].k*x+a[p].b;
}
void getrt(int u,int f){
	sz[u]=1; int tmp=0;
	for (int v:vec[u]){
		if (v==f||vis[v]) continue;
		getrt(v,u); sz[u]+=sz[v];
		tmp=max(tmp,sz[v]);
	}
	tmp=max(tmp,all-sz[u]);
	if (tmp<mn) mn=tmp,rt=u;
}
void dfs(int u,int f,int bel,int d,ll s,ll x,ll y){
	s+=val[u]; y+=s; x+=1ll*(d+1)*val[u];
	tot++; a[tot]=node(s,x); b[tot]=node(d,y+1ll*(d+1)*val[bel]);
	ans=max(ans,x+val[bel]);
	for (int v:vec[u]){
		if (vis[v]||v==f) continue;
		dfs(v,u,bel,d+1,s,x,y);
	}
}
void build(int now,int l,int r){
	tree[now]=0;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(ls,l,mid); build(rs,mid+1,r);
}
void change(int now,int l,int r,int v){
	if (l==r){
		if (calc(v,l)>calc(tree[now],l)) swap(tree[now],v);
		return;
	}
	int mid=(l+r)>>1;
	if (a[tree[now]].k>a[v].k) swap(tree[now],v);
	if (calc(v,mid)>calc(tree[now],mid)){
		change(ls,l,mid,tree[now]);
		tree[now]=v;
	} else change(rs,mid+1,r,v);
}
ll query(int now,int l,int r,int x){
	if (l==r) return calc(tree[now],x);
	int mid=(l+r)>>1; ll res=calc(tree[now],x);
	if (x<=mid) return max(res,query(ls,l,mid,x));
	else return max(res,query(rs,mid+1,r,x));
}
int cnt,p[810000],L[810000],R[810000];
void solve(int u){
	vis[u]=true; tot=0; cnt=0;
	for (int v:vec[u]){
		if (vis[v]) continue;
		p[++cnt]=v;
		L[v]=tot+1; dfs(v,u,u,1,0,0,0); R[v]=tot;
	}
	build(1,0,tot);
	for (int i=1;i<=cnt;i++){
		int v=p[i]; if (vis[v]) continue;
		for (int i=L[v];i<=R[v];i++) ans=max(ans,query(1,0,tot,b[i].k)+b[i].b);
		for (int i=L[v];i<=R[v];i++) change(1,0,tot,i);
	}
	build(1,0,tot);
	for (int i=cnt;i>=1;i--){
		int v=p[i]; if (vis[v]) continue;
		for (int i=L[v];i<=R[v];i++) ans=max(ans,query(1,0,tot,b[i].k)+b[i].b);
		for (int i=L[v];i<=R[v];i++) change(1,0,tot,i);
	}
	int tmp=all;
	for (int v:vec[u]){
		if (vis[v]) continue;
		mn=INF; all=(sz[v]<sz[u]?sz[v]:tmp-sz[u]);
		getrt(v,u); solve(rt); 
	}
}
int main(){
	scanf("%d",&n); int u,v;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for (int i=1;i<=n;i++) scanf("%d",&val[i]);
	mn=INF; all=n;
	getrt(1,0); solve(rt);
	printf("%lld\n",ans);
	return 0;
}