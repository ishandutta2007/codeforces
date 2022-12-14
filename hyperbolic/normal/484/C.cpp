#include <stdio.h>
#include <string.h>
#include <vector>

char x[1000010],y[1000010],ans[1000010];

int next[1000010][21];
int func(int k, int h)
{
	if(k==0) return 0;
	
	int k2 = k;
	int h2 = h;
	for(int j=20;j>=0;j--)
	{
		if(h2>=(1<<j))
		{
			h2 -= (1<<j);
			k2 = next[k2][j];
			if(k2==-1) goto u;
		}
	}
	return (h-1) + k2 + 1;
	u:;
	
	k2 = k, h2 = 0;
	for(int j=20;j>=0;j--)
	{
		if(next[k2][j]!=-1)
		{
			k2 = next[k2][j];
			h2 += (1<<j);
		}
	}
	return (h2-1) + 0 + 1;
}

int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	int b;
	scanf("%d",&b);
	while(b--)
	{
		for(int i=0;i<a;i++) y[i] = x[i+1];
		int c,d;
		scanf("%d%d",&c,&d);
		
		std::vector< std::vector<int> > check;
		check.resize((c/d)+1);
		for(int i=0;i<=(c/d);i++) check[i].resize(d+1);
		
		for(int i=0;i<c;i++)
		{
			int s = (i/d);
			int t = (i%d);
			check[s][t] = i+1;
		}
		
		int C = 0;
		for(int j=0;j<d;j++)
		{
			for(int i=0;i<=(c/d);i++)
			{
				if(check[i][j]>0)
				{
					next[check[i][j]-1][0] = C-1;
					C++;
				}
			}
		}
		
		for(int j=1;j<=20;j++)
		{
			for(int i=0;i<c;i++)
			{
				if(next[i][j-1]==-1) next[i][j] = -1;
				else next[i][j] = next[next[i][j-1]][j-1];
			}
		}
		
		for(int i=0;i<c;i++) ans[func(i,a-c+1)] = y[i];
		for(int i=c;i<a;i++) ans[(i-c+1)+func(c-1,a-i)] = y[i];
		
		for(int i=0;i<a;i++) x[i+1] = ans[i];
		for(int i=0;i<a;i++) printf("%c",ans[i]);
		printf("\n");
	}
}