#include <stdio.h>
#include <string.h>

char x[1010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	
	int C = 1;
	for(int i=1;i<=a;i++)
	{
		int t = x[i]-'a'+1;
		if(t<C);
		else if(C==t) C++;
		else
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	
}