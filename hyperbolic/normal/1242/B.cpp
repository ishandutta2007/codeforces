#include <stdio.h>
#include <vector>
#include <map>

std::map<int,int> hash;
std::vector<int> V[100010];
int dist[1010][1010],check[100010];
std::vector<int> index;

int next[1010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	
	int min = 12345678;
	int ind = -1;
	for(int i=1;i<=a;i++)
	{
		if(min>V[i].size())
		{
			min = V[i].size();
			ind = i;
		}
	}
	
	for(int i=0;i<V[ind].size();i++) check[V[ind][i]] = 1;
	for(int i=1;i<=a;i++) if(check[i]==1) index.push_back(i);
	index.push_back(ind);
	for(int i=0;i<index.size();i++) hash[index[i]] = i;
	
	for(int i=0;i+1<index.size();i++)
	{
		if(index[i]==ind) continue;
		
		int count = 0;
		for(int j=0;j<V[index[i]].size();j++)
		{
			if(check[V[index[i]][j]]==0) count++;
			else
			{
				int t = hash[V[index[i]][j]];
				dist[i][t] = dist[t][i] = 1;
			}
		}
		if(count==a-V[ind].size()) dist[i][index.size()-1] = dist[index.size()-1][i] = 1;
	}
	
	
	for(int i=0;i<index.size();i++) next[i] = i;
	for(int i=0;i<index.size();i++)
	{
		for(int j=0;j<index.size();j++)
		{
			if(dist[i][j]==0)
			{
				next[find(i)] = find(j);
			}
		}
	}
	
	int ans = 0;
	for(int i=0;i<index.size();i++)
	{
		for(int j=0;j<index.size();j++)
		{
			if(dist[i][j]==1)
			{
				int s = find(i);
				int t = find(j);
				if(s!=t)
				{
					ans++;
					next[s] = t;
				}
			}
		}
	}
	printf("%d",ans);
}