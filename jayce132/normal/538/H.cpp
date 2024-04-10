#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
	int s=0,f=1; char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=1e6+20;
const int maxs=1e5+20;

vector<int>ed[maxn];

int L,R;
int n,m;
int num[maxs][2],tot;
int l[maxs],r[maxs];

inline void addedge(int x,int y){ ed[x].push_back(y); ed[y^1].push_back(x^1);}

//int ls[maxs],lt,rs[maxs],rt;
int idl[maxs],idr[maxs];

inline void init()
{
	L=read();R=read();
	n=read();m=read();
	tot=1;
	REP(i,1,n)l[i]=read(),r[i]=read(),num[i][0]=++tot,num[i][1]=++tot;
	REP(i,1,n)idl[i]=idr[i]=i;
//REP(i,1,n)ls[++lt]=l[i],rs[++rt]=r[i],idl[i]=idr[i]=i;
	//sort(ls+1,ls+lt+1); lt=unique(ls+1,ls+lt+1)-ls-1;
	//sort(rs+1,rs+rt+1); rt=unique(rs+1,rs+rt+1)-rs-1;
	REP(i,1,m)
	{
		int u=read(),v=read();
		addedge(num[u][0],num[v][1]);
		addedge(num[u][1],num[v][0]);
	}
	sort(idl+1,idl+n+1,[](int a,int b){ return l[a]<l[b];});
	sort(idr+1,idr+n+1,[](int a,int b){ return r[a]<r[b];});
	static int suf0[maxn][2],suf1[maxn][2];// 0:01:1
	static int pre0[maxn][2],pre1[maxn][2];
	DREP(i,n,1)
	{
		suf0[i][0]=++tot; suf0[i][1]=++tot;
		suf1[i][0]=++tot; suf1[i][1]=++tot;
		if(i<n)addedge(suf0[i][0],suf0[i+1][0]),addedge(suf1[i][1],suf1[i+1][1]);
		addedge(suf0[i][0],num[idl[i]][0]),addedge(suf1[i][1],num[idl[i]][1]);
	}
	int j;
	j=n+1;
	REP(i,1,n)
	{
		int u=idl[i];
		while(j>i+1 && l[u]+l[idl[j-1]]>R)--j;
		chkmax(j,i+1);
		if(j<=n)addedge(num[u][0],suf0[j][0]),addedge(num[u][1],suf1[j][1]);
	}

	j=n+1;
	DREP(i,n,1)
	{
		int u=idr[i];
		while(j>1 && r[u]<l[idl[j-1]])j--;
		if(j<=n)addedge(num[u][0],suf1[j][1]),addedge(num[u][1],suf0[j][0]);
	}
	
	REP(i,1,n)
	{
		pre0[i][0]=++tot; pre0[i][1]=++tot;
		pre1[i][0]=++tot; pre1[i][1]=++tot;
		if(i>1)addedge(pre0[i][0],pre0[i-1][0]),addedge(pre1[i][1],pre1[i-1][1]);
		addedge(pre0[i][0],num[idr[i]][0]),addedge(pre1[i][1],num[idr[i]][1]);
	}
	j=0;
	DREP(i,n,1)
	{
		int u=idr[i];
		while(j<i-1 && r[u]+r[idr[j+1]]<L)++j;
		chkmin(j,i-1);
		if(j>0)addedge(num[u][0],pre0[j][0]),addedge(num[u][1],pre1[j][1]);
	}
	j=0;
	REP(i,1,n)
	{
		int u=idl[i];
		while(j<n && r[idr[j+1]]<l[u])j++;
		if(j>0)addedge(num[u][0],pre1[j][0]),addedge(num[u][1],pre1[j][0]);
	}
}

int dfn[maxn],low[maxn],times,id[maxn],COL;
int st[maxn],vis[maxn],top;

void dfs(int u)
{
	
	dfn[u]=low[u]=++times; vis[u]=1; st[++top]=u;
	for(int v:ed[u])
	{
		if(!dfn[v])
		{
			dfs(v);
			chkmin(low[u],low[v]);
		}else if(vis[v])chkmin(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		int x; ++COL;
		do{
			x=st[top--];
			vis[x]=0;
			id[x]=COL;
		}while(x!=u);
	}
}

const int inf=0x3f3f3f3f;

int ans[maxs];

inline void doing()
{
	REP(i,2,tot)if(!dfn[i])dfs(i);
	REP(i,1,n)if(id[num[i][0]]==id[num[i][1]])return puts("IMPOSSIBLE"),void();
	int L1=0,R1=inf,L2=0,R2=inf;
	int LL,RR;
	REP(i,1,n)if(id[num[i][0]]<id[num[i][1]])
	{
		ans[i]=1; //id;
		chkmax(L1,l[i]);
		chkmin(R1,r[i]);
	}else
	{
		ans[i]=2;
		chkmax(L2,l[i]);
		chkmin(R2,r[i]);
	}
	LL=L1+L2; RR=R1+R2;
	if(LL>R || RR<L)puts("IMPOSSIBLE"),exit(0);
	puts("POSSIBLE");
	int all=max(LL,L),n1=max(L1,all-R2),n2=all-n1;
	printf("%d %d\n",n1,n2);
	REP(i,1,n)printf("%d",ans[i]);
}

int main()
{
#ifndef ONLINE_JUDGE	
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}