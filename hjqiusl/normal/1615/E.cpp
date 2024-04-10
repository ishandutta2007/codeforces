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
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
vector<int>G[N];
int dis[N];
int a[N];
int n,m;
int cnt;
void ad(int x,int y)
{
	G[x].push_back(y);
}
void dfs(int k,int fa)
{
	int lst=0;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		if (!lst)
		{
			lst=u;
		} else
		{
			if (dis[lst]<dis[u])
			{
				a[++cnt]=dis[lst];
				lst=u;
			} else
			{
				a[++cnt]=dis[u];
			}
		}
	}
	dis[k]=dis[lst]+1;
	// cout<<k<<","<<dis[k]<<endl;
}
int gt(int i,int j,int x)
{
	return j*((x+a[i])-j+i-1-(n-j-((x+a[i])-j+i-1)));
}
void BellaKira()
{
	n=read();m=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		ad(x,y);
		ad(y,x);
	}
	dfs(1,0);
	a[++cnt]=dis[1];
	sort(a+1,a+cnt+1,greater<int>());
	int x=0,y=0;
	int ans=-inf;
	for (int i=1;i<=m;i++)
	{
		x+=a[i];
		if (-(n-x)+i>0) ans=max(ans,(n-i-(n-x))*(i-(n-x)));
		else
		{
			int k=min(n/2,n-x);
			ans=max(ans,(n-i-k)*(i-k));
		}
	}
	// sort(a+1,a+cnt+1);
	// x=0,y=0;
	// // ans=-inf;
	// for (int i=1;i<=cnt;i++)
	// {
		// // int o=(x+a[i])-j+i-1;
		// int l=max(0ll,x+a[i]+i-1-m),r=x+a[i]-1;
		// while (l<=r)
		// {
			// int mid=l+(r-l)/3,mid1=r-(r-l)/3;
			// if (gt(i,mid,x)<=gt(i,mid1,x))
			// {
				// cout<<"?"<<i<<","<<x<<" "<<gt(i,mid1,x)<<" "<<mid1<<endl;
				// ans=max(ans,gt(i,mid1,x));
				// r=mid1-1;
			// } else
			// {
				// cout<<"?"<<i<<" "<<x<<" "<<gt(i,mid,x)<<endl;
				// ans=max(ans,gt(i,mid,x));
				// l=mid+1;
			// }
		// }
		// x+=a[i]-1;
	// }
	writeln(ans);
		
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