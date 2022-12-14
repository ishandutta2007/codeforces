#include <stdio.h>
#include <vector>

long long int a,b,c;
double p=0,time = 0;
void func()
{
	long long int d = b*(a/b);
	long long int e = a-d;
	if(p+(((double)d)/c)>=1)
	{
		time += (1-p)*c;
		p = 1;
		return;
	}
	else
	{
		p += (((double)d)/c);
		time += d;
		if(e>0)
		{
			if(p+(((double)e)/c)>=1)
			{
				time += (1-p)*c;
				p = 1;
				return;
			}
			else
			{
				p += ((double)e)/c;
				time += e;
				if(p+((double)(b-e))/(2*c)>=1)
				{
					time += (1-p)*2*c;
					p = 1;
					return;
				}
				else
				{
					p += ((double)(b-e))/(2*c);
					time += (b-e);
				}
			}
		}
	}
}
long long int min = 1, max = 1;
int main()
{
	for(int i=1;i<=18;i++) max *=10;
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	func();
	if(p==1) printf("%.12lf",time);
	else
	{
		long long int ans = 1;
		while(min<=max)
		{
			long long int h =(min+max)/2;
			if(p*h>=1) max = h-1;
			else
			{
				min = h+1;
				ans = h;
			}
		}
		p *= ans, time *= ans;
		func();
		printf("%.12lf",time);
	}
}