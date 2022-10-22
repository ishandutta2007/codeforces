//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,w[N];
pa E[N];
int du[N];
set<pa>S;
queue<int>q;
int del[N];
vector<int>ans;
vector<pa>G[N];
int cnt;
bool cmp(pa x,pa y)
{
	return ((w[x.fi]-du[x.fi])^(w[y.fi]-du[y.fi]))?(w[x.fi]-du[x.fi])<(w[y.fi]-du[y.fi]):w[x.fi]<w[y.fi];
}
signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) w[i]=read();
	for (int i=1;i<=m;i++)
	{
		E[i].fi=read(),E[i].se=read();
		du[E[i].fi]++,du[E[i].se]++;
		G[E[i].fi].push_back({E[i].se,i});
		G[E[i].se].push_back({E[i].fi,i});
	}
	for (int i=1;i<=n;i++)
		if (w[i]-du[i]>=0)
		{
			q.push(i);
		}
	while (!q.empty())
	{
		int i=q.front();
		q.pop();
		for (auto U:G[i])
		{
			int u=U.fi,id=U.se;
			if (del[id]) continue;
			del[id]=1;
			ans.push_back(id);
			++cnt;
			--du[u];
			if (w[u]==du[u]) q.push(u);
		}
	}
	if (cnt!=m)
	{
		return puts("DEAD"),0;
	}
	puts("ALIVE");
	for (int i=ans.size()-1;i>=0;i--) writesp(ans[i]);
}
/*

*/