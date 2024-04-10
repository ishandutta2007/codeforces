#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

pair<int, int> dod(pair<int, int> p, char x) {
	if (x == 'R')
		return {p.first + 1, p.second};
	else if (x == 'L')
		return {p.first - 1, p.second};
	else if (x == 'U')
		return {p.first, p.second + 1};
	else if (x == 'D')
		return {p.first, p.second - 1};
	else if (x == 'X')
		return {p.first + 2, p.second};
	return {-1, -1};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;

	basic_string<pair<int, int>> e;
	e += {1, 1};

	string s = "RRRRRRRULLLLLLLURRRRRRRULLLLLLLURRRRRRRULLLLLLLU";
	s += "URDRURDRURDXLUR";

	for (int i=0; i<n-2; i++) {
		e.push_back(dod(e.back(), s[i]));
	}

	if (n == 63) {
		e.push_back(dod(e.back(), s[61]));
		e.push_back(dod(e.back(), s[62]));
	} else if (n == 62) {
		e.pop_back();
		e.push_back(dod(e.back(), 'R'));
		e.push_back(dod(e.back(), 'U'));
		e.push_back(dod(e.back(), 'R'));
	} else {
		if (e.back().first == 8) {
			e.push_back({8, e.back().second + 1});
			e.push_back({8, 8});
		} else if (e.back().second == 8) {
			e.push_back(dod(e.back(), 'R'));
			e.push_back({8, 8});
		} else if (e.back().second < 7) {
			e.push_back({e.back().first, 8});
			e.push_back({8, 8});
		} else {
			e.push_back({8, e.back().second});
			e.push_back({8, 8});
		}
	}

	for (auto f : e) {
		cout << (char)(f.first + 96) << f.second << ' ';
	}
	cout << '\n';
}