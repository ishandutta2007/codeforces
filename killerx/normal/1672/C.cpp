#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

#define tab "\t"
#define endl "\n"

#define ferr std::cerr

#ifdef DEBUG
std::ifstream fin("in");
std::ofstream fout("out");
#else
#define fin std::cin
#define fout std::cout
#endif

inline void Main() {
	int n;
	fin >> n;
	std::vector <int> a(n);
	rep(i, n) fin >> a[i];
	int mn = 1e9, mx = -1e9;
	rep(i, n - 1) if (a[i] == a[i + 1]) {
		mn = std::min(mn, i);
		mx = std::max(mx, i);
	}
	if (mn + 1 == mx) fout << 1 << endl;
	else fout << std::max(0, mx - mn - 1) << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T;
	fin >> T;
	while (T --) Main();
	return 0;
}