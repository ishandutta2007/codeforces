#include <stdio.h>

int count[3010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=2048;i*=2) count[i] = 0;
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			if(b<=2048) count[b]++;
		}
		for(int i=1;i<2048;i*=2) count[2*i] += (count[i]/2);
		printf("%s\n",count[2048]>0?"YES":"NO");
	}
}