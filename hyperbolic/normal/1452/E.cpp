#include <stdio.h>

int max(int a, int b)
{
	return a>b?a:b;
}
int min(int a, int b)
{
	return a<b?a:b;
}

int check[6010];
int limitL[2010],limitR[2010];
int sum[6010][6010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		d+=a;
		e+=a;
		int len = (e-d+1)<c?(e-d+1):c;
		for(int j=1;j+c-1<=3*a;j++)
		{
			int L = j;
			int R = j+c-1;
			check[j] = max(0,min(R,e)-max(L,d)+1);
		}
		for(int j=0;j<=len;j++)
		{
			limitL[j] = 3*a+1;
			limitR[j] = -1;
		}
		
		for(int j=1;j+c-1<=3*a;j++)
		{
			limitL[check[j]] = limitL[check[j]]<j?limitL[check[j]]:j;
			limitR[check[j]] = limitR[check[j]]>j?limitR[check[j]]:j;
		}
		
		for(int j=1;j+c-1<=3*a;j++)
		{
			sum[j][1] += check[j];
			sum[j][2] -= check[j];
			if(check[j]!=len)
			{
				sum[j][limitL[check[j]+1]]++;
				sum[j][limitL[len]+1]--;
				sum[j][limitR[len]+1]--;
				sum[j][limitR[check[j]+1]+2]++;
			}
		}
		
	}
	
	int ans = 0;
	for(int i=1;i<=3*a;i++)
	{
		int S = 0;
		int val = 0;
		for(int j=1;j<=3*a;j++)
		{
			S += sum[i][j];
			val += S;
			if(a<=i&&i+c-1<=2*a&&a<=j&&j+c-1<=2*a) ans = ans>val?ans:val;
		}
	}
	printf("%d",ans);
}