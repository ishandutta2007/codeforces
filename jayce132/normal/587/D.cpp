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
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}
inline void myassert(bool a,string s)
{
	if(!a)cerr<<s<<endl,exit(0);
}

const int maxn=8e5+20;

struct node {
	int v,next;
};
node e[maxn<<3];
int cnt,start[maxn],tot=1;
inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}
inline void Addedge(int u,int v){ addedge(u,v); addedge(v^1,u^1);}

struct Edge {
	int u,v,c,w;
};
Edge E[maxn];
vector<int>ed[maxn];

int n,m;

inline void init()
{
	n=read();m=read();
	REP(i,1,m)
	{
		int u=read(),v=read(),c=read(),w=read();
		E[i]=((Edge){u,v,c,w});
		ed[u].push_back(i);
		ed[v].push_back(i);
	}
	REP(i,1,n)sort(ed[i].begin(),ed[i].end(),[](int a,int b){ return E[a].c<E[b].c;});
}

int num[maxn][2];

int dfn[maxn],low[maxn],times,vis[maxn],st[maxn],top;
int id[maxn],COL;

void dfs(int u)
{
	dfn[u]=low[u]=++times; vis[u]=1; st[++top]=u;
	EREP(i,u)
	{
		int v=e[i].v;
		if(!dfn[v])
		{
			dfs(v);
			chkmin(low[u],low[v]);
		}else if(vis[v])chkmin(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		int x;++COL;
		do{
			x=st[top--];
			vis[x]=0;
			id[x]=COL;
		}while(x!=u);
	}
}

inline bool check(int x)
{
	memset(start,0,sizeof(int)*(tot+1));
	cnt=0; tot=1;
	REP(i,1,m)num[i][0]=++tot,num[i][1]=++tot;
	REP(i,1,n)if(SZ(ed[i])>=1)
	{
		int len=SZ(ed[i]);
		vector<int>st=ed[i];
		static int pre[maxn][2],suf[maxn][2];
		REP(j,0,len-1)pre[j][0]=++tot,pre[j][1]=++tot;
		DREP(j,len-1,0)suf[j][0]=++tot,suf[j][1]=++tot;
		REP(j,0,len-1)
		{
			Addedge(pre[j][1],num[st[j]][0]);
			if(j)Addedge(pre[j][1],pre[j-1][1]);
		}
		DREP(j,len-1,0)
		{
			Addedge(suf[j][1],num[st[j]][0]);
			if(j<len-1)Addedge(suf[j][1],suf[j+1][1]);
		}
		REP(j,0,len-1)
		{
			if(j)Addedge(num[st[j]][1],pre[j-1][1]);
			if(j<len-1)Addedge(num[st[j]][1],suf[j+1][1]);
		}
	}
	REP(i,1,n)
	{
		int s=0;
		REP(j,0,SZ(ed[i])-1)
		{
			++s;
			if(j==SZ(ed[i])-1 || E[ed[i][j]].c!=E[ed[i][j+1]].c)
			{
				if(s>=2)
				{
					Addedge(num[ed[i][j]][0],num[ed[i][j-1]][1]);
				}
				s=0;
			}
		}
	}
	REP(i,1,m)if(E[i].w>x)Addedge(num[i][1],num[i][0]);
	memset(dfn,0,sizeof(int)*(tot+1));
	memset(low,0,sizeof(int)*(tot+1)); times=0; COL=0;
	REP(i,1,tot)if(!dfn[i])dfs(i);
	REP(i,1,m)if(id[num[i][0]]==id[num[i][1]])return 0;//cerr<<x<<" "<<i<<endl,0;
	return 1;
}

inline void doing()
{
	REP(i,1,n)
	{
		int s=0;
		REP(j,0,SZ(ed[i])-1)
		{
			++s;
			if(j==SZ(ed[i])-1 || E[ed[i][j]].c!=E[ed[i][j+1]].c)
			{
				if(s>=3)puts("No"),exit(0);
				s=0;
			}
		}
	}
	int l=0,r=1e9+1;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	if(l!=1e9+1)
	{
		puts("Yes");
		vector<int>ans;
		myassert(check(l),"is so fake");
		REP(i,1,m)if(id[num[i][1]]<id[num[i][0]])ans.push_back(i);
		printf("%d %d\n",l,SZ(ans));
		REP(i,0,SZ(ans)-1)printf("%d ",ans[i]);
	}else puts("No");
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF587D.in","r",stdin);
	freopen("CF587D.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}