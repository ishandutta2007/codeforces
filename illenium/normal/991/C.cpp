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
#define maxn 200005
#define re register
#define inf 1e18
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,ans;

inline bool jud(ll x)
{
	ll tmp=0,p=n;
	while(p>0)
	{
		tmp+=min(x,p); p-=x;
		p-=p/10;
	}
	if(tmp>=(n+1)/2) return true;
	return false;
}

int main()
{
	cin>>n;
	ll l=1,r=inf;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(jud(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}