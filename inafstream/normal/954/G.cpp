#include <bits\stdc++.h>

using namespace std;

long long cnt[500005],cnt2[500005],a[500005];

bool check(long long x,long long n,long long m,long long k)
{
	long long i,s=0;
	
	memset(cnt2,0,sizeof(cnt2));
	
	for (i=1;i<=n;i++)
	{
		cnt2[i]+=cnt2[i-1];
		
		if (cnt2[i]+cnt[i]<x)
		{
			long long t=x-cnt[i]-cnt2[i];
			
			s+=t;
			
			cnt2[i]+=t;
			cnt2[min(n,i+m+m)+1]-=t;
		}
		
		if (s>k) return 0;
	}
	
	return s<=k;
}

int main()
{
	long long n,m,k,i;
	
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	
	for (i=1;i<=n;i++)
	{
		scanf("%I64d",a+i);
	}
	
	for (i=1;i<=n;i++)
	{
		cnt[max(1ll,i-m)]+=a[i];
		cnt[min(n,i+m)+1]-=a[i];
	}
	
	for (i=1;i<=n;i++) cnt[i]+=cnt[i-1];
	
	long long l=0,ans=0,r=1.2e18;
	
	while (l<r)
	{
		long long mid=(l+r)/2;
		
		if (check(mid,n,m,k))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid;
	}
	
	printf("%I64d\n",ans);
	
	return 0;
}