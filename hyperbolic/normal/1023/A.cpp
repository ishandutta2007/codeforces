#include <stdio.h>

char x[200010],y[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	scanf("%s%s",x+1,y+1);
	
	int p = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='*')
		{
			p = i;
			break;
		}
	}
	
	if(p==0)
	{
		if(a!=b)
		{
			printf("NO");
			return 0;
		}
		for(int i=1;i<=a;i++)
		{
			if(x[i]!=y[i])
			{
				printf("NO");
				return 0;
			}
		}
		printf("YES");
		return 0;
	}
	else
	{
		if(a>b+1)
		{
			printf("NO");
			return 0;
		}
		for(int i=1;i<p;i++)
		{
			if(x[i]!=y[i])
			{
				printf("NO");
				return 0;
			}
		}
		for(int i=p+1;i<=a;i++)
		{
			if(x[i]!=y[b+i-a])
			{
				printf("NO");
				return 0;
			}
		}
		printf("YES");
		return 0;
	}
}