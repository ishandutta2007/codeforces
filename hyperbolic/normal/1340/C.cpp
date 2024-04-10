#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
long long int MAX = 1;
int a,b,c,d;
int x[10010];
int check[10010][1010];
int check2[10010];
long long int dist[10010];
std::vector<int> V,V2;
void func(int s, int t)
{
	if(t>c) return;
	if(t==c)
	{
		if(check2[s]) return;
		else
		{
			check2[s] = 1;
			V2.push_back(s);
			return;
		}
	}
	
	if(check[s][t]) return;
	check[s][t] = 1;
	if(s>1) func(s-1,t + (x[s]-x[s-1]));
	if(s<b) func(s+1,t + (x[s+1]-x[s]));
}
int main()
{
	for(int i=1;i<=15;i++) MAX*=10;
	
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+b+1);
	scanf("%d%d",&c,&d);
	
	check2[1] = 1;
	V.push_back(1);
	long long int p = 1;
	for(int i=1;i<=b;i++) dist[i] = MAX;
	while(!V.empty())
	{
		for(int i=0;i<V.size();i++) func(V[i],0);
		for(int i=0;i<V2.size();i++) dist[V2[i]] = p*(c+d);
		V = V2;
		V2.clear();
		p++;
	}
	
	long long int ans = MAX;
	for(int i=1;i<=b;i++)
	{
		if(x[b]-x[i]<=c)
		{
			long long int S = dist[i] + x[b] - x[i];
			ans = ans<S?ans:S;
		}
	}
	if(ans==MAX) printf("-1");
	else printf("%lld",ans);
}