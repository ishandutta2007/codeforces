#include <stdio.h>

int check[3000010];
int main()
{
	check[0] = 1;
	for(int i=0;i<=1000000;i++)
	{
		if(check[i]==1)
		{
			check[i+11] = 1;
			check[i+111] = 1;
			check[i+1111] = 1;
			check[i+11111] = 1;
		}
	}
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a>1000000) printf("YES\n");
		else
		{
			if(check[a]==1) printf("YES\n");
			else printf("NO\n");
		}
	}
}