#include <stdio.h>
int check[1000010];
int main()
{
	int a,b,c,d,e;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++)
	{
		scanf("%d",&d);
		check[d] = 1;
	}
	int s = 1;
	for(int i=1;i<=c;i++)
	{
		if(check[s]==1)
		{
			printf("%d",s);
			return 0;
		}
		scanf("%d%d",&d,&e);
		if(d==s) s = e;
		else if(e==s) s = d;
	}
	printf("%d",s);
}