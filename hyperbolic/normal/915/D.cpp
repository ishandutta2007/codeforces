#include <stdio.h>
#include <vector>

int check[510];
std::vector< std::pair<int,long long int> > V[510];

int func(int k, int target)
{
	int ans = 0;
	check[k] = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==target)
		{
			ans++;
			V[k][i].second++;
		}
		else if(check[V[k][i].first]==0)
		{
			int t = func(V[k][i].first,target);
			ans += t;
			V[k][i].second += t;
		}
	}
	return ans;
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back({d,0});
	}
	
	long long int count = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++) check[j] = 0;
		int t = func(i,i);
		count += t;
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<V[i].size();j++)
		{
			if(V[i][j].second==count)
			{
				printf("YES");
				return 0;
			}
		}
	}
	printf("NO");
}