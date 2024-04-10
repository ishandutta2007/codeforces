#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		if(c%3==0)
		{
			if(b<c) printf("%s\n",b%3==0?"Bob":"Alice");
			else
			{
				int s = (b-c)%(c+1);
				printf("%s\n",s%3==1?"Bob":"Alice");
			}
		}
		else printf("%s\n",b%3==0?"Bob":"Alice");
	}
}