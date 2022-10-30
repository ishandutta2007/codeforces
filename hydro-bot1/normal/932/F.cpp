// Hydro submission #61e74c88e73dc20247247fc9@1642593483946
/*
Author: cnyz
----------------
Looking! The blitz loop this planet to search way.
Only my RAILGUN can shoot it. 
*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int N=1e5,V=1e5;
const ll inf=1e18;
int n,a[N+10],b[N+10];
vector<int> G[N+10];
int cnt,ls[V*8+10],rs[V*8+10],id[V*8+10],rt[N+10],tot;
struct Line{
	ll k,b;
} L[V*8+10];
ll f[N+10];
ll calc(int u,int x) {return L[u].k*x+L[u].b;}
void insert(int &p,int l,int r,int u) {
	if(!p) {
		p=++cnt;id[p]=u;
		return;
	}
	if(l==r) {
		if(calc(id[p],l)>calc(u,l)) id[p]=u;
		return;
	}
	int mid=(l+r)>>1;
	if(calc(u,mid)<calc(id[p],mid)) swap(id[p],u);
	if(calc(id[p],l)>calc(u,l)) insert(ls[p],l,mid,u);
	else if(calc(id[p],r)>calc(u,r)) insert(rs[p],mid+1,r,u);
}
ll query(int p,int l,int r,int x) {
	if(!p) return inf;
	if(l==r) return calc(id[p],x);
	int mid=(l+r)>>1;ll ret=calc(id[p],x);
	if(x<=mid) ret=min(ret,query(ls[p],l,mid,x));
	else ret=min(ret,query(rs[p],mid+1,r,x));
	return ret;
}
int merge(int a,int b,int l,int r) {
	if(!a||!b) return a+b;
	if(l==r) return calc(id[a],l)>calc(id[b],l)?b:a;
	int mid=(l+r)>>1;
	ls[a]=merge(ls[a],ls[b],l,mid);
	rs[a]=merge(rs[a],rs[b],mid+1,r);
	insert(a,l,r,id[b]);
	return a;
}
void dfs(int u,int fa) {
	for(auto v:G[u]) if(v!=fa)
		dfs(v,u),rt[u]=merge(rt[u],rt[v],-V,V);
	if(rt[u]) f[u]=query(rt[u],-V,V,a[u]);
	L[++tot]={b[u],f[u]};
	insert(rt[u],-V,V,tot);
}
int main() {
	scanf("%d",&n);L[0].b=inf;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1,x,y;i<n;i++) {
		scanf("%d %d",&x,&y);
		G[x].pb(y),G[y].pb(x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++) printf("%lld ",f[i]);
	puts("");
}