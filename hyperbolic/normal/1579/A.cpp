#include <stdio.h>
#include <string.h>

char x[1010];
int count[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		count[0] = count[1] = count[2] = 0;
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int i=1;i<=a;i++) count[x[i]-'A']++;
		if(count[0]+count[2]==count[1]) printf("YES\n");
		else printf("NO\n");
	}
}