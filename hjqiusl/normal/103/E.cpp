//~~
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
const int inf = 0x3fffffff;
#define mod 998244353
#define int ll
#define N 705
#define M 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
struct Graph_Dinic
{
	int q[N<<2],l,r,dis[N],cur[N],head[N],S,T,mch[N],cnt=1,ans,now;
	struct
	{
		int to,nx,val;
	}e[M<<1];
	inline void ad(int x,int y,int val)
	{
		e[++cnt].to=y,e[cnt].nx=head[x],e[cnt].val=val;head[x]=cnt;
		e[++cnt].to=x,e[cnt].nx=head[y],e[cnt].val=0;head[y]=cnt;
	}
	inline bool bfs()
	{
		l=0,r=1;
		q[++l]=S;
		memset(dis,-1,sizeof(dis));
		dis[S]=0;
		memcpy(cur,head,sizeof(head));
		while (l<=r)
		{
			now=q[l];
			l++;
			for (int i=head[now];i;i=e[i].nx)
			{
				if (dis[e[i].to]==-1&&e[i].val!=0)
				{
					dis[e[i].to]=dis[now]+1;
					q[++r]=e[i].to;
					if (e[i].to==T) return 1;
				}
			}
		}
		return 0;
	}
	inline int dfs(int now,int liu)
	{
		if (now==T||!liu)
		{
			return liu;
		}
		int res=liu;
		for (int i=cur[now];i&&res;i=e[i].nx)
		{
			cur[now]=i;
			if (dis[e[i].to]==dis[now]+1&&e[i].val!=0)
			{
				int c=dfs(e[i].to,min(res,e[i].val));
				res-=c;
				e[i].val-=c;
				e[i^1].val+=c;
				if (c!=0&&e[i].to!=T&&now!=S)
				{
					mch[now]=e[i].to;
					mch[e[i].to]=now;
				}
			}
		}
		return liu-res;
	}
	inline void dinic()
	{
		while (bfs())
			ans+=dfs(S,inf);
	}
}G;
int n,nod,id[N][2];
int w[N];
vector<int>P[N];
int ans;
void BellaKira()
{
	n=read();
	G.S=++nod;
	G.T=++nod;
	for (int i=1;i<=n;i++) id[i][0]=++nod,id[i][1]=++nod;
	for (int i=1;i<=n;i++)
	{
		int x=read();
		while (x--)
		{
			int y=read();
			P[i].push_back(y);
		}
	}
	for (int i=1;i<=n;i++) w[i]=-read(),ans+=w[i],G.ad(G.S,id[i][0],inf+w[i]),G.ad(id[i][1],G.T,inf);
	for (int i=1;i<=n;i++)
		for (auto u:P[i]) G.ad(id[i][0],id[u][1],inf);
	G.dinic();
	ans-=G.ans-inf*n;
//	writeln(G.ans);
	writeln(-ans);
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/