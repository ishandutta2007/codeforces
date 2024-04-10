#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a;

struct rect {
	int xl, xr, yl, yr;
};

rect unutrasnjost(int i) {
	int aa = (a+1) / 2;
	if (i == 1)
		return {-aa, aa, 0, a};
	if (i % 3 == 2)
		return {-aa, aa, a + i/3*2*a, 2*a + i/3*2*a};
	if (i % 3 == 0)
		return {-a, 0  , 0 + i/3*2*a, a + i/3*2*a};
	if (i % 3 == 1)
		return {0, a   , 0 + i/3*2*a, a + i/3*2*a};

	return {};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int x, y;
	cin >> a >> x >> y;

	for (int i=1; i<=1123123; i++) {
		auto g = unutrasnjost(i);
		if (g.xl < x && x < g.xr && g.yl < y && y < g.yr) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << "-1\n";
}