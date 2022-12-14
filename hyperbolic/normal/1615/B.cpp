#include <stdio.h>

int count[41][200010];
int main()
{
	for(int i=0;i<=200000;i++) for(int j=0;j<=20;j++) if(((i>>j)&1)==0) count[j][i]++;
	for(int j=0;j<=20;j++) for(int i=1;i<=200000;i++) count[j][i] += count[j][i-1];
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int ans = 12345678;
		for(int j=0;j<=20;j++)
		{
			int t = count[j][b] - count[j][a-1];
			ans = ans<t?ans:t;
		}
		printf("%d\n",ans);
	}
}