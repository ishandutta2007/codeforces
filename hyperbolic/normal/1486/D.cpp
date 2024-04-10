#include <stdio.h>

int x[200010],y[200010],max[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int l = 1, r = a;
	int ans = 0;
	while(l<=r)
	{
		int h = (l+r)/2;
		for(int i=1;i<=a;i++)
		{
			if(x[i]>=h) y[i] = 1;
			else y[i] = 0;
		}
		for(int i=2;i<=a;i+=2) y[i] += -1;
		for(int i=1;i<=a;i++) y[i] += y[i-1];
		max[a] = y[a];
		for(int i=a-1;i>=1;i--) max[i] = max[i+1]>y[i]?max[i+1]:y[i];
		for(int i=1;i+b-1<=a;i+=2)
		{
			if(max[i+b-1]-y[i-1]>0)
			{
				ans = h;
				l = h+1;
				goto u;
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			if(x[i]>=h) y[i] = 1;
			else y[i] = 0;
		}
		for(int i=1;i<=a;i+=2) y[i] += -1;
		for(int i=1;i<=a;i++) y[i] += y[i-1];
		max[a] = y[a];
		for(int i=a-1;i>=1;i--) max[i] = max[i+1]>y[i]?max[i+1]:y[i];
		for(int i=2;i+b-1<=a;i+=2)
		{
			if(max[i+b-1]-y[i-1]>0)
			{
				ans = h;
				l = h+1;
				goto u;
			}
		}
		r = h-1;
		u:;
	}
	printf("%d\n",ans);
}