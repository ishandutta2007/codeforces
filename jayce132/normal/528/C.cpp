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

const int maxn=4e5+20;

int n,m;

struct node {
	int v,next,from;
};
node e[maxn<<1];
int cnt=1,start[maxn];
inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u],u};start[u]=cnt;} 
int rd[maxn];

inline void init()
{
	n=read();m=read();
	REP(i,1,m)
	{
		int u=read(),v=read();
		addedge(u,v);addedge(v,u);
		rd[u]++;rd[v]++;
	}
	int lst=0;
	REP(i,1,n)
	{
		if(rd[i]&1)
		{
			if(!lst)lst=i;
			else addedge(lst,i),addedge(i,lst),rd[lst]++,rd[i]++,lst=0;
		}
	}
}

int cur[maxn];
int st[maxn],top,vis[maxn];

void dfs(int u)
{
	for(int &i=cur[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(vis[i>>1])continue;
		vis[i>>1]=1;
		int id=i;
		dfs(v);
		st[++top]=id;
	}
}
	
inline void doing()
{
	memcpy(cur,start,sizeof(int)*(n+1));
	dfs(1);
	reverse(st+1,st+top+1);
	if(top&1)
	{
		int v=e[st[top]].v;
		++top;st[top]=top<<1;
		e[top<<1]=e[top<<1|1]=(node){v,v,v};
	}
	printf("%d\n",top);
	REP(i,1,top)
	{
		printf("%d %d\n",e[st[i]^(~i&1)].from,e[st[i]^(~i&1)].v);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}