#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

inline void Main() {
	int n; scanf("%d", &n);
	std::vector <int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	n -= 2;
	a.erase(a.begin());
	a.erase(-- a.end());
	bool ok = 0;
	long long ans = 0;
	rep(i, n) ans += (a[i] + 1) >> 1;
	rep(i, n) {
		if (a[i] % 2 == 0) {
			ok = 1;
			break;
		}
	}
	int cnt = 0;
	rep(i, n) if (a[i] >= 2) ++ cnt;
	if (cnt && n >= 2) {
		ok = 1;
	}
	if (ok) printf("%lld\n", ans);
	else puts("-1");
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}