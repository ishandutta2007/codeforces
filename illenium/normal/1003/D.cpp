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
#define maxn 400005
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

ll n,q,b[maxn],p,ans,cnt,x;
map <ll,int> mp;

int main()
{
	cin>>n>>q;
	for(ll i=1;i<=n;i++)
	{
		int x=read(); mp[x]++; b[++cnt]=x;
	}
	sort(b+1,b+cnt+1);
	p=unique(b+1,b+cnt+1)-b-1;
	while(q--)
	{
		ll x=read(); ans=0;
		for(ll i=p;i>=1;i--)
		{
			if(mp[b[i]]*b[i]>=x)
			{
				ans+=(x/b[i]);
				x%=b[i];
			}
			else
			{
				ans+=mp[b[i]];
				x-=mp[b[i]]*b[i];
			}
			if(x==0) break;
		}
		if(x==0) printf("%lld\n",ans);
		else puts("-1");
	}
	return 0;
}