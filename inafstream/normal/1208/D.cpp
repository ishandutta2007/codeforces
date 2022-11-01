#include <bits/stdc++.h>
using namespace std;

int n,i,j,res[200005];
long long a[200005];
int fa[200005];

int fnd(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=fnd(fa[x]);
}

struct bit
{
	long long s[200005];
	void add(int x,long long y)
	{
		int i;
		for (i=x;i<=n;i+=(i&-i))
		{
			s[i]+=y;
		}
	}
	long long sum(int x)
	{
		int i;long long sum=0;
		for (i=x;i;i-=(i&-i))
		{
			sum+=s[i];
		}
		return sum;
	}
}c;

int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		fa[i]=i;
		scanf("%I64d",&a[i]); 
	}
	
	for (i=1;i<=n;i++)
	{
		c.add(i,i);
	}
	
	for (i=n;i>=1;i--)
	{
		int l=1,r=n+1,ans=0,mid;
		while (l<r)
		{
			mid=(l+r)/2;
			if (c.sum(mid-1)<a[i])
			{
				ans=mid;
				l=mid+1;
			}
			else
			{
				r=mid;
			}
		}
		res[i]=fnd(ans+1);
		fa[res[i]]=res[i]+1;
		c.add(res[i],-res[i]);
	}
	
	for (i=1;i<=n;i++)
	{
		printf("%d ",res[i]);
	}
	
	return 0;
}