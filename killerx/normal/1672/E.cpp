#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

#define tab "\t"
#define endl "\n"

#define ferr std::cerr

#define fin std::cin
#define fout std::cout

inline int ask(int w) {
	fout << "? " << w << endl;
	fout.flush();
	int h;
	fin >> h;
	return h;
}

inline void answer(int a) {
	fout << "! " << a << endl;
	fout.flush();
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n;
	fin >> n;
	int lb = 1, rb = n * 2000;
	while (lb < rb) {
		int md = (lb + rb) >> 1;
		if (ask(md) != 1) lb = md + 1;
		else rb = md;
	}
	int ans = 0x3f3f3f3f;
	for (int k = 1; k <= n; ++ k) {
		int w = lb / k, h = ask(w);
		if (h) ans = std::min(ans, h * w);
	}
	answer(ans);
	return 0;
}