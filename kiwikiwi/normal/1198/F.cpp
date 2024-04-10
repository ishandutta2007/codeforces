#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define maxN (1 << 18) + 10
#define maxM 20
i64 f[maxN], g[maxN], pw[maxN];
int cnt[maxN], pos[maxN];
int n, a[maxN], mask[maxN], t1, t2, m, g1, g2;
int p1[maxM], p2[maxM];

void factor(int x, int *p, int &t) {
	t = 0;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			p[t++] = i;
			while (x % i == 0)
				x /= i;
		}
	}
	if (x != 1) {
		p[t++] = x;
	}
}
int calc(int x, int *p, int t) {
	int mask = 0;
	for (int i = 0; i < t; i++) {
		if (x % p[i]) mask |= 1 << i;
	}
	return mask;
}

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
i64 base = 2;
i64 mod = 1000000007;

void construct(int ps) {
	printf("YES\n");
	int msk1 = 0, msk2 = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			pos[i] = 1; continue;
		}
		if (i == ps) {
			pos[i] = 2; continue;
		}
		int m1 = mask[i] >> t2, m2 = mask[i] & ((1 << t2) - 1);
		if ((msk1 | m1) == msk1) {
			msk2 |= m2;
			pos[i] = 2;
			continue;
		}
		if ((msk2 | m2) == msk2) {
			pos[i] = 1;
			msk1 |= m1;
			continue;
		}
		for (int j = 0; j < (1 << m); j++)
			cnt[j] = 0;
		for (int j = i + 1; j < n; j++) {
			if (j == ps) continue;
			int p1 = mask[j] >> t2, p2 = mask[j] & ((1 << t2) - 1);
			cnt[(p1 << t2) | p2] += 1;
		}
		int totn = 0;
		for (int j = 0; j < (1 << m); j++) {
			f[j] = cnt[j]; totn += cnt[j];
		}
		for (int k = 0; k < m; k++)
			for (int j = 0; j < (1 << m); j++)
				if (j & (1 << k))
					f[j] += f[j - (1 << k)];
		for (int j = 0; j < (1 << m); j++) {
			int f1 = j >> t2, f2 = j & ((1 << t2) - 1);
			g[j] = pw[f[j]];
			if (f[(f1 << t2) | g2] + f[g1 | f2] - f[j] != totn) {
				g[j] = 0;
			}
		}
		for (int k = 0; k < m; k++)
			for (int j = 0; j < (1 << m); j++)
				if (j & (1 << k))
					g[j] = g[j] - g[j - (1 << k)];
		bool v1 = 0, v2 = 0;
		int nmsk1 = msk1 | m1;
		int nmsk2 = msk2 | m2;
		for (int j = 0; j < (1 << m); j++) if (g[j] % mod != 0) {
				if ((j | (nmsk1 << t2) | msk2) == (1 << m) - 1) {
					v1 = 1;
				}
				if ((j | (msk1 << t2) | nmsk2) == (1 << m) - 1) {
					v2 = 1;
				}
			}
		assert(v1 || v2);
		if (v2) {
			pos[i] = 2;
			msk2 |= m2;
		} else {
			pos[i] = 1;
			msk1 |= m1;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", pos[i]);
	}
	printf("\n");
	exit(0);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	pw[0] = 1;
	for (int i = 1; i <= (1 << 18); i++)
		pw[i] = pw[i - 1] * base % mod;
	t1 = 0;
	factor(a[0], p1, t1);
	for (int i = 1; i < 12 && i < n; i++) {
		t2 = 0;
		factor(a[i], p2, t2);
		m = t1 + t2;
		g1 = ((1 << t1) - 1) << t2, g2 = (1 << t2) - 1;
		for (int j = 0; j < (1 << m); j++)
			cnt[j] = 0;
		for (int j = 0; j < n; j++) {
			if (j == 0 || j == i) continue;
			int mask1 = calc(a[j], p1, t1);
			int mask2 = calc(a[j], p2, t2);
			mask[j] = (mask1 << t2) | mask2;
			cnt[mask[j]] += 1;
		}
		int totn = 0;
		for (int j = 0; j < (1 << m); j++) {
			f[j] = cnt[j]; totn += cnt[j];
		}
		for (int k = 0; k < m; k++)
			for (int j = 0; j < (1 << m); j++)
				if (j & (1 << k))
					f[j] += f[j - (1 << k)];
		for (int j = 0; j < (1 << m); j++) {
			int f1 = j >> t2, f2 = j & ((1 << t2) - 1);
			g[j] = pw[f[j]];
			if (f[(f1 << t2) | g2] + f[g1 | f2] - f[j] != totn) {
				g[j] = 0;
			}
		}
		for (int k = 0; k < m; k++)
			for (int j = 0; j < (1 << m); j++)
				if (j & (1 << k))
					g[j] = g[j] - g[j - (1 << k)];
		if (g[(1 << m) - 1] % mod == 0) continue;

		construct(i);
	}
	printf("NO\n");
}