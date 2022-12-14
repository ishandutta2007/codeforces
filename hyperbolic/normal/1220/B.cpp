#include <stdio.h>
#include <math.h>

int x[1010][1010];
int main()
{
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) scanf("%d",&x[i][j]);
	
	for(int i=1;i<=a;i++)
	{
		int s1 = i+1, s2 = i+2;
		if(s1>a) s1 -= a;
		if(s2>a) s2 -= a;
		long long int t1 = (long long int)x[i][s1] * x[i][s2];
		long long int t2 = x[s1][s2];
		t1 /= t2;
		long long int t3 = sqrt(t1);
		printf("%lld ",t3);
	}
}