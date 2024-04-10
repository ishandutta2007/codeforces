#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = __int128;

inline i64 s0(i64 n) { return n; }
inline i64 s1(i64 n) { return n * (n + 1) / 2; }
inline i64 s2(i64 n) { return n * (n + 1) * (2 * n + 1) / 6; }

i64 s(i64 f[], int l, int r) {
	i64 ans = 0;
	ans += (s0(r) - s0(l - 1)) * f[0];
	ans += (s1(r) - s1(l - 1)) * f[1];
	ans += (s2(r) - s2(l - 1)) * f[2];
	return ans;
}

i64 calc(int n, int m) {
	if (n == 0 || m == 0) return 0;
	i64 ans = 0;
	int x = std::min(n, m);
	ans += s1(i64(x) * x);
	if (n < m) {
		// for(int i=n+1;i<=m;++i)ans+=(2*(i-1)*(i-1)+n+1)*n/2;
		i64 f[] = {2 + n + 1, -4, 2, 0};
		ans += s(f, n + 1, m) * n / 2;
	}
	if (m < n) {
		// for(int i=m+1;i<=n;++i)ans+=(2*i*i-m+1)*m/2;
		i64 f[] = {-m + 1, 0, 2, 0};
		ans += s(f, m + 1, n) * m / 2;
	}
	return ans;
}

void writeln(i64 x) {
	if (x < 1e10) printf("%lld\n", (long long) x);
	else printf("...%010lld\n", (long long) (x % ((long long) 1e10)));
}

int main() {
	#ifdef DEBUG
	freopen("in", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T --) {
		int x0, x1, y0, y1;
		scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
		writeln(calc(x1, y1) - calc(x0 - 1, y1) - calc(x1, y0 - 1) + calc(x0 - 1, y0 - 1));
	}
	return 0;
}