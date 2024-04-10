#include <cstdio>
#include <cmath>

int ans;
int a, b, c;

int cache[1000002];

int main()
{
	scanf("%d %d %d", &a, &b, &c);
	for (int i = 1;i <= a;i++) for (int j = 1;j <= b;j++) for (int k = 1;k <= c;k++)
	{
		long long temp = i*j*k;
		if (cache[temp] == 0)
		{
			int sq = ceil(sqrt(temp));
			for (int l = 1;l < sq;l++) if (temp%l == 0)
			{
				cache[temp] += 2;
				if (cache[temp] >= 1073741824)
					cache[temp] -= 1073741824;
			}
			if (sq*sq == temp)
				cache[temp] += 1;
			if (cache[temp] >= 1073741824)
				cache[temp] -= 1073741824;
		}
		ans += cache[temp];
		if (ans > 1073741824)
			ans -= 1073741824;
	}
	printf("%d\n", ans);
	return 0;
}