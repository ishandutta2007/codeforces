#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

inline void Main() {
	int n, m;
	scanf("%d %d", &n, &m);
	std::vector <std::vector <int> > a(n, std::vector <int> (m));
	rep(i, n) rep(j, m) scanf("%d", &a[i][j]);
	int p = -1;
	rep(i, n) rep(j, m - 1) if (a[i][j] > a[i][j + 1]) { p = j; break; }
	if (!~p) {
		printf("1 1\n");
		return ;
	}
	int mn = p, mx = p + 1;
	for (int j = p; ~j; -- j) {
		bool ok = false;
		rep(i, n) ok |= a[i][j] > a[i][p + 1];
		if (ok) mn = j;
	}
	for (int j = p + 1; j < m; ++ j) {
		bool ok = false;
		rep(i, n) ok |= a[i][p] > a[i][j];
		if (ok) mx = j;
	}
	rep(i, n) std::swap(a[i][mn], a[i][mx]);
	bool ok = true;
	rep(i, n) rep(j, m - 1) if (a[i][j] > a[i][j + 1]) { ok = false; break; }
	if (ok) printf("%d %d\n", mn + 1, mx + 1);
	else puts("-1");
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}