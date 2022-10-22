#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

void Main() {
	int n;
	scanf("%d", &n);
	std::map <std::pair <int, int>, int> gg;
	int minl = +0x3f3f3f3f, minlc = -1;
	int maxr = -0x3f3f3f3f, maxrc = -1;
	rep(i, n) {
		int l, r, c;
		scanf("%d %d %d", &l, &r, &c);
		if (gg.find({l, r}) == gg.end()) gg[{l, r}] = c;
		else gg[{l, r}] = std::min(gg[{l, r}], c);
		if (l < minl) minl = l, minlc = c;
		else if (l == minl) minlc = std::min(minlc, c);
		if (r > maxr) maxr = r, maxrc = c;
		else if (r == maxr) maxrc = std::min(maxrc, c);
		int ans = minlc + maxrc;
		if (gg.find({minl, maxr}) != gg.end()) ans = std::min(ans, gg[{minl, maxr}]);
		printf("%d\n", ans);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}