#include <stdio.h>

int check[110];
char x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<=26;i++) check[i] = 0;
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		
		char p = x[1];
		for(int i=2;i<=a;i++)
		{
			if(x[i]!=p)
			{
				if(check[x[i]-'A'+1])
				{
					printf("NO\n");
					goto u;
				}
				check[p-'A'+1] = 1;
				p = x[i];
			}
		}
		printf("YES\n");
		u:;
	}
}