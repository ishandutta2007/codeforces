#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

int next[100010],x[100010];
std::vector<int> prev[100010][31];
std::vector<int> V1,V2;
int ans[100010],check[100010];
std::map<int,int> hash;
std::set<int> S;
std::vector<int> save[100010];
int count[100010],check2[100010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&next[i]);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	int max = 0;
	for(int i=1;i<=a;i++) max = max>x[i]?max:x[i];
	max -= a;
	
	int C = 0;
	for(int i=1;i<=a;i++)
	{
		if(check[next[i]]) C++;
		else check[next[i]] = 1;
	}
	int b = max/C;
	
	for(int i=1;i<=a;i++) prev[next[i]][0].push_back(i);
	for(int j=1;j<=30;j++)
	{
		for(int i=1;i<=a;i++)
		{
			for(int k=0;k<prev[i][j-1].size();k++)
			{
				int t = prev[i][j-1][k];
				for(int l=0;l<prev[t][j-1].size();l++) prev[i][j].push_back(prev[t][j-1][l]);
			}
		}
	}
	
	
	for(int i=1;i<=a;i++) if(x[i]<=a) hash[x[i]] = i;
	for(int i=1;i<=a;i++)
	{
		if(hash.find(i)!=hash.end())
		{
			V1.clear();
			int b2 = b;
			V1.push_back(hash[i]);
			for(int j=30;j>=0;j--)
			{
				if(b2>=(1<<j))
				{
					V2.clear();
					for(int k=0;k<V1.size();k++)
					{
						for(int l=0;l<prev[V1[k]][j].size();l++)
						{
							V2.push_back(prev[V1[k]][j][l]);
						}
					}
					V1.clear();
					for(int k=0;k<V2.size();k++) V1.push_back(V2[k]);
					b2 -= (1<<j);
				}
			}
			std::sort(V1.begin(),V1.end());
			for(int j=0;j<V1.size();j++) save[i].push_back(V1[j]);
			check2[i] = 1;
			for(int j=0;j<V1.size();j++) count[V1[j]]++;
		}
	}
	
	for(int i=1;i<=a;i++) if(count[i]==0) S.insert(i);
	
	for(int i=1;i<=a;i++)
	{
		if(check2[i]==1)
		{
			for(int j=0;j<save[i].size();j++)
			{
				if(ans[save[i][j]]==0)
				{
					ans[save[i][j]] = i;
					for(int k=0;k<save[i].size();k++) S.insert(save[i][k]);
					S.erase(save[i][j]);
					break;
				}
			}
		}
		else
		{
			std::set<int> ::iterator it = S.begin();
			ans[*it] = i;
			S.erase(it);
		}
	}
	
	for(int i=1;i<=a;i++) printf("%d ",ans[i]);
}