#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 300005;

int a[maxn];
int n, k;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	int ans = 1;
	for (int i = 1; i <= a[0]; i++)
	{
		int next = 0;
		bool can = true;
		for (int j = i; can && next < n; j += i)
		{
			if (a[next] < j) can = false;
			next = lower_bound(a, a + n, j + k + 1) - a;
		}
		if (can) ans = i;
	}
	cout << ans << endl;
	return 0;
}