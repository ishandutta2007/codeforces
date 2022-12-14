#include <stdio.h>

char x[110][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) x[i][j] -= '0';
		
		int ans = 0;
		for(int i=1;i<=(a+1)/2;i++)
		{
			for(int j=1;j<=a/2;j++)
			{
				int s = 0;
				s += x[i][j];
				s += x[j][a-i+1];
				s += x[a-i+1][a-j+1];
				s += x[a-j+1][i];
				int t = 4-s;
				ans += (s<t?s:t);
			}
		}
		printf("%d\n",ans);
	}
}