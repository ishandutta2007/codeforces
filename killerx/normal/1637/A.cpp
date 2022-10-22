#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

inline void Main() {
	int n; scanf("%d", &n);
	std::vector <int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	std::vector <int> mn(n), mx(n);
	rep(i, n) mx[i] = std::max(i ? mx[i - 1] : 0, a[i]);
	for (int i = n - 1; ~i; -- i) mn[i] = std::min(i + 1 < n ? mn[i + 1] : 1 << 30, a[i]);
	bool ok = 0;
	rep(i, n - 1) if (mx[i] > mn[i + 1]) ok = 1;
	if (ok) puts("YES"); else puts("NO");
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}