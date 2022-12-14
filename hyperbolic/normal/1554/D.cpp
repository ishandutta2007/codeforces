#include <stdio.h>
#include <vector>

char ans[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a==1) printf("a\n");
		else if(a==2) printf("ab\n");
		else
		{
			if(a%2==1)
			{
				int b = (a-1)/2;
				for(int i=1;i<=b;i++) printf("a");
				printf("bc");
				for(int i=1;i<b;i++) printf("a");
				printf("\n");
			}
			else
			{
				int b = (a-2)/2;
				for(int i=1;i<=b;i++) printf("a");
				printf("bcd");
				for(int i=1;i<b;i++) printf("a");
				printf("\n");
			}
		}
	}
}