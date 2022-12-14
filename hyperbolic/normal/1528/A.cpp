#include <stdio.h>
#include <vector>

std::vector<int> V[100010];
std::pair<int,int> x[100010];
int abs(int k)
{
	return k>0?k:-k;
}

long long int check[100010][3];
long long int func(int k ,int prev, int type)
{
	if(check[k][type]!=-1) return check[k][type];
	
	int val;
	if(type==1) val = x[k].second;
	else val = x[k].first;
	
	long long int ans = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		long long int t1 = func(V[k][i],k,0) + abs(val-x[V[k][i]].first);
		long long int t2 = func(V[k][i],k,1) + abs(val-x[V[k][i]].second);
		ans += (t1>t2?t1:t2);
	}
	return check[k][type] = ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) check[i][0] = check[i][1] = -1;
		
		for(int i=1;i<=a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			x[i] = {b,c};
		}
		for(int i=1;i<a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			V[b].push_back(c);
			V[c].push_back(b);
		}
		
		long long int s1 = func(1,0,1);
		long long int s2 = func(1,0,0);
		long long int ans = s1>s2?s1:s2;
		printf("%lld\n",ans);
	}
}