#include <stdio.h>
char x[100010];
int main()
{
	int a,b,c;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		scanf("%d %d",&b,&c);
		if(b>=2400 && c>b)
		{
			printf("YES");
			return 0;
		}
	}
	printf("NO");
}