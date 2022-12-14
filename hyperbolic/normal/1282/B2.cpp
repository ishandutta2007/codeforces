#include <stdio.h>
#include <algorithm>

int x[200010],s[200010];
int main()
{
	int Case;
	scanf("%d",&Case);
	for(int T=1;T<=Case;T++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		for(int i=1;i<=c-1;i++) s[i] = s[i-1]+x[i];
		for(int i=c;i<=a;i++) s[i] = s[i-c] + x[i];
		
		for(int i=a;i>=1;i--)
		{
			if(s[i]<=b)
			{
				printf("%d\n",i);
				goto u;
			}
		}
		printf("0\n");
		u:;
	}
}