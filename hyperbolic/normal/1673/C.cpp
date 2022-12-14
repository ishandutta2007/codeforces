#include <stdio.h>
#include <vector>
#include <algorithm>
#define MOD 1000000007

std::vector<int> V;
int n;
long long int check[40010][510];
long long int func(int s, int t)
{
	if(s<0) return 0;
	if(t<0)
	{
		if(s==0) return 1;
		else return 0;
	}
	if(check[s][t]!=-1) return check[s][t];
	
	long long int s1 = func(s,t-1);
	long long int s2 = func(s-V[t],t);
	return check[s][t] = (s1+s2)%MOD;
}
int main()
{
	for(int i=0;i<=40000;i++) for(int j=0;j<=500;j++) check[i][j] = -1;
	for(int i=1;i<=9;i++) V.push_back(i);
	for(int i=1;i<=9;i++) V.push_back(10*i+i);
	for(int i=1;i<=9;i++) for(int j=0;j<=9;j++) V.push_back(100*i+10*j+i);
	for(int i=1;i<=9;i++) for(int j=0;j<=9;j++) V.push_back(1000*i+100*j+10*j+i);
	for(int i=1;i<=3;i++) for(int j=0;j<=9;j++) for(int k=0;k<=9;k++) V.push_back(10000*i+1000*j+100*k+10*j+i);
	std::sort(V.begin(),V.end());
	n = V.size()-1;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		printf("%lld\n",func(a,n));
	}
}