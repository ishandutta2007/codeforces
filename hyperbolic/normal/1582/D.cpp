#include <stdio.h>

int abs(int k)
{
	return k>0?k:-k;
}

int x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int sum = x[1];
		y[1] = 1;
		for(int i=2;i<a;i++)
		{
			if(x[i]>0)
			{
				if(sum - x[i]>=-10000) sum -= x[i], y[i] = -1;
				else sum += x[i], y[i] = 1;
			}
			else
			{
				if(sum + x[i]>=-10000) sum += x[i], y[i] = 1;
				else sum -= x[i], y[i] = -1;
			}
		}
		
		if(sum==0)
		{
			int ind = 1;
			for(int i=2;i<=a-1;i++) if(abs(x[i])<abs(x[ind])) ind = i;
			sum += x[ind];
			y[ind]++;
		}
		
		y[a] = -sum;
		for(int i=1;i<a;i++) y[i] *= x[a];
		
		for(int i=1;i<=a;i++) printf("%d ",y[i]);
		printf("\n");
	}
}