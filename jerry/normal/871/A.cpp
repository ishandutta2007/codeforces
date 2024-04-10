// Test that submissions work in China
// Who knows how powerful the Great Wall is

#include <bits/stdc++.h>
using namespace std;

int ans[105];
int n;

bool comp(int x)
{
	for (int i = 2;i < x;i++) if (x%i == 0) return true;
	return false;
}

int main()
{
	for (int i = 1;i < 105;i++)
	{
		ans[i] = -1;
		for (int j = 2;j <= i;j++) if (comp(j) && ans[i-j] != -1)
			ans[i] = max(ans[i], ans[i-j]+1);
	}
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		int x; scanf("%d", &x);
		if (x < 105) printf("%d\n", ans[x]);
		else printf("%d\n", ans[96+(x%4)]+(x/4-96/4));
	}
	return 0;
}