#include <stdio.h>
#include <algorithm>
#define MAX 123456789
int abs(int k)
{
	return k>0?k:-k;
}
int check[210][510];
int x[210],a;
int func(int s, int t)
{
	if(t>400) return MAX;
	if(s>a) return 0;
	if(check[s][t] != -1) return check[s][t];
	
	int s1 = func(s,t+1);
	int s2 = func(s+1,t+1) + abs(x[s]-t);
	return check[s][t] = s1<s2?s1:s2;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		for(int i=1;i<=a;i++) for(int j=1;j<=400;j++) check[i][j] = -1;
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		printf("%d\n",func(1,1));
	}
}