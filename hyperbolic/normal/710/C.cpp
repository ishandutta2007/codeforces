#include <stdio.h>
#include <vector>

std::vector<int> V[3];
int ans[110][110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a*a;i++) V[i%2].push_back(i);
	
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) ans[i][j] = 1;
	int p = 0;
	for(int i=1;i<=(a-1)/2;i++)
	{
		for(int j=1;j<=(a-1)/2;j++)
		{
			if(p==V[0].size()) goto u;
			p+=4;
			ans[i][j] = ans[a-i+1][j] = ans[i][a-j+1] = ans[a-i+1][a-j+1] = 0;
		}
	}
	u:;
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(ans[i][j]==1)
			{
				printf("%d ",V[1].back());
				V[1].pop_back();
			}
			else
			{
				printf("%d ",V[0].back());
				V[0].pop_back();
			}
		}
		printf("\n");
	}
}