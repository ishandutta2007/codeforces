#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool l(int p, int a) {
	return a <= p && 2*a >= p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	for (int p=0; p<=200; p++) {
		for (int q=0; q<p; q++) {
			for (int r=0; r<q; r++) {
				if (l(p, a) && l(q, b) && l(r, c) && l(r, d) && !l(q, d)) {
					cout << p << '\n' << q << '\n' << r << '\n';
					return 0;
				}
			}
		}
	}
	cout << "-1\n";
}