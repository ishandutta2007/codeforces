#include <stdio.h>
#include <vector>
#define MAX 1000000003
std::vector< std::pair<int,int> > V[100010];
int ans = MAX;
int check[100010];
void func(int k)
{
	if(check[k]==1) return;
	for(int i=0;i<V[k].size();i++)
	{
		if(check[V[k][i].first]==1) ans = ans<V[k][i].second?ans:V[k][i].second;
	}
}
int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++)
	{
		scanf("%d%d%d",&d,&e,&f);
		V[d].push_back(std::make_pair(e,f));
		V[e].push_back(std::make_pair(d,f));
	}
	for(int i=1;i<=c;i++)
	{
		scanf("%d",&d);
		check[d] = 1;
	}
	for(int i=1;i<=a;i++) func(i);
	printf("%d",ans==MAX?-1:ans);
}