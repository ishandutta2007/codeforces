#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

int x[1010][1010],y[1010][1010];

int possible(int s, int t)
{
	std::vector<int> temp;
	if(y[s][t]>0) temp.push_back(y[s][t]);
	if(y[s+1][t]>0) temp.push_back(y[s+1][t]);
	if(y[s][t+1]>0) temp.push_back(y[s][t+1]);
	if(y[s+1][t+1]>0) temp.push_back(y[s+1][t+1]);
	if(temp.empty()) return 1;
	else
	{
		std::sort(temp.begin(),temp.end());
		temp.erase(std::unique(temp.begin(),temp.end()),temp.end());
		if(temp.size()>1) return 0;
		else return temp[0];
	}
}

std::queue< std::pair<int,int> > Q;

struct str{
	int first;
	int second;
	int value;
};
std::vector<str> ans;
int check[1010][1010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) y[i][j] = x[i][j];
	
	for(int i=1;i<a;i++)
	{
		for(int j=1;j<b;j++)
		{
			if(possible(i,j))
			{
				Q.push(std::make_pair(i,j));
			}
		}
	}
	
	while(!Q.empty())
	{
		int s = Q.front().first;
		int t = Q.front().second;
		Q.pop();
		if(check[s][t]) continue;
		check[s][t] = 1;
		ans.push_back({s,t,possible(s,t)});
		y[s][t] = y[s+1][t] = y[s][t+1] = y[s+1][t+1] = 0;
		
		for(int i=s-1;i<=s+1;i++)
		{
			for(int j=t-1;j<=t+1;j++)
			{
				if(1<=i&&i<a&&1<=j&&j<b)
				{
					if(possible(i,j))
					{
						Q.push(std::make_pair(i,j));
					}
				}
			}
		}
	}
	
	std::reverse(ans.begin(),ans.end());
	
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) y[i][j] = 0;
	
	for(int i=0;i<ans.size();i++)
	{
		int s = ans[i].first, t = ans[i].second;
		y[s][t] = y[s+1][t] = y[s][t+1] = y[s+1][t+1] = ans[i].value;
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]!=y[i][j])
			{
				printf("-1");
				return 0;
			}
		}
	}
	
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d %d %d\n",ans[i].first,ans[i].second,ans[i].value);
}