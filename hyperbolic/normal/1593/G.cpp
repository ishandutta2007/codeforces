#include <stdio.h>
#include <string.h>

char x[1000010];
int count[1000010],sum[3][1000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='['||x[i]==']') count[i] = 1;
			else count[i] = 0;
		}
		
		for(int j=0;j<=1;j++) for(int i=1;i<=a;i++) sum[j][i] = 0;
		
		for(int i=1;i<=a;i++) sum[i%2][i] = count[i];
		for(int j=0;j<=1;j++) for(int i=1;i<=a;i++) sum[j][i] += sum[j][i-1];
		
		
		int b;
		scanf("%d",&b);
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			int s1 = sum[0][d] - sum[0][c-1];
			int s2 = sum[1][d] - sum[1][c-1];
			printf("%d\n",s2>s1?s2-s1:s1-s2);
		}
	}
}