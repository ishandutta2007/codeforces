#include <stdio.h>

char x[5010],y[5010];
int check[5010][5100];
int func(int s, int t)
{
	if(s==0) return 0;
	if(t==0) return 0;
	if(check[s][t]!=-1) return check[s][t];
	
	int s1 = func(s-1,t)-1;
	int s2 = func(s,t-1)-1;
	int s3 = 0;
	for(int i=s;i>=s-2&&i>=1;i--)
	{
		if(x[i]==y[t])
		{
			int k = func(i-1,t-1)+4-1-(s-i+1);
			s3 = s3>k?s3:k;
		}
	}
	for(int i=t;i>=t-2&&i>=1;i--)
	{
		if(x[s]==y[i])
		{
			int k = func(s-1,i-1)+4-1-(t-i+1);
			s3 = s3>k?s3:k;
		}
	}
	s3 = s3>s1?s3:s1;
	s3 = s3>s2?s3:s2;
	return check[s][t] = s3;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) check[i][j] = -1;
	
	scanf("%s%s",x+1,y+1);
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			int k = func(i,j);
			ans = ans>k?ans:k;
		}
	}
	printf("%d",ans);
}