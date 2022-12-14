#include <stdio.h>

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int min = 1, max = 1;
		for(int i=2;i<=a;i++)
		{
			if(x[min]>x[i]) min = i;
			if(x[max]<x[i]) max = i;
		}
		if(min<max) printf("%d %d\n",min,max);
		else printf("%d %d\n",max,min);
	}
}