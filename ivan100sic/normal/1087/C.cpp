#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<pair<int, int>> put(int ax, int ay, int bx, int by) {
	basic_string<pair<int, int>> r;
	r += {ax, ay};
	while (ax < bx) {
		r += {ax, ay};
		ax++;
	}
	while (ax > bx) {
		r += {ax, ay};
		ax--;
	}
	while (ay < by) {
		r += {ax, ay};
		ay++;
	}
	while (ay > by) {
		r += {ax, ay};
		ay--;
	}
	r += {ax, ay};
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;

	basic_string<int> xkand = {ax, bx, cx};
	basic_string<int> ykand = {ay, by, cy};

	set<pair<int, int>> sol;

	for (int x : xkand) {
		for (int y : ykand) {
			set<pair<int, int>> tmp;
			for (auto p : put(x, y, ax, ay))
				tmp.insert(p);
			for (auto p : put(x, y, bx, by))
				tmp.insert(p);
			for (auto p : put(x, y, cx, cy))
				tmp.insert(p);
			if (sol.size() == 0 || tmp.size() < sol.size())
				sol = tmp;
		}
	}
	cout << sol.size() << '\n';
	for (auto p : sol)
		cout << p.first << ' ' << p.second << '\n';
}