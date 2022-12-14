#include <stdio.h>
#include <string.h>

char x[110];
int count[110][110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		int b = strlen(x+1);
		count[b-1][x[b]-'A']++;
	}
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		int b = strlen(x+1);
		if(count[b-1][x[b]-'A']>=1) count[b-1][x[b]-'A']--;
		else ans++;
	}
	printf("%d",ans);
}