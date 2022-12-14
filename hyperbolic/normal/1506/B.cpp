#include <stdio.h>

char x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		
		int ans = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='*')
			{
				x[i] = 'x';
				ans++;
				break;
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='x')
			{
				for(int j=(i+b<a?i+b:a);j>=i+1;j--)
				{
					if(x[j]=='*')
					{
						x[j] = 'x';
						ans++;
						for(int k=j-1;k>=i+1;k--) if(x[k]=='*') x[k] = '.';
						break;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}