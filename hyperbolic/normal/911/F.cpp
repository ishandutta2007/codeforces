#include <stdio.h>
#include <vector>
#include <queue>
#define MAX 1234567890

int check[200010];
std::vector<int> V[200010];
std::queue<int> Q;
void func(int k)
{
	Q.push(k);
	check[k] = 0;
	while(!Q.empty())
	{
		int t = Q.front();
		Q.pop();
		
		for(int i=0;i<V[t].size();i++)
		{
			if(check[V[t][i]]==MAX)
			{
				check[V[t][i]] = check[t]+1;
				Q.push(V[t][i]);
			}
		}
	}
}

int s,t;
int dist1[200010],dist2[200010];
void func2(int k, int p)
{
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		func2(V[k][i],k);
	}
	if(check[k]==0)
	{
		if(dist1[k]>dist2[k]) printf("%d %d %d\n",s,k,k);
		else printf("%d %d %d\n",t,k,k);
	}
}

int prev[200010],height[200010];
void init(int k, int p, int h)
{
	prev[k] = p;
	height[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		init(V[k][i],k,h+1);
	}
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	
	int max;
	
	for(int i=1;i<=a;i++) check[i] = MAX;
	func(1);
	max = -1;
	for(int i=1;i<=a;i++)
	{
		if(check[i]>max)
		{
			max = check[i];
			s = i;
		}
	}
	
	for(int i=1;i<=a;i++) check[i] = MAX;
	func(s);
	max = -1;
	for(int i=1;i<=a;i++)
	{
		if(check[i]>max)
		{
			max = check[i];
			t = i;
		}
	}
	for(int i=1;i<=a;i++) dist1[i] = check[i];
	
	for(int i=1;i<=a;i++) check[i] = MAX;
	func(t);
	for(int i=1;i<=a;i++) dist2[i] = check[i];
	
	for(int i=1;i<=a;i++) check[i] = 0;
	init(t,0,1);
	int s2 = s, t2 = t;
	check[s2] = check[t2] = 1;
	while(s2!=t2)
	{
		if(height[s2]>height[t2]) s2 = prev[s2], check[s2] = 1;
		else t2 = prev[t2], check[t2] = 1;
	}
	
	long long int ans = 0;
	int count = 0;
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0)
		{
			int S = dist1[i]>dist2[i]?dist1[i]:dist2[i];
			ans += S;
		}
		else count++;
	}
	ans += (long long int)count*(count-1)/2;
	printf("%lld\n",ans);
	
	func2(t,0);
	int pivot = s;
	while(s!=t)
	{
		printf("%d %d %d\n",s,t,s);
		s = prev[s];
	}
}