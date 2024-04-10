#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll l[maxn],r[maxn],b[maxn],tot,cnt,segl[maxn],segr[maxn],dp[maxn][maxn],sum=1;
const ll mod=998244353;

inline ll qpow(ll a,ll b)
{
	ll ans=1,q=a;
	while(b)
	{
		if(b&1) ans=(ans*q)%mod;
		q=(q*q)%mod; b>>=1;
	}
	return ans;
}

inline ll C(int y,int x)
{
	ll ans=1;
	for(int i=1;i<=x;i++) ans=1ll*ans*(y+1-i)%mod*qpow(i,mod-2)%mod;
	return ans;
}

int main()
{
	//freopen("t1.in","r",stdin);
	int n=read();
	for(int i=1;i<=n;i++)
	{
		l[i]=read(),r[i]=read()+1;
		b[++cnt]=l[i]; b[++cnt]=r[i];
		sum=1ll*sum*(r[i]-l[i])%mod;
	}
	sort(b+1,b+cnt+1);
	tot=unique(b+1,b+cnt+1)-b-1;
	for(int i=1;i<tot;i++) segl[i]=b[i],segr[i]=b[i+1]-1;
	//for(int i=1;i<tot;i++) cout<<segl[i]<<" "<<segr[i]<<endl; cout<<endl;
	for(int i=1;i<=n;i++)
	{
		l[i]=lower_bound(segl+1,segl+tot,l[i])-segl;
		r[i]=lower_bound(segr+1,segr+tot,r[i]-1)-segr;
		//cout<<l[i]<<" "<<r[i]<<" "<<endl;
	}
	for(int i=1;i<=cnt;i++) dp[0][i]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=l[i];j<=r[i];j++)
		{
			for(int k=i;k;k--)
			{
				if(l[k]>j||r[k]<j) break;
				dp[i][j]+=(dp[k-1][j+1]*C(b[j+1]-b[j]+i-k,i-k+1))%mod;
			}
		}
		for(int j=tot-1;j>=1;j--) dp[i][j]=(dp[i][j]+dp[i][j+1])%mod;
	}
	printf("%lld",1ll*dp[n][1]*qpow(sum,mod-2)%mod);
	return 0;
}