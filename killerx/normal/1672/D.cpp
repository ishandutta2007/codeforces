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
	std::vector <int> a(n), b(n);
	rep(i, n) fin >> a[i];
	rep(i, n) fin >> b[i];
	std::multiset <int> stk;
	int i, j;
	for (i = n - 1, j = n - 1; ~i; -- i) {
		if (i + 1 < n && b[i] == b[i + 1]) {
			stk.insert(b[i]);
			continue;
		}
		while (!stk.empty() && b[i] != a[j] && stk.find(a[j]) != stk.end())
			stk.erase(stk.find(a[j])), -- j;
		if (b[i] == a[j])
			-- j;
		else {
			fout << "NO" << endl;
			return ;
		}
	}
	while (!stk.empty() && stk.find(a[j]) != stk.end())
		stk.erase(stk.find(a[j])), -- j;
	fout << (!~j ? "YES" : "NO") << endl;
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