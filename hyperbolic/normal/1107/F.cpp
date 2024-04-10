#include <stdio.h>
#include <algorithm>
#define MIN -(long long int)1e16


struct str{
	long long int first;
	long long int second;
	long long int third;
}x[510];
bool cmp(str a, str b)
{
	if(a.second==b.second) return a.third<b.third;
	return a.second<b.second;
}

int check[510][510];
long long int check2[510][510];

long long int func(int s, int t)
{
	if(s==0) return 0;
	if(check[s][t]) return check2[s][t];
	
	long long int s1 = func(s-1,t+1) + x[s].first - t*x[s].second;
	long long int s2 = func(s-1,t);
	if(x[s].first>x[s].second*x[s].third) s2 += (x[s].first-x[s].second*x[s].third);
	
	check[s][t] = 1;
	return check2[s][t] = s1>s2?s1:s2;
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		long long int b,c,d;
		scanf("%lld%lld%lld",&b,&c,&d);
		x[i] = {b,c,d};
	}
	std::sort(x+1,x+a+1,cmp);
	printf("%lld",func(a,0));
}