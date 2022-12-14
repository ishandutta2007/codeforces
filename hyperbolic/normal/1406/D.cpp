#include <stdio.h>

long long int x[100010],y[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<a;i++) y[i] = x[i+1]-x[i];
	
	long long int S = 0;
	for(int i=1;i<a;i++) S += (y[i]<0?0:y[i]);
	long long int t = (x[1]-S)/2;
	long long int t1 = x[1]-t;
	long long int t2 = S+t;
	printf("%lld\n",t1>t2?t1:t2);
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		if(c==1) x[1] += e;
		else
		{
			S -= (y[c-1]<0?0:y[c-1]);
			y[c-1] += e;
			S += (y[c-1]<0?0:y[c-1]);
		}
		
		if(d<a)
		{
			S -= (y[d]<0?0:y[d]);
			y[d] -= e;
			S += (y[d]<0?0:y[d]);
		}
		
		t = (x[1]-S)/2;
		t1 = x[1]-t;
		t2 = S+t;
		printf("%lld\n",t1>t2?t1:t2);
	}
}