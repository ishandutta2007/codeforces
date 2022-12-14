#include <stdio.h>
#include <string.h>

char x[200010];
int check[5];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		
		int min = 1, max = a;
		int ans = 0;
		while(min<=max)
		{
			int h = (min+max)/2;
			for(int i=1;i<=3;i++) check[i] = 0;
			for(int i=1;i<=h;i++) check[x[i]-'0']++;
			if(check[1]>=1 && check[2]>=1 && check[3]>=1)
			{
				ans = h;
				max = h-1;
				goto u;
			}
			for(int i=h+1;i<=a;i++)
			{
				check[x[i-h]-'0']--;
				check[x[i]-'0']++;
				if(check[1]>=1 && check[2]>=1 && check[3]>=1)
				{
					ans = h;
					max = h-1;
					goto u;
				}
			}
			
			min = h+1;
			u:;
		}
		printf("%d\n",ans);
	}
}