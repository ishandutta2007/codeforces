#include <cstdio>

int a[18];
long long cc[18], cd[18], dc[18], dd[18];

long long f(long long n, int m) {
	int i, j, k, t = 1;
	for (i = 15; i >= 0; i--) a[i] = n >> (15 - i << 2) & 15;
	for (i = 0; i < 18; i++) cc[i] = cd[i] = dc[i] = dd[i] = 0;
	for (i = 0; i < 16; i++) {
		for (j = 0; j <= m; j++) {
			if (i + (m >> 2) != 15 || (j >> (m & 3) & 1)) {
				(j == m ? cd : cc)[i + 1] += cc[i];
				cd[i + 1] += cd[i];
				if (j < a[i]) {
					(j == m ? cd : cc)[i + 1] += dc[i];
					cd[i + 1] += dd[i];
				}
				if (j == a[i]) {
					(j == m ? dd : dc)[i + 1] += dc[i];
					dd[i + 1] += dd[i];
				}
			}
			if (!j && i + (m >> 2) <= 15) (t ? dc : cc)[i]++;
		}
		if (a[i]) t = 0;
	}
	return cd[16];
}

int main() {
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int i;
		long long L, R, r;
		scanf("%I64x%I64x", &L, &R);
		r = 0;
		for (i = 0; i < 16; i++) r += f(R + 1, i) - f(L, i);
		printf("%I64d\n", r);
	}
}