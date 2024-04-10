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
	int x = 0;
	rep(i, n) {
		int v;
		fin >> v;
		x += v - 1;
	}
	if (x & 1) fout << "errorgorn" << endl;
	else fout << "maomao90" << endl;
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