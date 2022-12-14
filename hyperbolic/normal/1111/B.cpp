#include <stdio.h>
#include <algorithm>
int x[100010];
long long int sum[100010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	for(int i=a;i>=1;i--) sum[i] = sum[i+1] + x[i];
	double max = 0;
	for(int i=a;i>=1;i--)
	{
		if(i-1>c) continue;
		
		long long int t = (c-i+1)<(long long int)(a-i+1)*b?(c-i+1):(long long int)(a-i+1)*b;
		double s = sum[i] + t;
		max = max>s/(a-i+1)?max:s/(a-i+1);
	}
	printf("%.12lf",max);
}