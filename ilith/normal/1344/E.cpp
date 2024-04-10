#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(rgi i=a,i##i=b;i>=i##i;--i)
#define lc k<<1
#define rc lc|1
#define mid ((l+r)>>1)
#define fi first
#define se second
#define lson lc,l,mid
#define rson rc,mid+1,r
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int N=100010;
int n,m,s[N<<2],u[N],v[N],w[N],tt;
vector<pii>a[N],T;
priority_queue<ll,vector<ll>,greater<ll>>q;
int dep[N],fa[N],id[N],C,sn[N],tp[N],sz[N],sq[N],so[N],t,x,y,vs[N<<2];
ll d[N],p[N],cv[N<<2],ans=-1;
void dfs(int x,int f){
	fa[x]=f,sz[x]=1,dep[x]=dep[f]+1;
	for(auto to:a[x])if(to.fi!=f){
		d[to.fi]=d[x]+to.se,dfs(to.fi,x),sz[x]+=sz[to.fi];
		if(sz[to.fi]>sz[sn[x]])sn[x]=to.fi;
	}
}
void Dfs(int x,int f){
	tp[x]=f,sq[id[x]=++C]=x;
	if(sn[x])Dfs(sn[x],f);
	for(auto to:a[x])if(to.fi!=fa[x]&&to.fi!=sn[x])Dfs(to.fi,to.fi);
}
void chg(int k,int i,int e){
	T.pbk({p[i]+1,t+d[i]}),p[i]=t+d[i],so[i]=e,s[k]=(e!=sn[i]);
}
void pdown(int k){
	if(cv[k]){
		cv[lc]=cv[rc]=cv[k];
		if(vs[lc])p[sq[vs[lc]]]=cv[k]+d[sq[vs[lc]]];
		if(vs[rc])p[sq[vs[rc]]]=cv[k]+d[sq[vs[rc]]];
		cv[k]=0;
	}
}
void Cvr(int x,int y,int k=1,int l=1,int r=n){
	if(l>y||r<x)return;
	if(l==r)return void(p[sq[l]]=d[sq[l]]+t);
	if(l>=x&&r<=y)return void(cv[k]=t);
	pdown(k),Cvr(x,y,lson),Cvr(x,y,rson),s[k]=s[lc]|s[rc];
}
void cvr(int x,int y,int k=1,int l=1,int r=n){
	if(l>y||r<x||!s[k])return;
	if(l==r)return chg(k,sq[l],sn[sq[l]]);
	pdown(k),cvr(x,y,lson),cvr(x,y,rson),s[k]=s[lc]|s[rc];
}
void upd(int x,int e,int k=1,int l=1,int r=n){
	if(l>x||r<x||!x)return;
	if(l==r)return chg(k,sq[l],e);
	pdown(k),upd(x,e,lson),upd(x,e,rson),s[k]=s[lc]|s[rc];
}
void build(int k,int l,int r){
	if(l==r)s[k]=(so[sq[l]]!=sn[sq[l]]),vs[k]=l;
	else build(lson),build(rson),s[k]=s[lc]|s[rc];
}
signed main(){
	scanf("%d%d",&n,&m);
	FOR(i,2,n){
		scanf("%d%d%d",u+i,v+i,w+i);
		a[u[i]].pbk({v[i],w[i]}),a[v[i]].pbk({u[i],w[i]});
	}
	dfs(1,0),Dfs(1,1);
	FOR(i,2,n){
		if(fa[u[i]]==v[i])swap(u[i],v[i]);
		so[u[i]]=v[i];
	}
	build(1,1,n);
	while(m--){
		for(scanf("%d%d",&x,&t);x;x=fa[y]){
			y=tp[x],cvr(id[y],id[x]-1);
			Cvr(id[y],id[x]-1);
			if(so[fa[y]]!=y)upd(id[fa[tp[x]]],tp[x]);
			else p[fa[tp[x]]]=d[fa[tp[x]]]+t;
		}
	}
	sort(T.begin(),T.end()),T.pbk({1e18,2e18});
	ll res=1;
	for(auto k:T){
		while(!q.empty()&&res<k.fi){
			if(q.top()<res){
				ans=q.top();
				goto tag;
			}
			q.pop(),++res;
		}
		res=k.fi,q.push(k.se);
	}
	if(ans==-1)printf("-1 %d",(int)T.size()-1),exit(0);
	tag:for(auto k:T){
		if(k.fi>=ans)break;
		tt+=(k.se<ans);
	}
	printf("%lld %d",ans,tt);
	return 0;
}