#include <stdio.h>
#include <vector>
#define MAX 1234567890

int ans[510][510][30];
struct str{
	int first;
	int second;
	int value;
};
std::vector<str> V[510][510];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(c%2==1)
	{
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				printf("-1 ");
			}
			printf("\n");
		}	
		return 0;
	}
	c/=2;
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<b;j++)
		{
			int d;
			scanf("%d",&d);
			V[i][j].push_back({i,j+1,d});
			V[i][j+1].push_back({i,j,d});
		}
	}
	for(int i=1;i<a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			int d;
			scanf("%d",&d);
			V[i][j].push_back({i+1,j,d});
			V[i+1][j].push_back({i,j,d});
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			int min = MAX;
			for(int k=0;k<V[i][j].size();k++) min = min<V[i][j][k].value?min:V[i][j][k].value;
			ans[i][j][1] = min;
		}
	}
	
	for(int count=2;count<=c;count++)
	{
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				int min = MAX;
				for(int k=0;k<V[i][j].size();k++)
				{
					int t = V[i][j][k].value + ans[V[i][j][k].first][V[i][j][k].second][count-1];
					min = min<t?min:t;
				}
				ans[i][j][count] = min;
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			printf("%d ",2*ans[i][j][c]);
		}
		printf("\n");
	}
}