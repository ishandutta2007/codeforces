#include <stdio.h>

char x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		int last = -1;
		int ans = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='0')
			{
				if(last!=-1 && last+3 >i) ans += (2-(i-1 - (last+1)+1));
				last = i;
			}
		}
		printf("%d\n",ans);
	}
}