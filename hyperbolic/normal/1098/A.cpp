#include <stdio.h>
#include <vector>

std::vector<int> save[100010],V[100010];

void init(int k, int h)
{
	save[h].push_back(k);
	for(int i=0;i<V[k].size();i++) init(V[k][i],h+1);
}

int x[100010],min[100010],prev[100010];
long long int func(int k, int sum)
{
	if(min[k]!=-1)
	{
		if(min[k]<sum) return -1;
	}
	else return 0;
	
	long long int ans = (min[k]-sum);
	sum = min[k];
	for(int i=0;i<V[k].size();i++)
	{
		int t = func(V[k][i],sum);
		if(t==-1) return -1;
		ans += t;
	}
	return ans;
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=2;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		V[b].push_back(i);
		prev[i] = b;
	}
	init(1,1);
	
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) min[i] = x[i];
	
	for(int i=a;i>=2;i--)
	{
		for(int j=0;j<save[i].size();j++)
		{
			int s = prev[save[i][j]];
			int t = save[i][j];
			if(min[t]!=-1)
			{
				if(min[s]!=-1) min[s] = min[s]<min[t]?min[s]:min[t];
				else min[s] = min[t];
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		if(min[i]<x[i])
		{
			printf("-1");
			return 0;
		}
	}
	
	printf("%lld",func(1,0));
}