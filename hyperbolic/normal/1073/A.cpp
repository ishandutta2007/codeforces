#include <stdio.h>

char x[1010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	for(int i=1;i<a;i++)
	{
		if(x[i]!=x[i+1])
		{
			printf("YES\n");
			printf("%c%c",x[i],x[i+1]);
			return 0;
		}
	}
	printf("NO");
}