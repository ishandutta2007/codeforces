#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
	int n, K;
	scanf("%d %d", &n, &K);
	auto Or = [] (int x, int y) { printf("or %d %d\n", x + 1, y + 1); fflush(stdout); int ans; scanf("%d", &ans); return ans; };
	auto And = [] (int x, int y) { printf("and %d %d\n", x + 1, y + 1); fflush(stdout); int ans; scanf("%d", &ans); return ans; };
	std::vector <int> vor(n), vand(n);
	rep(i, n) if (i) vor[i] = Or(0, i), vand[i] = And(0, i);
	int exvor = Or(1, 2), exvand = And(1, 2);
	int totvor = (1LL << 31) - 1, totvand = 0;
	rep(i, n) if (i) totvor &= vor[i], totvand |= vand[i];
	int uncer = totvor ^ totvand;
	std::vector <int> a(n);
	a[0] = totvand | (uncer & ~exvor);
	rep(i, n) if (i) a[i] = (vor[i] ^ a[0]) | vand[i];
	std::sort(a.begin(), a.end());
	printf("finish %d\n", a[K - 1]);
	fflush(stdout);
	return 0;
}