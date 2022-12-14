#include <stdio.h>
#include <vector>

int sum;
int control;
int value[100010],x[100010];
std::vector<int> V[100010];
int init(int k, int prev)
{
	value[k] = x[k];
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		value[k] ^= init(V[k][i],k);
	}
	return value[k];
}

int func(int k, int prev, int type)
{
	int ans = 0;
	if(value[k]==sum)
	{
		if(type==1)
		{
			control = 1;
			return 1;
		}
	}
	if(value[k]==0) type = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		ans += func(V[k][i],k,type);
	}
	if(ans>=2) control = 1;
	if(ans==0 && value[k]==sum) ans = 1;
	return ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<a;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			V[c].push_back(d);
			V[d].push_back(c);
		}
		
		sum = 0;
		control = 0;
		for(int i=1;i<=a;i++) sum ^= x[i];
		if(sum==0)
		{
			printf("YES\n");
			continue;
		}
		if(b==2)
		{
			printf("NO\n");
			continue;
		}
		
		int temp = init(1,0);
		temp = func(1,0,0);
		if(control==1) printf("YES\n");
		else printf("NO\n");
	}
}