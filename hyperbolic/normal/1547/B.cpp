#include <stdio.h>
#include <string.h>

char x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		
		int L = 1, R = a;
		for(int i=1;i<=a;i++)
		{
			if(x[L]=='a'+a-i) L++;
			else if(x[R]=='a'+a-i) R--;
			else
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}