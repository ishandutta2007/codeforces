#include <stdio.h>
#include <vector>

std::vector<int> V[1000010];
int next[1000010][21];
int height[1000010];
int up[1000010];

void init(int k, int h)
{
	height[k] = h;
	for(int i=0;i<V[k].size();i++) init(V[k][i],h+1);
}

int func(int k)
{
	if(V[k].size()==0) return up[k];
	
	int ans = k;
	for(int i=0;i<V[k].size();i++)
	{
		int t = func(V[k][i]);
		ans = height[ans]<height[t]?ans:t;
	}
	return up[k] = ans;
}

std::pair<int,int> func2(int k)
{
	if(V[k].size()==0) return {1,0};
	
	int s1 = 0, s2 = 0;
	for(int i=0;i<V[k].size();i++)
	{
		std::pair<int,int> P = func2(V[k][i]);
		if(height[up[V[k][i]]]>height[k]) s2 = s2>P.first+P.second?s2:P.first+P.second;
		else
		{
			s2 = s2>P.second?s2:P.second;
			s1 += P.first;
		}
	}
	return {s1,s2};
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	next[1][0] = 1;
	for(int i=2;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		V[c].push_back(i);
		next[i][0] = c;
	}
	
	for(int j=1;j<=20;j++) for(int i=1;i<=a;i++) next[i][j] = next[next[i][j-1]][j-1];
	
	for(int i=1;i<=a;i++)
	{
		int c = b;
		int p = i;
		for(int j=20;j>=0;j--)
		{
			if(c>=(1<<j))
			{
				c -= (1<<j);
				p = next[p][j];
			}
		}
		up[i] = p;
	}
	
	init(1,1);
	func(1);
	
	std::pair<int,int> P = func2(1);
	printf("%d",P.first+P.second);
}