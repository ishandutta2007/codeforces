#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		int ans = 0;
		int S = 1;
		for(int i=1;i<=6;i++)
		{
			for(int j=1;j<=9;j++)
			{
				int val = S*j;
				if(val<=a) ans++;
			}
			S*=10;
		}
		printf("%d\n",ans);
	}
}