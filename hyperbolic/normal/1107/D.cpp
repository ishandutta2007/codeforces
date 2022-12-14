#include <stdio.h>

char x[10010];
int y[5210][5210];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		int b = (a/4);
		for(int j=1;j<=b;j++)
		{
			int c;
			if('0'<=x[j]&&x[j]<='9') c = x[j]-'0';
			else c = x[j]-'A'+10;
			for(int k=4*j;k>=4*j-3;k--) y[i][k] = c%2, c/=2;
		}
	}
	
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) y[i][j] += y[i][j-1];
	for(int j=1;j<=a;j++) for(int i=1;i<=a;i++) y[i][j] += y[i-1][j];
	
	int ans = 1;
	for(int i=1;i<=a;i++)
	{
		if(a%i==0)
		{
			int b = a/i;
			for(int j=i;j<=a;j+=i)
			{
				for(int k=i;k<=a;k+=i)
				{
					int t = y[j][k] - y[j-i][k] - y[j][k-i] + y[j-i][k-i];
					if(t==0 || t==i*i);
					else goto u;
				}
			}
			ans = i;
			u:;
		}
	}
	printf("%d",ans);
}