#include <stdio.h>
#include <string.h>

char x[100010],y[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s%s",x+1,y+1);
		int b = strlen(x+1);
		int c = strlen(y+1);
		int p1 = b, p2 = c;
		for(int j=c;j>=1;j--)
		{
			if(y[j]=='1')
			{
				p2 = j;
				break;
			}
		}
		for(int j=b-c+p2;j>=1;j--)
		{
			if(x[j]=='1')
			{
				p1 = j;
				break;
			}
		}
		printf("%d\n",(b-p1)-(c-p2));
	}
}