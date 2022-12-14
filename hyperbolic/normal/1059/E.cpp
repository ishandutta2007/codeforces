#include <stdio.h>
#include <vector>

std::pair<int,long long int> sparse[100010][30];
int height[100010];
std::vector<int> V[100010];
int x[100010];


int b;
long long int c;
int ANS = 0;
std::pair<int,long long int> func(int k)
{
	
	int ans = height[k]+1;
	std::pair<int,long long int> ansP;
	for(int i=0;i<V[k].size();i++)
	{
		std::pair<int,long long int> P = func(V[k][i]);
		
		int v = V[k][i];
		int length = P.first;
		long long int cost = P.second;
		
		for(int j=20;j>=0;j--)
		{
			if(height[v]-height[sparse[v][j].first]+length<=b&&sparse[v][j].second+cost<=c)
			{
				cost += sparse[v][j].second;
				length += (height[v]-height[sparse[v][j].first]);
				v = sparse[v][j].first;
			}
		}
		
		if(height[v]<ans)
		{
			ans = height[v];
			ansP = P;
		}
	}
	
	//printf("%d : %d %lld!!\n",k,ansP.first+1,ansP.second+x[k]);
	if(ans==height[k]+1)
	{
		ANS++;
		return std::make_pair(1,x[k]);
	}
	else return std::make_pair(ansP.first+1,ansP.second+x[k]);
}



int main()
{
	int a;
	scanf("%d%d%lld",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		if(x[i]>c)
		{
			printf("-1");
			return 0;
		}
	}
	
	height[1] = 1;
	for(int i=2;i<=a;i++)
	{
		int d;
		scanf("%d",&d);
		V[d].push_back(i);
		sparse[i][0] = std::make_pair(d,x[d]);
		height[i] = height[d] + 1;
	}
	sparse[1][0]=std::make_pair(0,0);
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i<=a;i++)
		{
			sparse[i][j].first = sparse[sparse[i][j-1].first][j-1].first;
			sparse[i][j].second = sparse[sparse[i][j-1].first][j-1].second + sparse[i][j-1].second;
		}
	}
	std::pair<int,long long int> P = func(1);
	printf("%d",ANS);
	
}