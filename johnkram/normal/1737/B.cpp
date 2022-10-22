#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 205
int t;
ll l,r;
ll work(ll n)
{
	if(!n)return 0;
	ll l=0,r=1<<30,mid;
	while(l+1<r)
	{
		mid=l+r>>1;
		if(mid*mid<=n)l=mid;
		else r=mid;
	}
	return (l-1)*2+n/l;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",work(r)-work(l-1));
	}
	return 0;
}