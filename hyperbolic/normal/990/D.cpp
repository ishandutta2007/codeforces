#include <stdio.h>

int ans[1010][1010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a==1&&b==1&&c==1)
	{
		printf("YES\n");
		printf("0");
		return 0;
	}
	
	if(b>1&&c>1)
	{
		printf("NO");
		return 0;
	}
	else if(b==1&&c==1)
	{
		if(a<=3)
		{
			printf("NO");
			return 0;
		}
		
		for(int i=1;i<=a;i++) for(int j=i+1;j<=a;j++) ans[i][j] = ans[j][i] = 0;
		for(int i=1;i<a;i++) ans[i][i+1] = ans[i+1][i] = 1;
	}
	else if(c==1)
	{
		for(int i=1;i<=a;i++) for(int j=i+1;j<=a;j++) ans[i][j] = ans[j][i] = 1;
		
		for(int i=2;i<=b;i++)
		{
			int s = i-1;
			for(int j=s+1;j<=a;j++) ans[s][j] = ans[j][s] = 0;
		}
	}
	else if(b==1)
	{
		for(int i=1;i<=a;i++) for(int j=i+1;j<=a;j++) ans[i][j] = ans[j][i] = 0;
		
		for(int i=2;i<=c;i++)
		{
			int s = i-1;
			for(int j=s+1;j<=a;j++) ans[s][j] = ans[j][s] = 1;
		}
	}
	
	printf("YES\n");
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++) printf("%d",ans[i][j]);
		printf("\n");
	}
}