#include <stdio.h>

char x[100010],ans[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	scanf("%s",x+1);
	
	for(int i=1;i<=a;i++)
	{
		int c1 = (x[i]-'a');
		int c2 = ('z'-x[i]);
		if(c1>=c2)
		{
			if(c1>b)
			{
				ans[i] = x[i]-b;
				b = 0;
			}
			else
			{
				ans[i] = 'a';
				b -= c1;
			}
		}
		else
		{
			if(c2>b)
			{
				ans[i] = x[i]+b;
				b = 0;
			}
			else
			{
				ans[i] = 'z';
				b -= c2;
			}
		}
	}
	
	if(b>0) printf("-1");
	else for(int i=1;i<=a;i++) printf("%c",ans[i]);
}