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
int n;
poly G[3000005];
int a[N];
int q;
int cnt;
int id[3000005][2];	
int query(int x,int l,int r)
{
	return upper_bound(G[x].begin(),G[x].end(),r)-G[x].begin()-(lower_bound(G[x].begin(),G[x].end(),l)-G[x].begin());
}
void BellaKira()
{
	n=read();
	cnt=1;
	for (int i=1;i<=n;i++)
	{
		int x=read();
		a[i]=x;
		int now=1;
		for (int j=30;j>=0;j--)
			if ((x>>j)&1)
			{
				int lst=now;
				now=id[now][1];
				if (!now) now=++cnt,id[lst][1]=now;
				G[now].push_back(i);
			} else
			{
				int lst=now;
				now=id[now][0];
				if (!now) now=++cnt,id[lst][0]=now;
				G[now].push_back(i);
			}		
	}
	q=read();
	for (int i=1;i<=q;i++)
	{
		int l=read(),r=read();
		int now=1;
		int ans=0;
		poly g;
		for (int j=30;j>=0;j--)
		{
			// cout<<j<<" "<<now<<" "<<g.size()<<endl;
			int x=0,y=0;
			if (now)
			{
				if (query(id[now][0],l,r)==1)
				{
					int x=id[now][0];
					int inss=0;
					inss=G[x][lower_bound(G[x].begin(),G[x].end(),l)-G[x].begin()];
					g.push_back(inss);
				} else
				if (query(id[now][0],l,r)>=2)
				{
					poly g1;
					for (auto u:g)
					{
						if ((a[u]>>j)%2==0) g1.push_back(u);
					}
					swap(g,g1);
					now=id[now][0];
					continue;
				}
			}
			for (auto u:g)
			{
				if ((a[u]>>j)%2==0) x++;
			}
			// if (g.size())
			// cout<<"?"<<x<<" "<<a[g[0]]<<" "<.<g[0]<<endl;
			if (x<=1)
			{
				now=id[now][1];
				ans+=(1<<j);
				continue;
			}
			poly g1;
			for (auto u:g)
			{
				if ((a[u]>>j)%2==0) g1.push_back(u);
			}
			swap(g,g1);
			now=0;
		}
		writeln(ans);
	}
	for (int i=1;i<=cnt;i++) G[i].clear(),id[i][0]=id[i][1]=0;
	cnt=0;
	
}
signed main()
{
	int T=read();
	while (T--)
	{
		BellaKira();
	}
}
/*

*/