#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e6 + 5, mod = 998244353;

int n, k, v[mxn];
int l[mxn], r[mxn];

inline void Main() {
	scanf("%d %d", &n, &k);
	rep(i, n) scanf("%d", &v[i]);
	int ans = 1;
	rep(i, k) {
		if (v[n - k + i] != -1 && v[n - k + i] != 0) {
			ans = 0;
			break;
		}
	}
	rep(i, k) {
		l[i] = 0, r[i] = n;
	}
	for (int i = 0; i < n - k; ++ i) {
		if (v[i] != -1) {
			l[i + k] = v[i] == 0 ? 0 : v[i] + k;
			r[i + k] = v[i] + k;
		} else {
			l[i + k] = 0, r[i + k] = n;
		}
	}
	rep(i, n) {
		l[i] = std::max(l[i], 0);
		r[i] = std::min(r[i], i);
		// eprintf("[%d, %d]\n", l[i], r[i]);
		if (l[i] <= r[i]) ans = 1LL * ans * (r[i] - l[i] + 1) % mod;
		else ans = 0;
	}
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}