#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

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

ll fac[maxn],inv[maxn];
char s[maxn];
int n;

inline ll C(int N,int M)
{
	if(N<M||M<0) return 0;
	return (fac[N]*inv[M])%mod*inv[N-M]%mod;
}

int main()
{
	fac[0]=1; inv[0]=1; rep(i,1,maxn-5) fac[i]=(fac[i-1]*i)%mod,inv[i]=pw(fac[i],mod-2);
	int T=read();
	while(T--)
	{
		n=read(); scanf("%s",s+1); int t1=0,t2=0,cnt=0;
		rep(i,1,n)
		{
			if(s[i]=='0') t1+=cnt/2,cnt=0,t2++;
			else cnt++;
		}
		t1+=cnt/2;
		printf("%lld\n",C(t1+t2,t2));
	}
	return 0;
}