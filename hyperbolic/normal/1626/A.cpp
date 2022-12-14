#include <stdio.h>
#include <string.h>
#include <algorithm>
char x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		std::sort(x+1,x+a+1);
		printf("%s\n",x+1);
	}
}