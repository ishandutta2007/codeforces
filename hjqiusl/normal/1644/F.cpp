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
int mu[N],pr[N],cnt;
int n,m,fac[N],inv[N];
int ans;
int vis[N];
int a[N];
int b[N];
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int calc(int x,int y)
{
	y=min(y,x);
	for (int i=0;i<=y;i++)
	{
		b[i]=quickPower(i,x);
		b[i]=b[i]*inv[i]%mod;
		if (i>0) b[i]=(b[i-1]+b[i])%mod;
	}
	int res=0;
	for (int i=0;i<=y;i++)
		res=(res+a[i]*b[y-i]%mod)%mod;
	return res;
}
void BellaKira()
{
	n=read(),m=read();
	if (min(n,m)==1) return writeln(1),void();
	fac[0]=inv[0]=1;
	for (int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	inv[n]=quickPower(fac[n],mod-2);
	for (int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%mod;
	int now=1;
	for (int i=0;i<=n;i++)
		a[i]=now,now=mod-now,a[i]=a[i]*inv[i]%mod;
		
		
	mu[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!vis[i])
		{
			pr[++cnt]=i;
			mu[i]=-1;
		}
		for (int j=1;j<=cnt&&pr[j]*i<=n;j++)
		{
			vis[i*pr[j]]=1;
			if (i%pr[j]==0) continue;
			mu[i*pr[j]]=-mu[i];
		}
	}
	
	// cout<<calc(4,2)<<endl;
	for (int i=1;i<=n;i++)
	{
		int x=calc(n/i+(n%i!=0),m);
		mu[i]=(mod+mu[i])%mod;
		ans+=x*mu[i];
		ans%=mod;
		ans=(ans-mu[i]+mod)%mod;
	}
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