#include <stdio.h>
#include <vector>

int check[1000010],check2[1000010];
std::vector< std::pair<int,int> > V[1000010];
void init(int k)
{
	if(check[k]) return;
	check[k] = 1;
	for(int i=0;i<V[k].size();i++)
	{
		check2[V[k][i].second] = 1;
		init(V[k][i].first);
	}
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(b==1)
	{
		printf("0");
		return 0;
	}
	
	int count = 0;
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(c==d) count++;
		V[c].push_back(std::make_pair(d,i));
		V[d].push_back(std::make_pair(c,i));
	}
	for(int i=1;i<=a;i++)
	{
		if(V[i].size()>0)
		{
			init(i);
			break;
		}
	}
	
	for(int i=1;i<=b;i++)
	{
		if(check2[i]==0)
		{
			printf("0");
			return 0;
		}
	}
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int t = 0;
		for(int j=0;j<V[i].size();j++)
		{
			if(V[i][j].first!=i) t++;
		}
		ans += (long long int)t*(t-1)/2;
	}
	ans += (long long int)count*(b-count);
	ans += (long long int)count*(count-1)/2;
	printf("%lld",ans);
}