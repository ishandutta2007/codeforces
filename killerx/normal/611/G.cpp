#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;
using i128 = __int128;
const int mxn = 1 << 20;
const int mod = 1e9 + 7;

struct point {
	int x, y;
	friend inline i64 operator ^ (point a, point b) {
		return 1LL * a.x * b.y - 1LL * a.y * b.x;
	}
};

int n;
point p[mxn];
i128 S[mxn];
i128 SS[mxn];
i64 Sx[mxn], Sy[mxn];

inline i128 area(int l, int r) {
	return S[r] - S[l] + (p[r] ^ p[l]);
}

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d %d", &p[i].x, &p[i].y);
	std::reverse(p, p + n);
	rep(i, n) p[i + n] = p[i];
	rep(i, n * 2) S[i + 1] = S[i] + (p[i] ^ p[i + 1]);
	rep(i, n * 2) SS[i + 1] = SS[i] + S[i];
	rep(i, n * 2) Sx[i + 1] = Sx[i] + p[i].x;
	rep(i, n * 2) Sy[i + 1] = Sy[i] + p[i].y;
	i128 ans = 0;
	for (int i = n; i < 2 * n; ++ i) {
		int lb = i - n + 1, rb = i;
		while (lb < rb) {
			int md = (lb + rb) >> 1;
			if (area(i - n, md) < area(md, i)) lb = md + 1;
			else rb = md;
		}
		if (i - n + 2 < lb) {
			int l = i - n + 2, r = lb;
			ans += i128(r - l) * S[i];
			ans -= SS[r] - SS[l];
			ans += i128(p[i].x) * (Sy[r] - Sy[l]);
			ans -= i128(p[i].y) * (Sx[r] - Sx[l]);
			
			ans -= SS[r] - SS[l];
			ans += i128(r - l) * S[i - n];
			ans -= i128(Sx[r] - Sx[l]) * p[i - n].y;
			ans += i128(Sy[r] - Sy[l]) * p[i - n].x;
		}
		if (lb < i - 1) {
			int l = lb, r = i - 1;
			ans += SS[r] - SS[l];
			ans -= i128(r - l) * S[i - n];
			ans += i128(Sx[r] - Sx[l]) * p[i - n].y;
			ans -= i128(Sy[r] - Sy[l]) * p[i - n].x;
			
			ans -= i128(r - l) * S[i];
			ans += SS[r] - SS[l];
			ans -= i128(p[i].x) * (Sy[r] - Sy[l]);
			ans += i128(p[i].y) * (Sx[r] - Sx[l]);
		}
	}
	int res = (ans % mod + mod) % mod;
	res = 1LL * res * ((mod + 1) / 2) % mod;
	printf("%d\n", res);
	return 0;
}