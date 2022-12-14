#include <stdio.h>
#include <math.h>
long long int getQuery(long long int s, long long int t)
{
	printf("? %lld %lld\n",s,t);
	fflush(stdout);
	
	long long int a;
	scanf("%lld",&a);
	return a;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		long long int V = getQuery(1,a);
		long long int min = 1, max = a;
		long long int L = a;
		while(min<=max)
		{
			long long int h = (min+max)/2;
			long long int t = getQuery(1,h);
			if(t==0)
			{
				L = h;
				min = h+1;
			}
			else max = h-1;
		}
		
		long long int t = getQuery(L+1,a);
		long long int l1 = V - t + 1;
		long long int t2 = getQuery(L+l1,a);
		long long int t3 = getQuery(L+l1+1,a);
		long long int l2 = t2-t3+1;
		printf("! %lld %lld %lld\n",L,L+l1,L+l1+l2-1);
		fflush(stdout);
	}
}