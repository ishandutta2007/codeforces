#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

ll n,k,fac[maxn],inv[maxn];
const ll mod=998244353;

inline ll pw(ll a,ll b)
{
	ll ans=1,base=a;
	while(b)
	{
		if(b&1) ans=(ans*base)%mod;
		base=(base*base)%mod; b>>=1;
	}
	return ans;
}

inline ll C(int N,int M){return (fac[N]*inv[M])%mod*inv[N-M]%mod;}

int main()
{
	cin>>n>>k; fac[0]=1; inv[0]=1;
	rep(i,1,n) fac[i]=(fac[i-1]*i)%mod; 
	rep(i,1,n) inv[i]=pw(fac[i],mod-2);
	if(k>=n) puts("0"); else if(k==0) cout<<fac[n]<<endl;
	else
	{
		ll nw=1,p=0,ans=0;
		for(int i=0;i<=n-k;i++)
		{
			p=(C(n-k,i)*pw(n-k-i,n))%mod*nw;
			ans=(ans+p+mod)%mod; nw*=-1;
		}
		cout<<(2*ans*C(n,k))%mod<<endl;
	}
	return 0;
}