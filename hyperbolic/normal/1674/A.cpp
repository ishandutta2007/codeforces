#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=100;i++)
		{
			long long int S = a;
			for(int j=1;j<=10;j++)
			{
				S*=i;
				if(S>b) break;
				if(S==b)
				{
					printf("%d %d\n",j,i);
					goto u;
				}
			}
		}
		printf("0 0\n");
		u:;
	}
}