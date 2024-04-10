#include <stdio.h>

int x[100010];
int count[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++) scanf("%d",&x[i]);
	int s = 0;
	for(int i=1;i<=b;i++)
	{
		if(count[x[i]]==0)
		{
			s++;
			count[x[i]] = 1;
			if(s==a)
			{
				printf("1");
				for(int j=1;j<=a;j++)
				{
					count[j]--;
					if(count[j]==0) s--;
				}
			}
			else printf("0");
		}
		else
		{
			count[x[i]]++;
			printf("0");
		}
	}
}