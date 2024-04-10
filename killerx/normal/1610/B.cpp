#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;
int n, a[mxn];

bool check(int ban) {
	for (int l = 0, r = n - 1; l < r; ++ l, -- r) {
		while (l < r && a[l] == ban) ++ l;
		while (l < r && a[r] == ban) -- r;
		if (l < r) {
			if (a[l] != a[r]) return false;
		}
	}
	return true;
}

void Main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	bool ok = false;
	int l, r;
	for (l = 0, r = n - 1; l < r; ++ l, -- r) {
		if (a[l] != a[r]) {
			ok |= check(a[l]);
			ok |= check(a[r]);
			break;
		}
	}
	if (l >= r) ok = true;
	puts(ok ? "YES" : "NO");
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}