#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#define MAX (long long int)1e18

struct str{
	int first;
	int second;
	int value;
};
std::vector<str> edge;

int prev[100010];
int height[100010];
std::pair<int,long long int> next[100010][30];
std::vector< std::pair<int,int> > V[100010];

void init(int k, int p, int h)
{
	prev[k] = p;
	height[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==p) continue;
		if(height[V[k][i].first]>0)
		{
			edge.push_back({k,V[k][i].first,V[k][i].second});
			continue;
		}
		
		next[V[k][i].first][0].first = k;
		next[V[k][i].first][0].second = V[k][i].second;
		init(V[k][i].first,k,h+1);
	}
}

long long int LCA(int s, int t)
{
	long long int ans = 0;
	if(height[s]>height[t])
	{
		int k = height[s]-height[t];
		for(int i=20;i>=0;i--)
		{
			if((1<<i)<=k)
			{
				k -= (1<<i);
				ans += next[s][i].second;
				s = next[s][i].first;
			}
		}
	}
	if(height[s]<height[t])
	{
		int k = height[t]-height[s];
		for(int i=20;i>=0;i--)
		{
			if((1<<i)<=k)
			{
				k -= (1<<i);
				ans += next[t][i].second;
				t = next[t][i].first;
			}
		}
	}
	for(int i=20;i>=0;i--)
	{
		if(next[s][i].first!=next[t][i].first)
		{
			ans += next[s][i].second;
			ans += next[t][i].second;
			s = next[s][i].first;
			t = next[t][i].first;
		}
	}
	if(s!=t) ans += next[s][0].second, ans += next[t][0].second;
	return ans;
}

std::vector<int> index;
std::map<int,int> hash;

long long int dist[50][50],save[50][50];
long long int check[50];
long long int check1[50],check2[50];

struct str2{
	long long int first;
	int second;
};
bool operator<(str2 a, str2 b)
{
	return a.first>b.first;
}

std::priority_queue<str2> Q;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		V[c].push_back(std::make_pair(d,e));
		V[d].push_back(std::make_pair(c,e));
	}
	init(1,0,1);
	
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i<=a;i++)
		{
			next[i][j].second = next[i][j-1].second + next[next[i][j-1].first][j-1].second;
			next[i][j].first = next[next[i][j-1].first][j-1].first;
		}
	}
	
	for(int i=0;i<edge.size();i++)
	{
		index.push_back(edge[i].first);
		index.push_back(edge[i].second);
	}
	
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
	
	for(int i=1;i<=index.size();i++) for(int j=i+1;j<=index.size();j++) save[i][j] = LCA(index[i-1],index[j-1]);
	for(int i=1;i<=index.size();i++) for(int j=i+1;j<=index.size();j++) save[j][i] = LCA(index[i-1],index[j-1]);
	for(int i=0;i<edge.size();i++) save[hash[edge[i].first]][hash[edge[i].second]] = edge[i].value;
	for(int i=0;i<edge.size();i++) save[hash[edge[i].second]][hash[edge[i].first]] = edge[i].value;
	
	for(int i=0;i<=index.size()+1;i++)
	{
		for(int j=1;j<=index.size();j++)
		{
			for(int k=1;k<=index.size();k++)
			{
				for(int l=1;l<=index.size();l++)
				{
					save[j][k] = save[j][k] < save[j][l]+save[l][k]? save[j][k] : save[j][l]+save[l][k];
				}
			}
		}
	}
	
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		long long int ans = LCA(d,e);
		for(int i=1;i<=index.size();i++) check1[i] = LCA(d,index[i-1]);
		for(int i=1;i<=index.size();i++) check2[i] = LCA(e,index[i-1]);
		for(int i=1;i<=index.size();i++)
		{
			for(int j=1;j<=index.size();j++)
			{
				long long int temp = check1[i]+check2[j]+save[i][j];
				ans = ans<temp?ans:temp;
			}
		}
		printf("%lld\n",ans);
	}
}