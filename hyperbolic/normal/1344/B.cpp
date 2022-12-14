#include <stdio.h>

char x[1010][1010];
int check[1010][1010],a,b;
int S[1010],T[1010];

void func(int s, int t, int color)
{
	check[s][t] = color;
	if(x[s+1][t]=='#' && check[s+1][t] == 0) func(s+1,t,color);
	if(x[s-1][t]=='#' && check[s-1][t] == 0) func(s-1,t,color);
	if(x[s][t+1]=='#' && check[s][t+1] == 0) func(s,t+1,color);
	if(x[s][t-1]=='#' && check[s][t-1] == 0) func(s,t-1,color);
}


int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='#')
			{
				S[i] = 1;
				T[j] = 1;
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		int L = b+1, R = 0;
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='#')
			{
				L = j;
				break;
			}
		}
		for(int j=b;j>=1;j--)
		{
			if(x[i][j]=='#')
			{
				R = j;
				break;
			}
		}
		
		if(L==b+1 && R==0)
		{
			for(int j=1;j<=b;j++) if(T[j]==0) goto v1;
			printf("-1");
			return 0;
			v1:;
		}
		
		for(int j=L;j<=R;j++)
		{
			if(x[i][j]=='.')
			{
				printf("-1");
				return 0;
			}
		}
	}
	
	for(int j=1;j<=b;j++)
	{
		int L = a+1, R = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i][j]=='#')
			{
				L = i;
				break;
			}
		}
		for(int i=a;i>=1;i--)
		{
			if(x[i][j]=='#')
			{
				R = i;
				break;
			}
		}
		
		if(L==a+1 && R==0)
		{
			for(int i=1;i<=a;i++) if(S[i]==0) goto v2;
			printf("-1");
			return 0;
			v2:;
		}
		
		for(int i=L;i<=R;i++)
		{
			if(x[i][j]=='.')
			{
				printf("-1");
				return 0;
			}
		}
	}
	
	
	int C = 1;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='#' && check[i][j]==0)
			{
				func(i,j,C++);
			}
		}
	}
	printf("%d",C-1);
}