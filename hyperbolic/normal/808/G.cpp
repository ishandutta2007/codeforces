#include <stdio.h>
#include <vector>
#include <string.h>

char x[100010],y[100010];
int fail[100010];
std::vector<int> V;

int DP[100010],max[100010],check[100010];
int main()
{
	scanf("%s%s",x+1,y+1);
	int a = strlen(x+1);
	int b = strlen(y+1);
	if(b>a)
	{
		printf("0");
		return 0;
	}
	
	fail[1] = 0;
	for(int i=2;i<=b;i++)
	{
		int t = fail[i-1];
		while(1)
		{
			if(y[t+1]==y[i])
			{
				fail[i] = t+1;
				break;
			}
			else
			{
				if(t==0)
				{
					fail[i] = 0;
					break;
				}
				else t = fail[t];
			}
		}
	}
	
	
	int p = b;
	while(fail[p]!=0)
	{
		V.push_back(b-fail[p]);
		p = fail[p];
	}
	
	for(int i=1;i+b-1<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i+j-1]=='?') continue;
			if(x[i+j-1]!=y[j]) goto u;
		}
		check[i] = 1;
		u:;
	}
	
	for(int i=1;i+b-1<=a;i++)
	{
		if(check[i]==0) DP[i] = -1;
		else
		{
			int C = 0;
			if(i-b>=1) C = max[i-b];
			for(int j=0;j<V.size();j++)
			{
				if(i-V[j]>=1&&check[i-V[j]]==1)
				{
					int t = DP[i-V[j]];
					C = C>t?C:t;
				}
			}
			DP[i] = C+1;
		}
		max[i] = DP[i]>max[i-1]?DP[i]:max[i-1];
	}
	printf("%d",max[a-b+1]);
}