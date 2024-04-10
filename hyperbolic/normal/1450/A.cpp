#include <stdio.h>
#include <algorithm>

char x[210];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		std::sort(x+1,x+a+1);
		for(int i=1;i<=a;i++) printf("%c",x[i]);
		printf("\n");
	}
}