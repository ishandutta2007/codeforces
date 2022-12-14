#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

std::set< std::pair<int,int> > S[110];
std::vector< std::pair<int,int> > save[110];
std::vector< std::pair<int,int> > edge;
int check2[110];

void func(int k, int prev)
{
	if(check2[k]) return;
	check2[k] = 1;
	for(int i=0;i<save[k].size();i++)
	{
		if(save[k][i].first==prev)
		{
			edge.push_back(std::make_pair(k,save[k][i].second));
			func(save[k][i].second,k);
		}
		if(save[k][i].second==prev)
		{
			edge.push_back(std::make_pair(k,save[k][i].first));
			func(save[k][i].first,k);
		}
	}
}

int next[110][110],height[110];
std::vector<int> V[110];
void init(int k, int prev, int h)
{
	if(height[k]>0) return;
	
	next[k][0] = prev;
	height[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		init(V[k][i],k,h+1);
	}
}

int dist(int s, int t)
{
	int ans = 0;
	if(height[s]<height[t])
	{
		int k = height[t]-height[s];
		for(int i=10;i>=0;i--)
		{
			if(k>=(1<<i))
			{
				k -= (1<<i);
				ans += (1<<i);
				t = next[t][i];
			}
		}
	}
	if(height[s]>height[t])
	{
		int k = height[s]-height[t];
		for(int i=10;i>=0;i--)
		{
			if(k>=(1<<i))
			{
				k -= (1<<i);
				ans += (1<<i);
				s = next[s][i];
			}
		}
	}
	
	for(int i=10;i>=0;i--)
	{
		if(next[s][i]!=next[t][i])
		{
			s = next[s][i];
			t = next[t][i];
			ans += 2*(1<<i);
		}
	}
	if(s!=t) return ans+2;
	else return ans;
}

int check[110][110][110];
char x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		edge.clear();
		for(int i=1;i<=a;i++) save[i].clear();
		for(int i=1;i<=a;i++) S[i].clear();
		for(int i=1;i<=a;i++) check2[i] = 0;
		
		if(a==2)
		{
			scanf("%s",x+1);
			int control = 0;
			for(int k=1;k<=a;k++) if(x[k]=='1') control = 1;
			if(control==1) printf("No\n");
			else
			{
				printf("Yes\n");
				printf("1 2\n");
			}
			continue;
		}
		
		for(int i=1;i<a;i++)
		{
			for(int j=1;j<=a-i;j++)
			{
				scanf("%s",x+1);
				for(int k=1;k<=a;k++) if(x[k]=='1') save[k].push_back(std::make_pair(i,i+j));
			}
		}
		int leaf = -1, root = -1;
		for(int i=1;i<=a;i++) if(save[i].size()==0) leaf = i;
		
		if(leaf==-1)
		{
			for(int i=1;i<=a;i++) for(int j=0;j<save[i].size();j++) S[i].insert(save[i][j]);
			for(int i=1;i<=a;i++)
			{
				std::vector< std::pair<int,int> > temp;
				for(int j=1;j<=a;j++)
				{
					if(i==j) continue;
					for(int k=0;k<save[i].size();k++) if(S[j].find(save[i][k])==S[j].end()) goto u2;
					temp.push_back(std::make_pair(save[j].size(),j));
					u2:;
				}
				if(temp.size()>0)
				{
					std::sort(temp.begin(),temp.end());
					leaf = i;
					root = temp[0].second;
					break;
				}
			}
		}
		else
		{
			for(int i=1;i<=a;i++)
			{
				if(i==leaf) continue;
				int C = 0;
				for(int j=0;j<save[i].size();j++)
				{
					if(save[i][j].first==leaf) C++;
					if(save[i][j].second==leaf) C++;
				}
				if(C>0 && save[i].size()==1)
				{
					root = i;
					break;
				}
			}
		}
		
		if(leaf==-1)
		{
			printf("No\n");
			continue;
		}
		if(root==-1)
		{
			printf("No\n");
			continue;
		}
		
		check2[leaf] = 1;
		edge.push_back(std::make_pair(leaf,root));
		func(root,leaf);
		
		if(edge.size()!=a-1)
		{
			printf("No\n");
			continue;
		}
		
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) for(int k=1;k<=a;k++) check[i][j][k] = 0;
		for(int i=1;i<=a;i++) height[i] = 0;
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=0;i<edge.size();i++)
		{
			V[edge[i].first].push_back(edge[i].second);
			V[edge[i].second].push_back(edge[i].first);
		}
		
		init(leaf,leaf,1);
		int control = 0;
		for(int i=1;i<=a;i++) if(height[i]==0) control = 1;
		if(control)
		{
			printf("No\n");
			continue;
		}
		for(int j=1;j<=10;j++) for(int i=1;i<=a;i++) next[i][j] = next[next[i][j-1]][j-1];
		
		for(int i=1;i<=a;i++) for(int j=0;j<save[i].size();j++) check[save[i][j].first][save[i][j].second][i] = 1;
		for(int i=1;i<=a;i++)
		{
			for(int j=i+1;j<=a;j++)
			{
				for(int k=1;k<=a;k++)
				{
					int s1 = dist(i,k), s2 = dist(j,k);
					if(check[i][j][k]==0 && s1==s2)
					{
						printf("No\n");
						goto u;
					}
					if(check[i][j][k]==1 && s1!=s2)
					{
						printf("No\n");
						goto u;
					}
				}
			}
		}
		
		printf("Yes\n");
		for(int i=0;i<edge.size();i++) printf("%d %d\n",edge[i].first,edge[i].second);
		u:;
	}
}