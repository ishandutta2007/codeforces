#include <stdio.h>

int check[1010];
int main()
{
	for(int i=0;i<=100;i++) for(int j=0;j<=100;j++) check[3*i+7*j] = 1;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		printf("%s\n",check[a]==1?"YES":"NO");
	}
}