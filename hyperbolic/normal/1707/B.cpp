#include <stdio.h>
#include <algorithm>
 
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
		for(int j=1;j<=30&&a>=2;j++)
		{
			for(int i=1;i<a;i++) y[i] = x[i+1]-x[i];
			x[a] = 0;
			a--;
			for(int i=1;i<=a;i++) x[i] = y[i];
			std::sort(x+1,x+a+1);
		}
		while(a>=2)
		{
			int b = a-30>1?a-30:1;
			for(int i=b;i<a;i++) y[i] = x[i+1]-x[i];
			x[a] = 0;
			a--;
			for(int i=b;i<=a;i++) x[i] = y[i];
			std::sort(x+b,x+a+1);
		}
		printf("%d\n",x[a]);
	}
}