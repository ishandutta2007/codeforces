#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

inline void Main() {
	int n0, n1, m;
	scanf("%d %d", &n0, &m);
	std::vector <std::pair <int, int> > a0(n0);
	rep(i, n0) scanf("%d", &a0[i].first), a0[i].second = 1;
	std::reverse(a0.begin(), a0.end());
	scanf("%d", &n1);
	std::vector <std::pair <int, int> > a1(n1);
	rep(i, n1) scanf("%d", &a1[i].first), a1[i].second = 1;
	std::reverse(a1.begin(), a1.end());
	while (!a0.empty() && !a1.empty()) {
		if (a0.back().first == a1.back().first) {
			int z = std::min(a0.back().second, a1.back().second);
			if (a0.back().second == z) a0.pop_back(); else a0.back().second -= z;
			if (a1.back().second == z) a1.pop_back(); else a1.back().second -= z;
			continue;
		}
		if (a0.back().first > a1.back().first) {
			if (a0.back().first % m == 0) {
				a0.back().first /= m;
				a0.back().second *= m;
			} else {
				puts("No");
				return ;
			}
		} else {
			if (a1.back().first % m == 0) {
				a1.back().first /= m;
				a1.back().second *= m;
			} else {
				puts("No");
				return ;
			}
		}
	}
	if (a0.empty() && a1.empty()) puts("Yes");
	else puts("No");
}

int main() {
	int T;
	scanf("%d", &T);
	while (T --) Main();
	return 0;
}