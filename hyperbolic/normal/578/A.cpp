#include <stdio.h>
#define MIN 0
#define MAX 1e9 + 3
double func1(int x, int y)
{
	double s = (double)(x-y)/(2*y);
	int n = (int)s;
	if(n==0) return MAX;
	return (double)(x-y)/(2*n);
}
double func2(int x, int y)
{
	double s = (double)(x+y)/(2*y);
	int n = (int)s - 1;
	if(n==-1) return MAX;
	return (double)(x+y)/(2*n+2);
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	double s1 = func1(a,b);
	double s2 = func2(a,b);
	double ans = s1<s2?s1:s2;
	if(ans==MAX)
	{
		printf("-1");
		return 0;
	}
	else
	{
		printf("%.12lf",ans);
		return 0;
	}
}