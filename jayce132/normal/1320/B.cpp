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
	int s=0,f=1; char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=2e5+20;

int n,m;
vector<int>ed[maxn];
int dis[maxn],f[maxn];

int st[maxn],top;

inline void init()
{
	n=read();m=read();
	REP(i,1,m)
	{
		int x=read(),y=read();
		ed[y].push_back(x);
	}
	top=read();
	REP(i,1,top)st[i]=read();
	queue<int>q;
	q.push(st[top]);
	dis[st[top]]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v:ed[u])
		{
			if(!dis[v])dis[v]=dis[u]+1,f[v]++,q.push(v);
			else if(dis[v]==dis[u]+1)f[v]++;
		}
	}
}

inline void doing()
{
	int mn=0,mx=0;
	REP(i,1,top-1)
	{
		int a=st[i],b=st[i+1];
		if(dis[a]==dis[b]+1)
		{
			if(f[a]>1)mx++;
		}else mn++,mx++;
	}
	printf("%d %d\n",mn,mx);
}

int main()
{
	init();
	doing();
	return 0;
}