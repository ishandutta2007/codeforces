#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int k;
int x[102];
int num[102];
int ans;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0;i < n;i++)
		scanf("%d", x+i);
	for (int i = 0;i < n;i++)
		num[i%k] += (x[i] - 1);
	for (int i = 0;i < n;i++)
		ans += min(num[i], n/k-num[i]);
	printf("%d\n", ans);
	return 0;
}