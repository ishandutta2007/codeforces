#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;
int n, a[mxn], b[mxn];

bool check(int M) {
	int L = 0, R = 0;
	rep(i, n) {
		int L0 = std::max(L, M - a[i] - 1);
		int R0 = std::min(R, b[i]);
		if (L0 <= R0) {
			++ L0, ++ R0;
			L = std::min(L, L0);
			R = std::max(R, R0);
		}
	}
	return L <= M && M <= R;
}

void Main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d %d", &a[i], &b[i]);
	int lb = 0, rb = n;
	while (lb < rb) {
		int md = (lb + rb + 1) >> 1;
		if (check(md)) lb = md;
		else rb = md - 1;
	}
	printf("%d\n", lb);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}