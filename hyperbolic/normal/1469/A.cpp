#include <stdio.h>
#include <string.h>

char x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		if(a%2==1) printf("NO\n");
		else
		{
			if(x[1]==')') printf("NO\n");
			else if(x[a]=='(') printf("NO\n");
			else printf("YES\n");
		}
	}
}