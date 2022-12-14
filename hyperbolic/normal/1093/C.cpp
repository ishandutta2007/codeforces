#include <stdio.h>

long long int ans[200010];
long long int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a/2;i++) scanf("%lld",&x[i]);
	ans[1] = 0;
	ans[a] = x[1];
	for(int i=2;i<=a/2;i++)
	{
		int L = i;
		int R = a-i+1;
		ans[L] = ans[L-1]>x[i]-ans[R+1]?ans[L-1]:x[i]-ans[R+1];
		ans[R] = x[i] - ans[L];
	}
	for(int i=1;i<=a;i++) printf("%lld ",ans[i]);
	printf("\n");
}