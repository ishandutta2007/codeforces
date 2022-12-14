#include <stdio.h>
#include <string.h>

char x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		int count = 0;
		for(int i=1;i<=a;i++) if(x[i]=='N') count++;
		printf("%s\n",count==1?"NO":"YES");
	}
}