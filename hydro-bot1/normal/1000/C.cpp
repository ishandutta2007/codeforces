// Hydro submission #62b808751e65e67e47ec840f@1656227958561
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair < ll , ll >
ll l,r,n;
pll s[400005];
ll a[400005],ans[200005];


void add(int x,int y)
{
	for(;x<=2*n;x+=x&(-x))
		a[x]+=y;
}

int sum(int x)
{
	int ret=0;
	for(;x;x-=x&(-x))
		ret+=a[x];
	return ret;
}

int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%lld",&l,&r);
		s[i]=make_pair(l,1);
		s[i+n]=make_pair(r+1,-1);
	}
	sort(s+1,s+2*n+1);
	for(int i=1;i<=2*n;++i)
	{
		add(i,s[i].second);
	}
	for(int i=1;i<=2*n-1;++i)
	{
		ans[sum(i)]+=s[i+1].first-s[i].first;
	}
	for(int i=1;i<=n;++i)
	{
		printf("%lld ",ans[i]);
	}
	return 0;
}