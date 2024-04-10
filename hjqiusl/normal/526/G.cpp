//~
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
//#define int ll
#define N 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m;
struct Tree
{
	int ffa[N],s[N],S[N];
	int P[N],col[N];
	int st[N][25];
	pa p[N];
	int sdp[N];
	int ffa1[N];
	vector<pa>G[N];
	int ss[N];
	vector<int>L[N];
	int unif[N],yez[N];
	int rt;
	int cnt;
	#define gtop(x) ((L[x][0]))
	#define gend(x) ((L[x].back()))
	#define sum(x) ((s[gtop(x)])+ffa1[gtop(x)])
	void ad(int x,int y,int w)
	{
		G[x].push_back(mp(y,w));
		G[y].push_back(mp(x,w));
	}
	pa getfar(int k,int fa)
	{
		pa res=mp(k,0);
		for (auto U:G[k])
		{
			int u=U.fi,w=U.se;
			if (u==fa) continue;
			pa now=getfar(u,k);
			now.se+=w;
			if (now.se>res.se) res=now;
		}
		return res;
	}
	void dfs(int k,int fa)
	{
		ffa[k]=fa;
		st[k][0]=fa;
		for (int i=1;i<=20;i++)
			st[k][i]=st[st[k][i-1]][i-1];
		int now=0;
		s[k]=0;
		for (auto U:G[k])
		{
			int u=U.fi,w=U.se;
			if (u==fa) continue;
			sdp[u]=sdp[k]+w;
			dfs(u,k);
			if (s[u]+w>s[k])
			{
				now=u;
				s[k]=s[u]+w;
			}
			ffa1[u]=w;
		}
		if (now) unif[now]=k;
		else yez[k]=1;
	}
	void work(int x,int nowc)
	{
		col[x]=nowc;
		if (x!=unif[x]) work(unif[x],nowc);
		L[nowc].push_back(x);
	}
	int getrt(int x)
	{
		rt=getfar(x,0).fi;
		for (int i=1;i<=n;i++) unif[i]=i;
		dfs(rt,0);
		for (int i=1;i<=n;i++)
			if (yez[i])
			{
				work(i,++cnt);
			}
		for (int i=1;i<=cnt;i++) p[i].fi=-sum(i),p[i].se=i,ss[p[i].se]=sum(p[i].se);
		sort(p+1,p+cnt+1);
		for (int i=1;i<=cnt;i++) P[p[i].se]=i;
		for (int i=1;i<=cnt;i++) S[i]=S[i-1]+ss[p[i].se];
		return rt;
	}
	int query(int x,int y)
	{
		y=2*y-1;
		y=min(y,cnt);
		// cout<<"???"<<P[col[x]]<<endl;
		if (P[col[x]]<=y) return S[y];
		int now=x;
		int nowc=col[x];
		for (int i=20;i>=0;i--)
			if (st[now][i]&&P[col[st[now][i]]]>y) now=st[now][i];
		int ans=S[y]-s[ffa[now]]+sdp[gend(nowc)]-sdp[ffa[now]];
		y--;
		now=x;
		for (int i=20;i>=0;i--)
			if (st[now][i]&&P[col[st[now][i]]]>y) now=st[now][i];
		return max(ans,S[y]+sdp[gend(nowc)]-sdp[ffa[now]]);
	}
}T1,T2;	
void BellaKira()
{
	n=read(),m=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read(),w=read();
		T1.ad(x,y,w);
		T2.ad(y,x,w);
	}T1.getrt(1);
	T2.getrt(T1.rt);
	// return;
	ll ans=0;
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		x=(x+ans-1)%n+1;
		y=(y+ans-1)%n+1;
		ans=max(T1.query(x,y),T2.query(x,y));
		writeln(ans);
	}
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