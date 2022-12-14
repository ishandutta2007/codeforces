#include <stdio.h>
#include <algorithm>

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		for(int i=1;i<=a;i++)
		{
			if(x[i]==b)
			{
				printf("1\n");
				goto u;
			}
		}
		
		if(b<x[a])
		{
			printf("2\n");
			goto u;
		}
		
		c = (b-1)/x[a]+1;
		printf("%d\n",c);
		
		u:;
	}
}