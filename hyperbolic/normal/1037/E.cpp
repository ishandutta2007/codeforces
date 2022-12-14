#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

struct str{
	int x0;
	int y0;
};

bool cmp(str a,str b)
{
	return a.y0<b.y0;
}

int score[200010],check[200010];

std::queue<int> Q;
std::vector<str> V[200010];
std::pair<int,int> P[200010];
int ans[200010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		V[d].push_back({e,i});
		V[e].push_back({d,i});
		P[i] = std::make_pair(d,e);
	}
	for(int i=1;i<=a;i++) std::sort(V[i].begin(),V[i].end(),cmp);
	
	int count = a;
	for(int i=1;i<=a;i++) check[i] = 1;
	for(int i=1;i<=a;i++) score[i] = V[i].size();
	for(int i=1;i<=a;i++)
	{
		if(score[i]<c)
		{
			count--;
			check[i] = 0;
			Q.push(i);
		}
	}
	while(!Q.empty())
	{
		int k = Q.front();
		Q.pop();
		for(int i=0;i<V[k].size();i++)
		{
			score[V[k][i].x0]--;
			if(score[V[k][i].x0]<c && check[V[k][i].x0]==1)
			{
				count--;
				check[V[k][i].x0] = 0;
				Q.push(V[k][i].x0);
			}
		}
	}
	
	ans[b] = count;
	
	
	for(int i=b;i>=2;i--)
	{
		if(check[P[i].first]==1&&check[P[i].second]==1)
		{
			score[P[i].first]--;
			score[P[i].second]--;
			if(score[P[i].first]<c)
			{
				count--;
				check[P[i].first] = 0;
				Q.push(P[i].first);
			}
			if(score[P[i].second]<c)
			{
				count--;
				check[P[i].second] = 0;
				Q.push(P[i].second);
			}
		}
		while(!Q.empty())
		{
			int k = Q.front();
			Q.pop();
			for(int j=0;j<V[k].size();j++)
			{
				if(V[k][j].y0>=i) break;
				score[V[k][j].x0]--;
				if(score[V[k][j].x0]<c && check[V[k][j].x0]==1)
				{
					count--;
					check[V[k][j].x0] = 0;
					Q.push(V[k][j].x0);
				}
			}
		}
		ans[i-1] = count;
	}
	for(int i=1;i<=b;i++) printf("%d\n",ans[i]);
}