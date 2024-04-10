#include <stdio.h>

char x[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		if(a==2)
		{
			if(x[1]>=x[2]) printf("NO\n");
			else printf("YES\n2\n%c %c\n",x[1],x[2]);
		}
		else
		{
			printf("YES\n2\n");
			printf("%c ",x[1]);
			for(int i=2;i<=a;i++) printf("%c",x[i]);
			printf("\n");
		}
	}
}