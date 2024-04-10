#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
#define gc (c=getchar())
char getc()
{
	char c;
	while(gc<'0');
	return c;
}
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
const int inf=1e9+5;
const int N=1e5+5;
int n,w[N];
namespace TREE
{
const int N=2e5+5;
int n;
vector<int>lk[N];
int fa[N],deep[N],sz[N],son[N],top[N],dfn[N];
struct HEAP
{
priority_queue<int,vector<int>,greater<int> >a,b;
void push(int x)
{
	a.push(x);
}
void del(int x)
{
	b.push(x);
}
int top()
{
	while(!b.empty()&&a.top()==b.top()){a.pop();b.pop();}
	return a.top();
}
};
HEAP heap[N]; 
void add_e(int y,int x)
{
	lk[y].pb(x);
}
int ans;
namespace SEG
{
#define mid (l+r>>1)
#define cl (k*2)
#define cr (cl+1)
#define in (ql<=l&&qr>=r)
#define out (ql>r||qr<l)
int mn[N*4];
void modify(int i,int w)
{
	int k=1,l=1,r=n;
	while(l!=r)
	if(i<=mid){k=cl;r=mid;}
	else{k=cr;l=mid+1;}
	if(mn[k]==w)return ;
	mn[k]=w;
	while(k>>=1)mn[k]=min(mn[cl],mn[cr]);
}
int ql,qr;
void qiu(int k,int l,int r)
{
	if(in){chmin(ans,mn[k]);return ;}
	if(out)return ;
	qiu(cl,l,mid);qiu(cr,mid+1,r);
}
void qiu(int l,int r)
{
	ql=l;qr=r;
	qiu(1,1,n);
}
};
int tot;
namespace DFS1
{
void dfs(int x)
{
	sz[x]=1;
	for(auto y:lk[x])
	{
		fa[y]=x;
		deep[y]=deep[x]+1;
		dfs(y);
		sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
};
namespace DFS2
{
void dfs(int x,int ntop)
{
	top[x]=ntop;dfn[x]=++tot;
	if(!son[x])return ;
	dfs(son[x],ntop);
	for(auto y:lk[x])
	if(y!=son[x])dfs(y,y);
}
};
void init()
{
	DFS1::dfs(1);
	DFS2::dfs(1,1);
}
void modify(int x,int w0,int w1)
{
	SEG::modify(dfn[x],w1);
	if(!fa[x])return ;
	if(w0!=-1)heap[fa[x]].del(w0);
	heap[fa[x]].push(w1);
	SEG::modify(dfn[fa[x]],heap[fa[x]].top());
}
#define fx top[x]
#define fy top[y]
int qiu(int x,int y)
{
	ans=inf;
	while(fx!=fy)
	{
		if(deep[fx]<deep[fy])swap(x,y);
		SEG::qiu(dfn[fx],dfn[x]);
		x=fa[fx];
	}
	if(deep[x]>deep[y])swap(x,y);
	SEG::qiu(dfn[x],dfn[y]);
	if(x>::n)chmin(ans,::w[fa[x]]);
	return ans;
}
};
namespace GRAGH
{
int m;
vector<int>lk[N];
int dfn[N],low[N],tot;
int st[N],top;
void dfs(int x,int fr)
{
	dfn[x]=low[x]=++tot;
	st[++top]=x;
	for(auto y:lk[x])
	{
		if(y==fr)continue;
		if(dfn[y])
		{
			chmin(low[x],dfn[y]);
			continue;
		}
		dfs(y,x);
		chmin(low[x],low[y]);
		if(low[y]>=dfn[x])
		{
			++TREE::n;
			TREE::add_e(x,TREE::n);
			while(1)
			{
				int i=st[top--];
				TREE::add_e(TREE::n,i);
				if(i==y)break;
			}
		}
	}
}
void init()
{
	rep(i,1,n)scanf("%d",w+i);
	rep(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		lk[x].pb(y);lk[y].pb(x);
	}
	TREE::n=n;
	dfs(1,0);
	TREE::init();
	rep(i,1,n)TREE::modify(i,-1,w[i]); 
}
};

int main()
{
	//freopen("1.in","r",stdin);
	int q;
	scanf("%d%d%d",&n,&GRAGH::m,&q);
	GRAGH::init();
	while(q--)
	if(getc()=='C')
	{
		int x,w;
		scanf("%d%d",&x,&w);
		TREE::modify(x,::w[x],w);
		::w[x]=w;
	}
	else
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",TREE::qiu(x,y));
	}
}