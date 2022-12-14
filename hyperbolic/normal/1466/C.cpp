#include <stdio.h>
#include <string.h>

char x[100010];
int a;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		a = strlen(x+1);
		int s = 0, t = 0;
		int ans = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='a'+s-1)
			{
				ans++;
				s = t;
				t = 0;
			}
			else if(x[i]=='a'+t-1)
			{
				ans++;
				s = t;
				t = 0;
			}
			else
			{
				s = t;
				t = x[i]-'a'+1;
			}
		}
		printf("%d\n",ans);
	}
}