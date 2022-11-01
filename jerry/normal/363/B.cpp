#include <cstdio>

int cumu[150001];
int n;
int k;
int ans;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1;i <= n;i++)
	{
		int temp;
		scanf("%d", &temp);
		cumu[i] = cumu[i-1] + temp;
	}
	for (int i = 1;i <= n-k;i++) if (cumu[i+k]-cumu[i] < cumu[ans+k]-cumu[ans])
		ans = i;
	printf("%d\n", ans+1);
	return 0;
}