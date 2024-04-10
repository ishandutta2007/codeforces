#include <stdio.h>
#include <set>

long long int MAX = 1;
int x[300010],a;
long long int check[300010][21];
long long int func(int s, int t)
{
	if(x[s]==-1) return 0;
	if(t>=20) return MAX;
	if(check[s][t]!=-1) return check[s][t];
	
	int size = 0;
	for(int j=1;j<=t;j++) size += (a>>j);
	size -= (a-s);
	
	if(size==0) return check[s][t] = func(s-1,t+1)+x[s];
	else
	{
		long long int s1 = func(s-1,t+1)+x[s];
		long long int s2 = func(s-1,t);
		return check[s][t] = s1<s2?s1:s2;
	}
}
int main()
{
	for(int i=1;i<=16;i++) MAX*=10;
	
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) for(int j=0;j<=20;j++) check[i][j] = -1;
	
	printf("%lld",func(a,0));
}