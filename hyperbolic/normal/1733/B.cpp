#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		
		if(b==0&&c==0)
		{
			printf("-1\n");
			continue;
		}
		if(b<c)
		{
			int temp = b;
			b = c;
			c = temp;
		}
		
		if(c==0)
		{
			if((a-1)%b==0)
			{
				for(int i=2;i<=a;i+=b)
				{
					for(int j=i;j<=i+b-1;j++) printf("%d ",i);
				}
				printf("\n");
			}
			else printf("-1\n");
		}
		else printf("-1\n");
	}
}