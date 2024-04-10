#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000500
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll a[maxn],b[maxn],n,cnt,p[maxn],sum[maxn];
bool vis[maxn];

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		ll k=read(),mx=0,mn=inf;
		for(int j=1;j<=k;j++)
		{
			ll x=read();
			if(x>mn&&vis[i]==0) cnt++,vis[i]=1;
			mx=max(x,mx); mn=min(x,mn);
		}
		a[i]=mx; if(vis[i]==0) b[i]=mn;
	}
	ll ans=n*n-(n-cnt)*(n-cnt);
	for(int i=1;i<=n;i++) if(vis[i]==0) p[b[i]]++; sum[0]=p[0];
	for(int i=1;i<=maxn-5;i++) sum[i]=sum[i-1]+p[i];
	for(int i=1;i<=n;i++) if(vis[i]==0) ans+=sum[a[i]-1];
	cout<<ans<<endl;
	return 0;
}