#include <stdio.h>

int x[110],y[110],ans[210];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		scanf("%d",&b);
		for(int i=1;i<=b;i++) scanf("%d",&y[i]);
		int max1 = 0, max2 = 0;
		int S = 0;
		for(int i=1;i<=a;i++)
		{
			S += x[i];
			max1 = max1>S?max1:S;
		}
		S = 0;
		for(int i=1;i<=b;i++)
		{
			S += y[i];
			max2 = max2>S?max2:S;
		}
		printf("%d\n",max1+max2);
	}
}