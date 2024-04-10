#include <stdio.h>

char x[200010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	scanf("%s",x+1);
	
	int control = 1;
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='*') control = 1;
		else
		{
			if(control==1)
			{
				if(b>c)
				{
					if(b>0)
					{
						ans++;
						b--;
						control = 2;
					}
					else control = 1;
				}
				else
				{
					if(c>0)
					{
						ans++;
						c--;
						control = 3;
					}
					else control = 1;
				}
			}
			else if(control==2)
			{
				if(c>0)
				{
					ans++;
					c--;
					control = 3;
				}
				else control = 1;
			}
			else
			{
				if(b>0)
				{
					ans++;
					b--;
					control = 2;
				}
				else control = 1;
			}
		}
	}
	printf("%d",ans);
}