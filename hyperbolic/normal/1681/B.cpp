#include <stdio.h>

int x[200010],y[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int start = 1;
		int b;
		scanf("%d",&b);
		for(int i=1;i<=b;i++)
		{
			int c;
			scanf("%d",&c);
			start += c;
			if(start>a) start -= a;
		}
		printf("%d\n",x[start]);
	}
}