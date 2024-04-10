#include <stdio.h>

int check[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=0;i<=9;i++) check[i] = 1;
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			check[b] = 0;
		}
		
		int S = 0;
		for(int i=0;i<=9;i++) S += check[i];
		printf("%d\n",3*S*(S-1));
	}
}