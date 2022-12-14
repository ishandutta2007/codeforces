#include <stdio.h>

char x[500010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		int p = 1;
		int ans = 0;
		while(p+1<=a)
		{
			if(x[p]==')'&&x[p+1]=='(')
			{
				if(p+2>a) break;
				for(int j=p+2;j<=a;j++)
				{
					if(x[j]==')')
					{
						ans++;
						p = j+1;
						goto u;
					}
				}
				break;
				u:;
			}
			else ans++, p+=2;
		}
		printf("%d %d\n",ans,a-p+1);
	}
}