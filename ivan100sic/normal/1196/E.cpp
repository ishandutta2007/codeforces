#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int limit(int x) {
	return 1 + 3*x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		int b, w;
		cin >> b >> w;

		int x = 10, y = 10;

		if (b < w) {
			swap(b, w);
			x++;
		}

		if (b > limit(w)) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for (int i=0; i<w; i++)
				cout << x+2*i << ' ' << y << '\n';
			// izmedju
			for (int i=0; i<=w && b; i++, b--)
				cout << x+2*i-1 << ' ' << y << '\n';
			// gore
			for (int i=0; i<w && b; i++, b--)
				cout << x+2*i << ' ' << y+1 << '\n';
			// dole
			for (int i=0; i<w && b; i++, b--)
				cout << x+2*i << ' ' << y-1 << '\n';
		}
	}
}