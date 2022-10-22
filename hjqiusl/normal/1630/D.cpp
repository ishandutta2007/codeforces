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
#define inf 2e9
#define mod 998244353
#define int ll
#define N 1000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,a[N],ans,b[N];
vector<int>G1[N];
int G[N];
int ans1;
void BellaKira()
{
	n=read();m=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		ans+=a[i]>0?a[i]:-a[i];
	}
	ans1=ans;
	for (int i=1;i<=m;i++)
	{
		b[i]=__gcd(b[i-1],read());
	}
	for (int i=1;i<=n;i++)
	{
		if (a[i]<0)
		{
			G[i%b[m]]++;
		}
		G1[i%b[m]].push_back(abs(a[i]));
	}
	for (int i=0;i<b[m];i++)
	{
		sort(G1[i].begin(),G1[i].end());
		G1[i].push_back(inf);
		if (G[i]%2==1)
		{
			ans-=G1[i][0]*2;
		} else 
		{
			ans1-=G1[i][0]*2;
		}
		// if (G[i].size())
		// cout<<i<<" "<<G[i].back()<<endl;
		G[i]=0;
		G1[i].clear();
	}
	// cout<<ans<<" "<<ans1<<endl;
	writeln(max(ans,ans1));
	ans=0;
		
		
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