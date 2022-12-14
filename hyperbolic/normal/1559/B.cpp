#include <stdio.h>

int check[110][10],next[110][10],a;
char x[110];
int func(int k, int prev)
{
	if(k>a) return 0;
	if(check[k][prev]!=-1) return check[k][prev];
	
	if(x[k]=='?')
	{
		int s1 = func(k+1,1);
		int s2 = func(k+1,2);
		if(prev==1) s1++;
		if(prev==2) s2++;
		if(s1<s2)
		{
			next[k][prev] = 1;
			return check[k][prev] = s1;
		}
		else
		{
			next[k][prev] = 2;
			return check[k][prev] = s2;
		}
	}
	else if(x[k]=='R')
	{
		int s1 = func(k+1,1);
		if(prev==1) s1++;
		next[k][prev] = 1;
		return check[k][prev] = s1;
	}
	else
	{
		int s1 = func(k+1,2);
		if(prev==2) s1++;
		next[k][prev] = 2;
		return check[k][prev] = s1;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		scanf("%s",x+1);
		for(int i=0;i<=a;i++) for(int j=0;j<=2;j++) next[i][j] = check[i][j] = -1;
		func(1,0);
		int t = 0;
		for(int i=1;i<=a;i++)
		{
			if(next[i][t]==1)
			{
				printf("R");
				t = 1;
			}
			else
			{
				printf("B");
				t = 2;
			}
		}
		printf("\n");
	}
}