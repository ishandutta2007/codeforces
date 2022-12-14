#include <stdio.h>

int check[100010];
int main()
{
	int c = 0;
	for(int i=1;i<=9;i++)
	{
		int s = 0;
		for(int j=1;j<=4;j++)
		{
			s*=10;
			s+=i;
			c+=j;
			check[s] = c;
		}
	}
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		printf("%d\n",check[a]);
	}
}