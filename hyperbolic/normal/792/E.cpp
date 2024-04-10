#include <stdio.h>
#define SIZE 40000

long long int x[510];
int a;
void func(int h)
{
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		long long int b = x[i]/(h+1);
		long long int c = x[i]%(h+1);
		if(c==0) ans += b;
		else ans += (b+1);
	}
	printf("%lld",ans);
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int c=1;c<=SIZE;c++)
	{
		if(x[1]%c==0)
		{
			long long int h = x[1]/c;
			if(x[1]>h*h) continue;
			for(int i=1;i<=a;i++)
			{
				long long int b = x[i]/h;
				long long int c = x[i]%h;
				if(c>b) goto u2;
			}
			func(h);
			return 0;
			u2:;
			
			h = (x[1]/c)-1;
			if(x[1]>h*h) continue;
			for(int i=1;i<=a;i++)
			{
				long long int b = x[i]/h;
				long long int c = x[i]%h;
				if(c>b) goto u3;
			}
			func(h);
			return 0;
			u3:;
		}
		else
		{
			long long int h = x[1]/c;
			if(x[1]>h*h) continue;
			for(int i=1;i<=a;i++)
			{
				long long int b = x[i]/h;
				long long int c = x[i]%h;
				if(c>b) goto u4;
			}
			func(h);
			return 0;
			u4:;
		}
	}
	
	for(int h=SIZE;h>=1;h--)
	{
		for(int i=1;i<=a;i++)
		{
			long long int b = x[i]/h;
			long long int c = x[i]%h;
			if(c>b) goto u;
		}
		func(h);
		return 0;
		u:;
	}
}