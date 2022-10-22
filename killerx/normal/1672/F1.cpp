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

const int mxn = 2e5 + 5;

int n;
int a[mxn], b[mxn];
std::vector <int> vec[mxn];
int ptr[mxn];
std::set <std::pair <int, int> > lft;

inline void Main() {
	fin >> n;
	rep(i, n) fin >> a[i], -- a[i];
	rep(i, n) vec[i].clear(), ptr[i] = 0;
	rep(i, n) vec[a[i]].push_back(i);
	rep(i, n) lft.insert({(int) vec[i].size(), i});
	while (!lft.empty()) {
		int mn = lft.begin()->first - ptr[lft.begin()->second];
		while (mn --) {
			std::vector <int> pp;
			for (auto pr : lft) pp.push_back(pr.second);
			rep(i, pp.size()) {
				int j = (i + 1) % int(pp.size());
				b[vec[pp[i]][ptr[pp[i]] ++]] = pp[j];
			}
		}
		for (auto it = lft.begin(); it != lft.end(); ) {
			if (ptr[it->second] == it->first) {
				it = lft.erase(it);
			} else {
				++ it;
			}
		}
	}
	rep(i, n) fout << b[i] + 1 << " ";
	fout << endl;
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