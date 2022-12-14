#include <stdio.h>

int x[2010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int control = 0;
		for(int i=1;i<=a;i++) if(x[i]!=i) control = 1;
		if(control==0)
		{
			printf("0\n");
			continue;
		}
		
		if(x[1]==1) printf("1\n");
		else if(x[a]==a) printf("1\n");
		else if(x[1]==a&&x[a]==1) printf("3\n");
		else printf("2\n");
	}
}