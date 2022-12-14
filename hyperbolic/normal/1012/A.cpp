#include <stdio.h>
#include <algorithm>

long long int x[200010];
int main()
{
	int a,b;
	scanf("%d",&a);
	b = 2*a;
	for(int i=1;i<=b;i++) scanf("%lld",&x[i]);
	if(a==1)
	{
		printf("0");
		return 0;
	}
	std::sort(x+1,x+b+1);
	long long int min1 = x[1];
	long long int max1 = x[a];
	long long int min2 = x[a+1];
	long long int max2 = x[2*a];
	long long int s1 = (max1-min1)*(max2-min2);
	long long int s2 = x[a+1]-x[2];
	for(int i=3;i<=a;i++) s2 = s2<(x[i+a-1]-x[i])?s2:(x[i+a-1]-x[i]);
	s2 *= (max2-min1);
	printf("%lld",s1<s2?s1:s2);
}