#include <stdio.h>

int main()
{
	long long int m;
	scanf("%lld",&m);
	long long int h1,a1,x1,y1;
	scanf("%lld%lld%lld%lld",&h1,&a1,&x1,&y1);
	long long int h2,a2,x2,y2;
	scanf("%lld%lld%lld%lld",&h2,&a2,&x2,&y2);
	long long int k = h1;
	long long int start1 = -1, start2 = -1, p1 = -1, p2 = -1;
	for(int i=1;i<=m+1;i++)
	{
		if(k==a1)
		{
			start1 = i-1;
			break;
		}
		k = (k*x1+y1)%m;
	}
	k = a1;
	for(int i=1;i<=m+1;i++)
	{
		k = (k*x1+y1)%m;
		if(k==a1)
		{
			p1 = i;
			break;
		}
	}
	
	k = h2;
	for(int i=1;i<=m+1;i++)
	{
		if(k==a2)
		{
			start2 = i-1;
			break;
		}
		k = (k*x2+y2)%m;
	}
	k = a2;
	for(int i=1;i<=m+1;i++)
	{
		k = (k*x2+y2)%m;
		if(k==a2)
		{
			p2 = i;
			break;
		}
	}
	//printf("%lld %lld %lld %lld!!\n",start1,start2,p1,p2);
	if(start1==-1||start2==-1)
	{
		printf("-1");
		return 0;
	}
	if(p1==-1&&p2==-1)
	{
		if(start1==start2) printf("%lld",start1);
		else printf("-1");
	}
	else if(p1==-1)
	{
		if(start1>=start2 && (start1-start2)%p2==0) printf("%lld",start1);
		else printf("-1");
	}
	else if(p2==-1)
	{
		if(start2>=start1 && (start2-start1)%p1==0) printf("%lld",start2);
		else printf("-1");
	}
	else
	{
		int count = 1234567;
		for(long long int ans = start1;count;ans+=p1)
		{
			if(ans>=start2 && (ans-start2)%p2==0)
			{
				printf("%lld",ans);
				return 0;
			}
			count--;
		}
		printf("-1");
	}
}