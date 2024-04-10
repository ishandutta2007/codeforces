#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 500005
#define re register
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

ll s[maxn],a[maxn],v[maxn],num,n,k,ans;

int main()
{
	n=read(); k=read();
	if(k==1) ans+=n;
	for(int i=1;i<=n;i++) a[i]=read(),s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++) if(a[i]>1) v[++num]=i;
	v[num+1]=n+1;
	for(int i=1;i<=num;i++)
	{
		ll x=v[i],now=a[x];
		for(int j=i+1;j<=num;j++)
		{
			ll y=v[j]; now*=a[y];
			if(now>(ll)1e12) break;
			if(now%k!=0) continue;
			ll l=v[i]-v[i-1]-1,r=v[j+1]-v[j]-1;
			ll det=now/k-s[y]+s[x-1];
			if(det>=0&&det<=l+r)
			{
				ll sl=min(l,det),dl=max(0ll,det-r);
				ans+=(sl-dl+1);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}