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
#define N 300005
#define ll long long
#define ull unsigned ll
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,a,b,c,d,ecnt,last[N],A[N],fa[N][20],deep[N];ull val1[N],val2[N];
struct road{int to,nex;}e[N<<1];
void adde(int u,int v) {e[++ecnt]=(road){v,last[u]},last[u]=ecnt;}
ull rd() {return (((ull)rand())<<8)^rand();}
class PresidentTree
{
#define lc t[x].ls
#define rc t[x].rs
#define mid ((l+r)>>1)
	struct node{int ls,rs;ull v1,v2;}t[N*25];
public:
	int root[N],cntnode;
	void insert(int &x,int y,int l,int r,int p)
	{
		t[x=++cntnode]=t[y],t[x].v1^=val1[p],t[x].v2^=val2[p];
		if(l==r) return;
		p<=mid?insert(lc,t[y].ls,l,mid,p):insert(rc,t[y].rs,mid+1,r,p);
	}
	int ask(int x,int y,int z,int w,int l,int r,int _l,int _r)
	{
		ull v1=t[x].v1^t[y].v1^t[z].v1^t[w].v1,v2=t[x].v2^t[y].v2^t[z].v2^t[w].v2;int res=-1;
		if(!v1&&!v2) return -1;
		if(l==r) return l;
		if(_l<=mid) res=ask(lc,t[y].ls,t[z].ls,t[w].ls,l,mid,_l,_r);
		if(_r>mid&&res<0) res=ask(rc,t[y].rs,t[z].rs,t[w].rs,mid+1,r,_l,_r);
		return res;
	}
}T;
void dfs(int x,int fath=0)
{
	fa[x][0]=fath,deep[x]=deep[fath]+1;
	T.insert(T.root[x],T.root[fath],1,n,A[x]);
	for(int k=last[x];k;k=e[k].nex) if(e[k].to^fath) dfs(e[k].to,x);
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
	srand(123);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]),val1[A[i]]=rd(),val2[A[i]]=rd();
	for(int i=1;i<n;i++) scanf("%d%d",&a,&b),adde(a,b),adde(b,a);
	dfs(1);
	for(int j=1;j<20;j++)
		for(int i=1;i<=n;i++) fa[i][j]=fa[fa[i][j-1]][j-1];
	for(int LCA;m--;)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d),LCA=asklca(a,b);
		printf("%d\n",T.ask(T.root[a],T.root[b],T.root[LCA],T.root[fa[LCA][0]],1,n,c,d));
	}
	return 0;
}