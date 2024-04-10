// Lynkcat.
// Problem: E. Balance Addicts
// Contest: Codeforces - Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms

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
#define N 100005 
using namespace std;
int n,a[N];
int fac[N],inv[N],pre[N],suf[N];
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int C(int x,int y)
{
	if (x<y||y<0) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void BellaKira()
{
	poly g;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i],pre[i]=pre[i-1]+a[i];
	suf[n+1]=0;
	for (int i=n;i>=1;i--) suf[i]=suf[i+1]+a[i];
	for (int i=1;i<=n;i++) 
		if (a[i]>0) g.push_back(i);
	if (g.size()==0) return cout<<quickPower(2,n-1)<<'\n',void();
	int ans=0;
	for (int k=0;k<=min(g[0]-1,n-g.back());k++)
		ans=(ans+C(g[0]-1,k)*C(n-g.back(),k)%mod)%mod;
	for (int i=0,j=(int)g.size()-1;i<j;i++)
	{
		int o=j;
		while (i<j&&pre[g[i]]>suf[g[j]]) j--;
		if  (pre[g[i]]!=suf[g[j]]) continue;
		if (i>j) break;
		if (j<=i+1)
		{
			// cout<<"?"<<i<<" "<<j<<endl;
			ans=ans*quickPower(2,g[j]-g[i])%mod;
			break;
		}
		int x=g[i+1]-g[i];
		int y=g[j]-g[j-1];
		int now=0;
		for (int k=0;k<=min(x,y);k++)
			now=(now+C(x,k)*C(y,k)%mod)%mod;
		ans=ans*now%mod;
	}
	cout<<ans<<'\n';
}
signed main()
{
	fac[0]=1;
	for (int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
	inv[N-1]=quickPower(fac[N-1],mod-2);
	for (int i=N-1;i>=1;i--) inv[i-1]=inv[i]*i%mod;
	IOS;cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}