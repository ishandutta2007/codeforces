#include <bits/stdc++.h>
#define REP(i, a, b) for (int i(a); i <= (b); ++i)
#define dbg(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		static char s[1000];
		scanf("%d%s", &n, s + 1);
		int p = 1, q = n;
		while (p <= n && s[p] == '<') ++p;
		while (q && s[q] == '>') --q;
		std::cout << std::min(p - 1, n - q) << "\n";
	}
    return 0;
}