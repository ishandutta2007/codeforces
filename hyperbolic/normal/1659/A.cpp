#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int d = b/(c+1);
		int e = b%(c+1);
		for(int i=1;i<=c;i++)
		{
			for(int j=1;j<=d;j++) printf("R");
			if(i<=e) printf("R");
			printf("B");
		}
		for(int j=1;j<=d;j++) printf("R");
		printf("\n");
	}
}