#include<bits/stdc++.h>
using namespace std;
int t;
long long l,r;
long long m;
bool flag;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		scanf("%lld%lld%lld",&l,&r,&m);
		for(int i=l;i<=r;i++)
		{
			long long left=1,right=m;
			while(left<=right)
			{
				long long mid=(left+right)/2;
				if(abs(mid*i-m)<=r-l)
				{
					if(mid*i-m>=0)
					{
						printf("%d %lld %lld\n",i,l,l+mid*i-m);
					}
					else
					{
						printf("%d %lld %lld\n",i,r,r+mid*i-m);
					}
					flag=1;
					break;
				}
				else if(mid*i-m<=l-r)
				{
					left=mid+1;
				}
				else
				{
					right=mid-1;
				}
			}
			if(flag)
			{
				break;
			}
		}
	}
	return 0;
}