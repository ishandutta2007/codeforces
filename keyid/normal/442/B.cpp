#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN=105;

double p[MAXN];

bool cmp(double x,double y)
{
	return x>y;
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%lf",&p[i]);
	sort(p,p+n,cmp);
	if (fabs(p[0]-1)<1e-9)
	{
		putchar('1');
		return 0;
	}
	double P=1,S=0;
	for (int i=0;i<n;i++)
	{
		P*=1-p[i];
		S+=p[i]/(1-p[i]);
		if (S>=1) break;
	}
	printf("%.9f",P*S);
	return 0;
}