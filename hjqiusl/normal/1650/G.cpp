//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 1000000007
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,s,t;
poly G[N];
int vis[N],f[N][2];
int vis1[N];
void BellaKira()
{
	n=read(),m=read();
	s=read(),t=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	queue<int>q;
	q.push(s);
	vis[s]=1;
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		for (auto v:G[u])
		{
			if (!vis[v]) vis[v]=vis[u]+1,q.push(v);
		}
	}
	
	
	q.push(s);
	vis1[s]=1;
	f[s][0]=1;
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		for (auto v:G[u])
		{
			if (!vis1[v]) vis1[v]=1,q.push(v);
			{
				for (int i=0;i<=0;i++)
					for (int j=0;j<=0;j++)
						if (vis[u]+i+1==vis[v]+j)
						{
							f[v][j]=(f[v][j]+f[u][i])%mod;
						}
			}
		}
	}
	for (int i=1;i<=n;i++) vis1[i]=0;
	
	q.push(s);
	vis1[s]=1;
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		for (auto v:G[u])
		{
			if (!vis1[v]) vis1[v]=1,q.push(v);
			{
				for (int i=0;i<=0;i++)
					for (int j=1;j<=1;j++)
						if (vis[u]+i+1==vis[v]+j)
						{
							f[v][j]=(f[v][j]+f[u][i])%mod;
						}
			}
		}
	}
	for (int i=1;i<=n;i++) vis1[i]=0;
	
	
	q.push(s);
	vis1[s]=1;
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		for (auto v:G[u])
		{
			if (!vis1[v]) vis1[v]=1,q.push(v);
			{
				for (int i=1;i<=1;i++)
					for (int j=1;j<=1;j++)
						if (vis[u]+i+1==vis[v]+j)
						{
							f[v][j]=(f[v][j]+f[u][i])%mod;
						}
			}
		}
	}
	for (int i=1;i<=n;i++) vis1[i]=0;
	
	
	
	// for (int i=1;i<=n;i++)	
		// cout<<f[i][0]<<" "<<f[i][1]<<endl;
		
	writeln((f[t][1]+f[t][0])%mod);
	for (int i=1;i<=n;i++) f[i][0]=f[i][1]=vis[i]=vis1[i]=0,G[i].clear();
		
}
signed main()
{
	int T=read();
	while (T--)
	{
		BellaKira();
	}
}