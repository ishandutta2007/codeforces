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
	std::string s;
	fin >> s;
	if (s.back() != 'B') {
		fout << "NO" << endl;
		return ;
	}
	int cnt = 0;
	for (char c : s) {
		if (c == 'A') ++ cnt;
		else {
			if (!cnt) {
				fout << "NO" << endl;
				return ;
			}
			-- cnt;
		}
	}
	fout << "YES" << endl;
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