#include <stdio.h>

int abs(int k)
{
	return k>0?k:-k;
}

int x[100010],y[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int min = 1, max = b;
		int p = b+1;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(y[h]>=x[i])
			{
				p = h;
				max = h-1;
			}
			else min = h+1;
		}
		if(p==b+1) ans = ans>abs(x[i]-y[b])?ans:abs(x[i]-y[b]);
		else if(p==1) ans = ans>abs(x[i]-y[1])?ans:abs(x[i]-y[1]);
		else
		{
			int t1 = abs(x[i]-y[p]);
			int t2 = abs(x[i]-y[p-1]);
			int t = t1<t2?t1:t2;
			ans = ans>t?ans:t;
		}
	}
	printf("%d",ans);
}