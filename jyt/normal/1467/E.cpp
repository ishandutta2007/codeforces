#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 200005
#define ll long long
#define db double
#define pb push_back
#define lb(x) std::lower_bound(so+1,so+1+tot,x)-so
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,a,b,ecnt,last[N],A[N],so[N],tot,Sum[N],dfn[N],idx,fa[N][20],deep[N],mark[N],mark2[N],flag,ans;
std::vector<int>S[N];
struct road{int to,nex;}e[N<<1];
void adde(int u,int v) {e[++ecnt]=(road){v,last[u]},last[u]=ecnt;}
class SegmentTree
{
#define lc t[x].ls
#define rc t[x].rs
#define mid ((l+r)>>1)
	struct node{int ls,rs,v;}t[N*20];
public:
	int root[N],cntnode;
	void insert(int &x,int l,int r,int p,int v)
	{
		x=++cntnode;
		if(l==r) {t[x].v+=v;return;}
		p<=mid?insert(lc,l,mid,p,v):insert(rc,mid+1,r,p,v);
	}
	void merge(int &x,int y,int l,int r)
	{
		if(!x||!y) return void(x=x?x:y);
		if(l==r) return void(t[x].v+=t[y].v);
		merge(lc,t[y].ls,l,mid),merge(rc,t[y].rs,mid+1,r);
	}
	int ask(int x,int l,int r,int p)
	{
		if(!x||l==r) return t[x].v;
		return p<=mid?ask(lc,l,mid,p):ask(rc,mid+1,r,p);
	}
}T;
void dfs1(int x,int fath=0)
{
	dfn[x]=++idx,fa[x][0]=fath,deep[x]=deep[fath]+1;
	if(Sum[A[x]]>1) T.insert(T.root[x],1,tot,A[x],1);
	int cnt=0;
	for(int k=last[x];k;k=e[k].nex)
		if(e[k].to^fath)
		{
			dfs1(e[k].to,x);
			mark2[e[k].to]=T.ask(T.root[e[k].to],1,tot,A[x]);
			T.merge(T.root[x],T.root[e[k].to],1,tot);
			if(Sum[A[x]]>1&&T.ask(T.root[e[k].to],1,tot,A[x])) cnt++;
		}
	if(T.ask(T.root[x],1,tot,A[x])<Sum[A[x]]) cnt++;
	if(cnt>1) flag=1;
}
void dfs2(int x,int fath,int v)
{
	v+=mark[x];
	if(v==tot) ans++;
	for(int k=last[x];k;k=e[k].nex)
		if(e[k].to^fath) dfs2(e[k].to,x,v);
}
int asklca(int x,int y)
{
	if(deep[x]<deep[y]) std::swap(x,y);
	for(int j=19;~j;j--) if(deep[x]-(1<<j)>=deep[y]) x=fa[x][j];
	if(x==y) return x;
	for(int j=19;~j;j--) if(fa[x][j]^fa[y][j]) x=fa[x][j],y=fa[y][j];
	return fa[x][0];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]),so[i]=A[i];
	for(int i=1;i<n;i++) scanf("%d%d",&a,&b),adde(a,b),adde(b,a);
	std::sort(so+1,so+1+n),tot=std::unique(so+1,so+1+n)-so-1;
	for(int i=1;i<=n;i++) A[i]=lb(A[i]),S[A[i]].pb(i),Sum[A[i]]++;
	dfs1(1);
	if(flag) return puts("0"),0;
	for(int j=1;j<20;j++)
		for(int i=1;i<=n;i++) fa[i][j]=fa[fa[i][j-1]][j-1];
	for(int i=1,x,y,LCA;i<=tot;i++) if(Sum[i]>1)
	{
		std::sort(S[i].begin(),S[i].end(),[](int t1,int t2){return dfn[t1]<dfn[t2];});
		x=S[i][0],y=S[i][Sum[i]-1],LCA=asklca(x,y);
		if(LCA==x)
		{
			for(int k=last[x];k;k=e[k].nex)
				if(e[k].to^fa[x][0]&&mark2[e[k].to]) mark[e[k].to]++;
			for(int j:S[i]) if(j^x) mark[j]--;
			continue;
		}
		mark[1]++;
		for(int j:S[i]) mark[j]--;
	}
	tot=0;
	for(int i=1;i<=n;i++) if(Sum[i]>1) tot++;
	dfs2(1,0,0);
	printf("%d\n",ans);
	return 0;
}