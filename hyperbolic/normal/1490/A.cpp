#include <stdio.h>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int count = 0;
		for(int i=1;i<a;i++)
		{
			if(x[i]<x[i+1])
			{
				int C = x[i];
				while(2*C<x[i+1]) count++,C*=2;
			}
			else
			{
				int C = x[i+1];
				while(2*C<x[i]) count++,C*=2;
			}
		}
		printf("%d\n",count);
	}
}