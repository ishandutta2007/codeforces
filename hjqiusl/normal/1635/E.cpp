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
#define inf 1e9
#define mod 998244353
#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int dfn[N],low[N],sta[N],tp;
vector<int>G[N],G2[N];
int P[N];
int L[N],R[N];
vector<int>G1[N],G11[N];
int ins[N];int SCC[N];
int SCC_tot;
int ru[N];
int dfn_Id;
int n,m;
int cnt;
int id[N][2];
mt19937_64 rnd1(time(0));
int rnd(int l,int r)
{
	return rnd1()%(r-l+1)+l;
}
void ad(int x,int y)
{
	G[x].push_back(y);
}
void ad1(int x,int y)
{
	G11[x].push_back(y);
	ru[y]++;
}
void tarjan(int x)
{
	dfn[x]=++dfn_Id;
	low[x]=dfn[x];
	sta[++tp]=x;
	ins[x]=1;
	for (auto u:G[x])
	{
		if (!dfn[u])
		{
			tarjan(u);
			low[x]=min(low[x],low[u]);
		}
		else
			if (ins[u]) low[x]=min(low[x],dfn[u]);
	}
	if (low[x]==dfn[x])
	{
		++SCC_tot;
		while (sta[tp+1]!=x)
		{
			int u=sta[tp];
			ins[u]=0;
			SCC[u]=SCC_tot;
			tp--;
		}
	}
}	
void BellaKira()
{
	n=read();m=read();
	for (int i=1;i<=n;i++)
		for (int j=0;j<2;j++)
			id[i][j]=++cnt;
	for (int i=1;i<=m;i++)
	{
		int opt=read(),x=read(),y=read();
		if (opt==1)
		{
			ad(id[x][1],id[y][0]);
			ad(id[y][1],id[x][0]);
			ad(id[x][0],id[y][1]);
			ad(id[y][0],id[x][1]);
			G2[x].push_back(y);
			G2[y].push_back(x);
		}
		else
		{
			ad(id[x][1],id[y][0]);
			ad(id[y][1],id[x][0]);
			ad(id[x][0],id[y][1]);
			ad(id[y][0],id[x][1]);
			G1[x].push_back(y);
			G1[y].push_back(x);
		}
	}
	for (int i=1;i<=cnt;i++)
		if (!dfn[i]) tarjan(i);
	for (int i=1;i<=n;i++)
	{
		if (SCC[id[i][0]]==SCC[id[i][1]])
		{
			puts("NO");
			exit(0);
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (SCC[id[i][0]]<SCC[id[i][1]])
		{
				for (auto u:G2[i])
				{
					ad1(i,u);
				}
				for (auto u:G1[i])
				{
					ad1(u,i);
				}
		} else
		{
				for (auto u:G2[i])
				{
					ad1(u,i);
				}
				for (auto u:G1[i])
				{
					ad1(i,u);
				}
		}
	}
	queue<int>q;
	int cnt1=0;
	for (int i=1;i<=n;i++)
		if (!ru[i])
		{
			q.push(i);
		}
	while (!q.empty())
	{
		int k=q.front();
		q.pop();
		P[k]=++cnt1;
		for (auto u:G11[k])
		{
			ru[u]--;
			if (!ru[u]) q.push(u);
		}
	}
	for (int i=1;i<=n;i++)
		if (ru[i]) 
		{
			puts("NO");
			exit(0);
		}
	puts("Yes");
	for (int i=1;i<=n;i++)
	{
		if (SCC[id[i][0]]<SCC[id[i][1]]) cout<<"L"<<" "<<P[i]<<endl;
		else cout<<"R "<<P[i]<<endl;
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