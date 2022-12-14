#include <stdio.h>

int check[110];
char x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		check[0] = check[1] = 0;
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		x[a+1] = 'W';
		for(int i=1;i<=a+1;i++)
		{
			if(x[i]=='W')
			{
				if(check[0]==0&&check[1]==0);
				else if(check[0]==1&&check[1]==1) check[0] = check[1] = 0;
				else
				{
					printf("NO\n");
					goto u;
				}
			}
			else if(x[i]=='R') check[0] = 1;
			else check[1] = 1;
		}
		printf("YES\n");
		u:;
	}
}