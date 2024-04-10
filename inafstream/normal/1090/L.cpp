#include <bits/stdc++.h>

using namespace std;

long long t,n,a,b,k,l,r,mid,ans=0;

bool check(long long x)
{
	return x*k<=min(a,x)*(n/2+n%2)+min(b,x)*(n/2);
}

int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d",&t,&n,&a,&b,&k);
	
	l=1;r=t+1;
	
	while (l<r)
	{
		mid=(l+r)/2;
		if (check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid;
	}
	
	cout<<ans<<endl;
	
	return 0;
}