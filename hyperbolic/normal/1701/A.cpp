#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int ans = 0;
		for(int i=1;i<=4;i++)
		{
			int b;
			scanf("%d",&b);
			ans+=b;
		}
		if(ans==0) printf("0\n");
		else if(ans==4) printf("2\n");
		else printf("1\n");
	}
}