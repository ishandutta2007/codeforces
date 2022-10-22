//The Hunting Party - Keys To The Kingdom
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
#define N 205
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,x;
set<int>G[N],G1[N];
vector<int>E[N],E1[N];
int ans[N];
int chs[N];
int vis[N];
void LYC_music()
{
	int bl=0;
	int rt=0,rt1=0;
	n=read();
	for (int i=1;i<n;i++)
	{
		x=read();
		for (int j=1;j<=x;j++)
		{
			int y=read();
			G[y].insert(i);
			G1[y].insert(i);
			E[i].push_back(y);
			E1[i].push_back(y);
		}
	}
	for (int i=1;i<=n;i++)
		if (G[i].size()==1)
		{
			if (rt) rt1=i;
			else rt=i;
		}
	for (int i=n;i>=1;i--)
	{
		x=0;
		for (int j=1;j<=n;j++)
		{
			if (!vis[j]&&(j==rt&&i==n||i!=n&&(chs[j]>chs[x]||chs[j]==chs[x]&&G[j].size()==1))) x=j;
//			cout<<j<<" "<<chs[j]<<endl;
		}
		vis[x]=1;
		ans[i]=x;
//		cout<<"?"<<i<<" "<<x<<endl;
		if (G[x].size()>1||x==0)
		{
			bl=1;
			break;
		}
		if (i==1) break;
		int mx=0,nowmx=0;
		for (auto u:G[x])
		{
			if (E[u].size()>mx)
			{
				mx=E[u].size();
				nowmx=u;
			}
		}
		int u=nowmx;
			for (auto v:E[u])
			{
				if (v!=x) 
				{
					G[v].erase(u);
					chs[v]=max(chs[v],i-(int)E[u].size()+1);
				}
			}
		G[x].clear();
	}
	if (bl==1)
	{
//		cout<<"?"<<rt<<" "<<rt1<<endl; 
		for (int i=1;i<=n;i++) swap(G[i],G1[i]),swap(E[i],E1[i]),vis[i]=0,chs[i]=0;
		for (int i=n;i>=1;i--)
		{
			x=0;
			for (int j=1;j<=n;j++)
			{
				if (!vis[j]&&(j==rt1&&i==n||i!=n&&(chs[j]>chs[x]||chs[j]==chs[x]&&G[j].size()==1))) x=j;
			}
			vis[x]=1;
			ans[i]=x;
			if (G[x].size()!=1)
			{
				bl=1;
				break;
			}
			if (i==1) break;
			int mx=0,nowmx=0;
			for (auto u:G[x])
			{
				if (E[u].size()>mx)
				{
					mx=E[u].size();
					nowmx=u;
				}
			}
			int u=nowmx;
				for (auto v:E[u])
				{
					if (v!=x) 
					{
						G[v].erase(u);
						chs[v]=max(chs[v],i-(int)E[u].size()+1);
					}
				}
			G[x].clear();
		}
	}
	for (int i=1;i<=n;i++) writesp(ans[i]),G[i].clear(),E[i].clear(),vis[i]=0,chs[i]=0,G1[i].clear(),E1[i].clear();
	puts("");
}
signed main()
{
	int T=read();
	while (T--)
	{
		LYC_music();
	}
}
/*
1
5
3 2 3 4
2 3 5
4 1 2 3 4
2 2 3
*/