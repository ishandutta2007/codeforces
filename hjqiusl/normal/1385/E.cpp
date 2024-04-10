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
#define N 500005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
pa E[N];
int T,n,m;
int b[N],ru[N],tp[N];
int ID;
vector<int>G[N];
void ad(int x,int y)
{
	G[x].push_back(y);
	ru[y]++;
}
void LYC_music()
{
	T=read();
	while (T--)
	{
		n=read(),m=read();
		for (int i=1;i<=m;i++)
		{
			int opt=read(),x=read(),y=read();
			E[i]=mp(x,y);
			if (opt==1)
			{
				ad(x,y);
			} else
			{
				b[i]=1;
			}
		}
		queue<int>q;
		for (int i=1;i<=n;i++)
			if (!ru[i])
			{
				q.push(i);
			}
		while (!q.empty())
		{
			int u=q.front();
//			cout<<"?"<<u<<endl;
			tp[u]=++ID;
			q.pop();
			for (auto v:G[u])
			{
				ru[v]--;
				if (!ru[v]) q.push(v);
			}
		}
		int ans=1;
		for (int i=1;i<=n;i++)
			if (!tp[i])
			{
//				cout<<"?"<<i<<" "<<tp[i]<<endl;
				ans=0;
				break;
			}
		if (ans)
		{
			puts("YES");
			for (int i=1;i<=m;i++)
				if (!b[i]) writesp(E[i].fi),writeln(E[i].se);
				else
				{
					if (tp[E[i].fi]>tp[E[i].se]) swap(E[i].fi,E[i].se);
					writesp(E[i].fi),writeln(E[i].se);
				}
		}
		else
		{
			puts("NO");
		}
		for (int i=1;i<=n;i++)
			vector<int>().swap(G[i]),ru[i]=0,tp[i]=0;
		for (int i=1;i<=m;i++) b[i]=0;
		ID=0;
	}
}
signed main()
{
	int T=1;
	while (T--)
	{
		LYC_music();
	}
}
/*

*/