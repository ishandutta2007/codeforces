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

int n;
int a[maxn],b[maxn];
vector<int>ed[maxn];
int col[maxn];

inline void init()
{
	n=read();
	REP(i,1,n)a[i]=read(),b[i]=read(),ed[a[i]].push_back(b[i]),ed[b[i]].push_back(a[i]);
	REP(i,1,n)ed[2*i].push_back(2*i-1),ed[2*i-1].push_back(2*i);
}

void dfs(int u)
{
	for(int v:ed[u])
	{
		if(col[v]==-1)
		{
			col[v]=col[u]^1;
			dfs(v);
		}
	}
}

inline void doing()
{
	memset(col,-1,sizeof(col));
	REP(i,1,2*n)if(col[i]==-1)col[i]=0,dfs(i);
	REP(i,1,n)printf("%d %d\n",col[a[i]]+1,col[b[i]]+1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("742E.in","r",stdin);
	freopen("742E.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}