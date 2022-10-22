#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

inline void Main() {
	const int mxn = 2e5 + 5;
	int n;
	scanf("%d", &n);
	static int a[mxn];
	rep(i, n) scanf("%d", &a[i]);
	bool ok = 1;
	static long long L[mxn], R[mxn];
	R[n - 1] = 0;
	for (int i = n - 1; ~i; -- i) {
		L[i] = R[i] - a[i];
		if (i) R[i - 1] = L[i];
		if (L[i] < 0) {
			ok = 0;
			break;
		}
	}
	if (L[0] != 0) {
		ok = 0;
	}
	rep(i, n - 1) {
		if (!R[i] && R[i + 1]) {
			ok = 0;
			break;
		}
	}
	puts(ok ? "Yes" : "No");
}

int main() {
	int T;
	scanf("%d", &T);
	while (T --) Main();
	return 0;
}