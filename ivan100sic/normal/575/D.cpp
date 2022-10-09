#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef set<pair<int, int>> spii;

spii evolve(int n, spii s) {
	spii t;
	for (auto [x, y] : s) {
		for (int dx=-1; dx<=1; dx+=2) {
			for (int y2=1; y2<=2; y2++) {
				if (x+dx >= 1 && x+dx <= n) {
					t.insert({x+dx, y2});
				}
			}
		}
	}
	return t;
}

void rek(int n, basic_string<pair<int, int>> st, set<pair<int, int>> mozda) {
	if (mozda.size() == 0) {
		for (auto [x, y] : st) {
			cerr << x << ' ' << y << '\n';
		}
		exit(0);
		return;
	}
	if ((int)st.size() > 6)
		return;
	for (int x1=1; x1<=n; x1++) {
		for (int y1=1; y1<=2; y1++) {
			for (int x2=1; x2<=n; x2++) {
				for (int y2=1; y2<=2; y2++) {
					if (x1 == x2 && y1 == y2) {
						continue;
					}

					auto tmp = mozda;

					tmp.erase({x1, y1});
					tmp.erase({x2, y2});

					tmp = evolve(n, tmp);

					auto t = st;
					t += {x1, y1};
					t += {x2, y2};

					rek(n, t, tmp);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// int n;
	// cin >> n;

	// spii s;
	// for (int x=1; x<=n; x++)
	// 	for (int y=1; y<=2; y++)
	// 		s.insert({x, y});
	// rek(n, {}, s);

	const int n = 1000;
	cout << 2*n-4 << '\n';
	for (int i=2; i<=n-1; i++)
		cout << i << " 1 " << i << " 2\n";
	for (int i=n-1; i>=2; i--)
		cout << i << " 1 " << i << " 2\n";
}