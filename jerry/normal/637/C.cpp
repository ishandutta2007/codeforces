#include <bits/stdc++.h>
using namespace std;

char buf[1005][8];
int ans = 6;
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%s", buf[i]);
	for (int i = 0;i < n;i++) for (int j = i+1;j < n;j++)
	{
		int alt = 0;
		for (int k = 0;k < 6;k++) if (buf[i][k] != buf[j][k])
			alt++;
		alt = (alt-1)/2;
		if (alt < ans)
			ans = alt;
	}
	printf("%d\n", ans);
	return 0;
}