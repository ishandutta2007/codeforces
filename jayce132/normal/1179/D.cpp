#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=5e5+20;

struct node {
	int v,next;
};
node e[maxn<<1];
int cnt,start[maxn];
inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}

int n;

inline void init()
{
	n=read();
	REP(i,1,n-1)
	{
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
}

int sz[maxn];
void get_sz(int u,int fa){ sz[u]=1; EREP(i,u)if(e[i].v!=fa)get_sz(e[i].v,u),sz[u]+=sz[e[i].v];}

ll ans[maxn];

void dfs(int u,int fa)
{
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		ans[v]=ans[u]+(ll)(sz[u]-sz[v])*sz[v];
		dfs(v,u);
	}
}
	
inline void doing()
{
	get_sz(1,0);
	ans[1]=(ll)n*(n-1)>>1;dfs(1,0);

	int u=2;
	REP(i,3,n)if(ans[u]<ans[i]){u=i;}
	get_sz(u,0);
	ans[u]=(ll)n*(n-1)>>1;dfs(u,0);
	ll t=0;
	REP(i,1,n)chkmax(t,ans[i]);
	printf("%lld\n",t);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}