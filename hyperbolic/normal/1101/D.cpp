#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

int check[200010],check2[200010],check3[200010];
std::vector<int> V[200010];
std::queue<int> Q;

int func(int k)
{
	Q.push(k);
	check2[k] = 1;
	
	int start = k;
	while(!Q.empty())
	{
		int k = Q.front();
		Q.pop();
		if(check[k]==0) continue;
		
		start = k;
		for(int i=0;i<V[k].size();i++)
		{
			if(check2[V[k][i]]==0)
			{
				check2[V[k][i]] = check2[k]+1;
				Q.push(V[k][i]);
			}
		}
	}
	
	check3[start] = 1;
	Q.push(start);
	int ans = 1;
	while(!Q.empty())
	{
		int k = Q.front();
		Q.pop();
		if(check[k]==0) continue;
		ans = check3[k];
		for(int i=0;i<V[k].size();i++)
		{
			if(check3[V[k][i]]==0)
			{
				check3[V[k][i]] = check3[k]+1;
				Q.push(V[k][i]);
			}
		}
	}
	return ans;
}

std::vector<int> prime[200010];
int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		int d = x[i];
		for(int j=2;j*j<=x[i];j++)
		{
			if(d%j==0)
			{
				prime[j].push_back(i);
				while(d%j==0) d/=j;
			}
		}
		if(d>1) prime[d].push_back(i);
	}
	
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	
	int ans = 0;
	for(int i=2;i<=200000;i++)
	{
		for(int j=0;j<prime[i].size();j++)
		{
			check[prime[i][j]] = 1;
			check2[prime[i][j]] = check3[prime[i][j]] = 0;
		}
		
		for(int j=0;j<prime[i].size();j++)
		{
			if(check2[prime[i][j]]==0)
			{
				int s = func(prime[i][j]);
				ans = ans>s?ans:s;
			}
		}
		for(int j=0;j<prime[i].size();j++)
		{
			check[prime[i][j]] = check2[prime[i][j]] = check3[prime[i][j]] = 0;
		}
	}
	printf("%d",ans);
}