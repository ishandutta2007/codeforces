#include <stdio.h>
#include <string.h>
char x[1010];
int check[1010];
int main()
{
	int a;
	scanf("%s",x+1);
	a = strlen(x+1);
	int b = 0, c = 0;
	for(int i=1;i<a;i++)
	{
		if(x[i]=='V'&&x[i+1]=='K')
		{
			b++;
			check[i] = 1;
			check[i+1] = 1;
		}
	}
	for(int i=1;i<a;i++)
	{
		if(check[i]==0&&check[i+1]==0)
		{
			if(x[i]==x[i+1])
			{
				printf("%d",b+1);
				return 0;
			}
		}
	}
	printf("%d",b);
}