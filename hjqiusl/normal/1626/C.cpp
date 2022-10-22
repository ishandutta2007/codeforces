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
//#define N
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[100005],b[100005];
int dp[100005];
void BellaKira()
{
	n=read();
	int ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=1;i<=n;i++) dp[i]=inf;
	dp[0]=0;
	for (int i=0;i<=n;i++)
	{
		int x=-1;
		for (int j=i+1;j<=n;j++)
		{
			if (x==-1)
			{
				// cout<<"??"<<j<<" "<<a[j]-a[j-1]<<" "<<b[j]<<endl;
				if (a[j]-a[j-1]<b[j]) break;
				x=b[j];
			}
			else
			{
				if (x+(a[j]-a[j-1])<b[j])
				{
					x=b[j];
				}
				else x+=(a[j]-a[j-1]);
			}
			if (a[j]-a[i]<x) break;
			dp[j]=min(dp[j],dp[i]+(1+x)*x/2);
			// cout<<i<<" "<<j<<" "<<dp[j]<<" "<<x<<endl;
		}
	}
	writeln(dp[n]);
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