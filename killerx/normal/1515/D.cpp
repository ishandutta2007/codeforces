#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

void Main() {
	int n, l, r;
	scanf("%d %d %d", &n, &l, &r);
	std::map <int, int> L, R;
	rep(i, n) {
		int c; scanf("%d", &c);
		if (i < l) L[c] ++;
		else R[c] ++;
	}
	if (l > r) std::swap(l, r), std::swap(L, R);
	for (auto &x : L) if (R.find(x.first) != R.end()) {
		int mn = std::min(L[x.first], R[x.first]);
		L[x.first] -= mn;
		R[x.first] -= mn;
		l -= mn;
		r -= mn;
	}
	int mov = (r - l) >> 1;
	int can = 0;
	for (auto x : R) can += x.second >> 1;
	int once = std::min(can, mov) + l;
	int twice = mov - std::min(can, mov);
	printf("%d\n", once * 1 + twice * 2);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}