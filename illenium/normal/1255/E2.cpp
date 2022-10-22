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
#define maxn 1000005
#define re register
#define inf 1e18
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll a[maxn],n,cnt;
vector <ll> vec,tmp;

inline ll jud(ll x)
{
	ll tot=0,tt2=0;
	for(int i=1;i<=n;i++)
	{
		tt2=(tt2+a[i])%x;
		if(x-tt2%x>tt2%x) tot+=tt2%x;
		else tot+=x-tt2%x;
	}
	return tot;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),cnt+=a[i];
	ll ans=inf;
	for(ll i=2;i<=sqrt(cnt);i++)
	{
		if(cnt%i==0)
		{
			ans=min(ans,jud(i));
			ans=min(ans,jud(cnt/i));
		}
		while(cnt%i==0) cnt/=i;
	}
	if(cnt!=1) ans=min(ans,jud(cnt));
	if(ans==1e18) puts("-1");
	else printf("%lld\n",ans);
	return 0;
}