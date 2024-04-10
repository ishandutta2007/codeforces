#include <stdio.h>
#include <algorithm>

int x[100010];
int check[100010];
int a,b;
int func(int k)
{
	if(k==a+1) return 0;
	if(k>a+1) return -12345678;
	if(check[k]!=-1) return check[k];
	
	int s1 = func(k+1);
	int t = (b-1)/x[k]+1;
	int s2 = func(k+t)+1;
	return check[k] = s1>s2?s1:s2;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a+1;i++) check[i] = -1;
		std::sort(x+1,x+a+1);
		
		printf("%d\n",func(1));
	}
}