#include <stdio.h>

char x[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		
		if(b==0)
		{
			printf("1\n");
			continue;
		}
		
		int control = 1;
		for(int i=1;i<=a;i++) if(x[i]!=x[a-i+1]) control = 2;
		
		printf("%d\n",control);
	}
}