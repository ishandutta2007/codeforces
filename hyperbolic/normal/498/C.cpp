#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#define MAX 12345678

struct FlowGraph{
	int capacity[1010][1010];
	std::vector<int> V[1010];
	int source, sink;
	FlowGraph()
	{
		for(int i=0;i<=1000;i++) for(int j=0;j<=1000;j++) capacity[i][j] = 0;
	}
	
	int level[2010];
	void setEdge(int s, int e, int k)
	{
		V[s].push_back(e);
		V[e].push_back(s);
		capacity[s][e] = k;
	}
	void makeLevel()
	{
		std::queue<int> Q;
		for(int i=0;i<=1001;i++) level[i] = 0;
		Q.push(source);
		level[source] = 1;
		while(!Q.empty())
		{
			int k = Q.front();
			Q.pop();
			for(int i=0;i<V[k].size();i++)
			{
				if(capacity[k][V[k][i]]>0&&level[V[k][i]]==0)
				{
					level[V[k][i]] = level[k]+1;
					Q.push(V[k][i]);
				}
			}
		}
	}
	
	int start[2010];
	int findPath(int v, int minflow)
	{
		if(v==sink) return minflow;
		for(int i=start[v];i<V[v].size();i++)
		{
			if(capacity[v][V[v][i]]>0&&level[V[v][i]]>level[v])
			{
				int f = findPath(V[v][i],minflow<capacity[v][V[v][i]]?minflow:capacity[v][V[v][i]]);
				if(f>0)
				{
					capacity[v][V[v][i]] -= f;
					capacity[V[v][i]][v] += f;
					return f;
				}
			}
			start[v] = i+1;
		}
		return 0;
	}
	int getFlow()
	{
		int ans = 0;
		while(1)
		{
			for(int i=0;i<=1001;i++) start[i] = 0;
			makeLevel();
			if(level[sink]==0) return ans;
			while(1)
			{
				int f = findPath(source,MAX);
				if(f==0) break;
				ans += f;
			}
		}
		
	}
}F;

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

std::vector< std::pair<int,int> > index1,index2;
std::map< std::pair<int,int> ,int> hash;
int x[110];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i+=2)
	{
		int k = x[i];
		for(int j=2;j*j<=x[i];j++)
		{
			if(k%j==0)
			{
				index1.push_back(std::make_pair(i,j));
				while(k%j==0) k/=j;
			}
		}
		if(k>1) index1.push_back(std::make_pair(i,k));
	}
	for(int i=2;i<=a;i+=2)
	{
		int k = x[i];
		for(int j=2;j*j<=x[i];j++)
		{
			if(k%j==0)
			{
				index2.push_back(std::make_pair(i,j));
				while(k%j==0) k/=j;
			}
		}
		if(k>1) index2.push_back(std::make_pair(i,k));
	}
	std::sort(index1.begin(),index1.end());
	index1.erase(std::unique(index1.begin(),index1.end()),index1.end());
	for(int i=0;i<index1.size();i++) hash[index1[i]] = i;
	int C = index1.size();
	std::sort(index2.begin(),index2.end());
	index2.erase(std::unique(index2.begin(),index2.end()),index2.end());
	for(int i=0;i<index2.size();i++) hash[index2[i]] = i+C;
	C += index2.size();
	F.source = C;
	F.sink = C+1;
	for(int i=0;i<index1.size();i++)
	{
		int s = x[index1[i].first];
		int t = index1[i].second;
		int k = 0;
		while(s%t==0) k++,s/=t;
		F.setEdge(C,hash[index1[i]],k);
	}
	for(int i=0;i<index2.size();i++)
	{
		int s = x[index2[i].first];
		int t = index2[i].second;
		int k = 0;
		while(s%t==0) k++,s/=t;
		F.setEdge(hash[index2[i]],C+1,k);
	}
	
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(c%2==0)
		{
			int e = c;
			c = d;
			d = e;
		}
		int g = gcd(x[c],x[d]);
		int g2 = g;
		for(int j=2;j*j<=g;j++)
		{
			int k = 0;
			while(g2%j==0) k++, g2/=j;
			if(k>0) F.setEdge(hash[std::make_pair(c,j)],hash[std::make_pair(d,j)],k);
		}
		if(g2>1) F.setEdge(hash[std::make_pair(c,g2)],hash[std::make_pair(d,g2)],1);
	}
	
	printf("%d",F.getFlow());
}