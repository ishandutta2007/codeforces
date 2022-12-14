#include <stdio.h>
#include <vector>

std::vector<int> V[3][200010];
int size[3][200010];
int check[3][200010];

int getSize(int type, int k, int prev)
{
	int ans = 1;
	for(int i=0;i<V[type][k].size();i++)
	{
		if(V[type][k][i]==prev) continue;
		ans += getSize(type,V[type][k][i],k);
	}
	return ans;
}

void func(int type, int k, int C, int prev)
{
	check[type][k] = C;
	for(int i=0;i<V[type][k].size();i++)
	{
		if(V[type][k][i]==prev) continue;
		func(type,V[type][k][i],C,k);
	}
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c,d;
		scanf("%d%d%d",&b,&c,&d);
		V[d][b].push_back(c);
		V[d][c].push_back(b);
	}
	for(int j=0;j<=1;j++)
	{
		for(int i=1;i<=a;i++)
		{
			if(check[j][i]==0)
			{
				func(j,i,getSize(j,i,0),0);
			}
		}
	}
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		long long int s = check[0][i];
		long long int t = check[1][i];
		ans += s*t;
	}
	printf("%lld",ans-a);
}