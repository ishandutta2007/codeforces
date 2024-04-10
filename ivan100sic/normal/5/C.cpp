#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct zag {
	int t, x;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	basic_string<zag> g;
	int a=0, b=1, i=0;
	for (char c : s) {
		if (c == '(') {
			g += {1, i};
		} else {
			if (g.size() && g.back().t == 0)
				g.pop_back();
			if (g.size()) {
				int x = g.back().x;
				g.pop_back();
				if (g.size() && g.back().t == 0) {
					x = g.back().x;
					g.pop_back();
				}
				int z = i - x + 1;
				if (z > a) {
					a = z;
					b = 1;
				} else if (z == a) {
					b++;
				}
				g += zag{0, x};
			}
		}
		i++;
	}
	cout << a << ' ' << b << '\n';
}