#include <stdio.h>

int count[110];
char x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<=26;i++) count[i] = 0;
		scanf("%s",x+1);
		for(int i=1;i<=6;i++)
		{
			if('a'<=x[i]&&x[i]<='z') count[x[i]-'a']++;
			else
			{
				if(count[x[i]-'A']==0)
				{
					printf("NO\n");
					goto u;
				}
				else count[x[i]-'A']--;
			}
		}
		printf("YES\n");
		u:;
	}
}