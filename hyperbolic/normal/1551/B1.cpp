#include <stdio.h>
#include <string.h>

int count[30];
char x[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		
		for(int i=0;i<26;i++) count[i] = 0;
		
		for(int i=1;i<=a;i++) count[x[i]-'a']++;
		
		int C = 0;
		int ans = 0;
		for(int i=0;i<26;i++)
		{
			if(count[i]>=2) ans++;
			else C += count[i];
		}
		printf("%d\n",ans + C/2);
	}
}