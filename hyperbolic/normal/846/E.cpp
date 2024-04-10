#include <stdio.h>
#include <vector>
#define MAX (long long int)1e18

std::vector< std::pair<int,int> > V[100010];
long long int x[100010],y[100010];
int control = 0;
long long int func(int k, int r)
{
	long long int sum = x[k] - y[k];
	for(int i=0;i<V[k].size();i++)
	{
		sum += func(V[k][i].first,V[k][i].second);
		if(sum<0 && (-sum)>MAX) control = 1;
	}
	
	if(sum<0)
	{
		if((-sum)>MAX/r) control = 1;
		return sum*r;
	}
	else return sum;
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++) scanf("%lld",&y[i]);
	for(int i=2;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back({i,c});
	}
	
	long long int t = func(1,1);
	
	if(control==1) printf("NO");
	else if(t<0) printf("NO");
	else printf("YES");
}