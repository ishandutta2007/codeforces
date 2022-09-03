#include <cstdio>
#include <algorithm>

using namespace std;

long long d[200002];

int main()
{
	long long p, q, tp, tq;
	int L, R, M;
	int i, j, n, r, rr;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%I64d", d + i);
	sort(d + 1, d + n + 1);
	for (i = 1; i <= n; i++) d[i] += d[i - 1];
	p = -1;
	q = 1;
	for (i = 1; i <= n; i++)
	{
		L = 1;
		R = min(i, n - i + 1);
		while (L < R)
		{
			M = L + R >> 1;
			if ((d[n] - d[n - M + 1] + d[i] - d[i - M])*(M + M + 1) < (d[n] - d[n - M] + d[i] - d[i - M - 1])*(M + M - 1)) L = M + 1;
			else R = M;
		}
		tp = d[n] - d[n - L + 1] + d[i] - d[i - L] - (d[i] - d[i - 1])*(L + L - 1);
		tq = L + L - 1;
		if (tp * q > p * tq)
		{
			p = tp;
			q = tq;
			r = i;
			rr = L;
		}
	}
	printf("%d\n", rr + rr - 1);
	for (i = 0; i < rr; i++) printf("%I64d ", d[r - i] - d[r - i - 1]);
	for (i = 1; i < rr; i++) printf("%I64d ", d[n - i + 1] - d[n - i]);
}