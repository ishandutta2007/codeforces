#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct fenwick {
	static const int mxn = 1 << 20;
	int s[mxn], vis[mxn], tim;
	inline void clear() { ++ tim; }
	inline void R(int x) { if (vis[x] != tim) vis[x] = tim, s[x] = 0; }
	inline void update(int x, int v) { for (++ x; x < mxn; x += x & -x) R(x), s[x] += v; }
	inline int query(int x) { int ans = 0; for (++ x; x; x &= x - 1) R(x), ans += s[x]; return ans; }
} bit;

int n, m;
char s[1000005];

inline void Main() {
	scanf("%d %d", &n, &m);
	scanf("%s", s);
	std::vector <int> ans(n * m);
	std::vector <bool> hav(m);
	int cur = 0;
	rep(i, n * m) {
		if (s[i] == '1') if (!hav[i % m]) hav[i % m] = 1, ++ cur;
		ans[i] += cur;
	}
	int last = -1;
	bit.clear();
	rep(i, n * m) {
		if (s[i] == '1') {
			bit.update(0, +1);
			if (~last) {
				if (i - last < m) {
					bit.update(i % m, -1);
					if (i % m + (m - (i - last)) < m)
						bit.update(i % m + (m - (i - last)), +1);
					else {
						bit.update(0, -1);
						bit.update(i % m + (m - (i - last)) - m, +1);
					}
				}
			}
			last = i;
		}
		ans[i] += bit.query(i % m);
	}
	rep(i, n * m) printf("%d ", ans[i]);
	printf("\n");
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}