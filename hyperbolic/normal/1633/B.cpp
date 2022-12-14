#include <stdio.h>
#include <string.h>

int count[110];
char x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		
		count[0] = count[1] = 0;
		for(int i=1;i<=a;i++)
		{
			count[x[i]-'0']++;
		}
		if(count[0]<count[1]) printf("%d\n",count[0]);
		else if(count[0]>count[1]) printf("%d\n",count[1]);
		else printf("%d\n",count[0]-1);
	}
}