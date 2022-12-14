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
		
		int sum = 0;
		for(int i=1;i<=a;i++)
		{
			for(int j=i;j<=a;j++)
			{
				int ans = (j-i+1);
				for(int k=i;k<=j;k++)
				{
					if(x[k]==0) ans++;
				}
				sum += ans;
			}
		}
		printf("%d\n",sum);
	}
}