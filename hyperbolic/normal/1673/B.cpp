#include <stdio.h>
#include <string.h>

char x[200010];
int check[110],last[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int i=0;i<26;i++) check[i] = 0;
		for(int i=1;i<=a;i++) check[x[i]-'a'] = 1;
		int sum = 0;
		for(int i=0;i<26;i++) sum += check[i];
		
		for(int i=0;i<26;i++) last[i] = -1;
		for(int i=1;i<=a;i++)
		{
			if(last[x[i]-'a']!=-1 && i-last[x[i]-'a']!=sum)
			{
				printf("NO\n");
				goto u;
			}
			last[x[i]-'a'] = i;
		}
		printf("YES\n");
		u:;
	}
}