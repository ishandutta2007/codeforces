#include <stdio.h>
#include <string.h>

char x[1010];
int main()
{
	int a;
	scanf("%d",&a);
	
	int ans = 0;
	while(a>-1)
	{
		scanf("%s",x+1);
		int b = strlen(x+1);
		a-=b;
		a--;
		int count = 0;
		for(int i=1;i<=b;i++) if('A'<=x[i]&&x[i]<='Z') count++;
		ans = ans>count?ans:count;
	}
	printf("%d",ans);
}