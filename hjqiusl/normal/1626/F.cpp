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
// #define int ll
#define N 10000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N];
int x,y,K,M;
int pw[1005];
int dp[20000005];
int g[20000005];
int ans;
#define ad(x,y) (x=((x+y>=mod)?x+y-mod:x+y))
// void ad(int &x,int y)
// {
	// // x=(x+y)%mod;
	// // return;
	// if (x+y>=mod) x=(x+y-mod);
	// else x=x+y;
// }
ll quickPower(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if(y&1)res=1ll*res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
void BellaKira()
{
	n=read();
	a[1]=read();
	x=read(),y=read(),K=read(),M=read();
	int lcm=1;
	for (int i=2;i<=K;i++)
		lcm=1ll*lcm/__gcd(lcm,i)*i;
	pw[0]=1;
	for (int i=1;i<=K;i++)
		pw[i]=1ll*pw[i-1]*n%mod;
	for (int i=1;i<=n;i++)
	{
		if (i>1) a[i]=(1ll*a[i-1]*x+y)%M;
	}
	for (int i=1;i<=n;i++)
	{
		// cout<<i<<" "<<a[i]<<" "<<lcm<<" "<<<<endl;
		ad(ans,1ll*(a[i]/lcm)*pw[K-1]%mod*K%mod*lcm%mod);
		a[i]%=lcm;
		dp[a[i]]++;
		dp[a[i]]%=mod;
		// cout<<i<<" "<<a[i]<<" "<<lcm<<endl;
	}
	for (int i=1;i<=K;i++)
	{
		for (int j=0;j<lcm;j++)
		{
			ad(g[(j-(j%i))],dp[j]);
			ad(ans,1ll*dp[j]*pw[K-i]%mod*j%mod);
			ad(g[j],1ll*dp[j]*(n-1)%mod);
		}
		for (int j=0;j<lcm;j++)
		{
			dp[j]=g[j],g[j]=0;
		}
	}
	// ans=1ll*ans*quickPower(pw[K],mod-2)%mod;
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