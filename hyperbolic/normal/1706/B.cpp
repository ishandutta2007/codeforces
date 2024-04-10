#include <stdio.h>

int ans[100010],x[100010],last[100010][3];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) for(int j=0;j<=1;j++) last[i][j] = 0;
		
		for(int i=a;i>=1;i--)
		{
			if(last[x[i]][1-i%2]!=0) ans[i] = ans[last[x[i]][1-i%2]] + 1;
			else ans[i] = 1;
			last[x[i]][i%2] = i;
		}
		
		for(int i=1;i<=a;i++)
		{
			int s1 = last[i][0], s2 = last[i][1];
			printf("%d ",ans[s1]>ans[s2]?ans[s1]:ans[s2]);
		}
		printf("\n");
	}
}