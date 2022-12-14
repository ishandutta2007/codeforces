#include <stdio.h>
#include <string.h>

char x[110],y[110],z[110];
int s[30];
int main()
{
	int Case;
	scanf("%d",&Case);
	for(int T=1;T<=Case;T++)
	{
		for(int i=0;i<=26;i++) s[i] = 0;
		scanf("%s",x+1);
		scanf("%s",y+1);
		scanf("%s",z+1);
		int a = strlen(x+1);
		int b = strlen(y+1);
		int c = strlen(z+1);
		
		int p = 0;
		for(int i=1;i<=a;i++)
		{
			p++;
			while(p<=b)
			{
				if(y[p]==x[i]) goto u;
				p++;
			}
			printf("NO\n");
			goto v;
			
			u:;
		}
		for(int i=1;i<=b;i++) s[y[i]-'a']++;
		for(int i=1;i<=a;i++) s[x[i]-'a']--;
		for(int i=1;i<=c;i++) s[z[i]-'a']--;
		for(int i=0;i<=26;i++)
		{
			if(s[i]>=1)
			{
				printf("NO\n");
				goto v;
			}
		}
		printf("YES\n");
		v:;
	}
}