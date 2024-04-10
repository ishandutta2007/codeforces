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
 
ll n,k;
 
inline ll jud(ll x)
{
	if(x==0) return 0;
	ll l=0,r=0;
	if(x%2==0) l=x,r=x+1;
	else l=x,r=x;
	ll tmp=0;
	while(l<=n)
	{
		tmp+=r-l+1;
		if(l*2<=n) l=2*l;
		else l=n+1;
		r=min(2*r+1,n);
	}
	return tmp;
}
 
int main()
{
	ll ans=0; cin>>n>>k;
	ll l=1,r=n;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(mid%2==0)
		{
			if(jud(mid)>=k) l=mid+1,ans=mid;
			else r=mid-1;
		}
		else
		{
			if(jud(mid-1)>=k) l=mid,ans=mid-1;
			if(jud(mid+1)>=k) l=mid+2,ans=mid+1;
			else r=mid-1;
		}
		//cout<<mid<<endl;
	}
	if(ans==0) cout<<1<<endl;
	else
	{
		if(jud(ans+1)>=k) cout<<ans+1<<endl;
		else cout<<ans<<endl;;
	}
	return 0;
}