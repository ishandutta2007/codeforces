#include <stdio.h>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		if(x[1]!=x[2])
		{
			if(x[1]!=x[3]) printf("1\n");
			else printf("2\n");
		}
		else
		{
			int t = x[1];
			for(int i=1;i<=a;i++) if(x[i]!=t) printf("%d\n",i);
		}
	}
}