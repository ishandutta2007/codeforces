#include <stdio.h>
#include <vector>

int ans[200010],ans2[200010],x[200010];
std::vector<int> V[200010];
int init(int k)
{
	int sum = ans[k];
	for(int i=0;i<V[k].size();i++) sum += init(V[k][i]);
	return ans2[k] = sum;
}

std::pair<int,long long int> next[200010][21];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=2;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		next[i][0] = std::make_pair(b,c);
		V[b].push_back(i);
	}
	
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i<=a;i++)
		{
			next[i][j].first = next[next[i][j-1].first][j-1].first;
			next[i][j].second = next[next[i][j-1].first][j-1].second + next[i][j-1].second;
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		long long int sum = 0;
		int p = i;
		for(int j=20;j>=0;j--)
		{
			if(sum + next[p][j].second <= x[i])
			{
				sum += next[p][j].second;
				p = next[p][j].first;
			}
		}
		ans[i]++;
		ans[next[p][0].first]--;
	}
	
	init(1);
	
	for(int i=1;i<=a;i++) printf("%d ",ans2[i]-1);
}