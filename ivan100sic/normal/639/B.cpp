#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, d, h;
	cin >> n >> d >> h;

	if (2*h < d || (n > 2 && d == 1))
		return cout << -1, 0;

	// dva putica, h, d-h
	if (h != d) {
		int nd = 1;

		int prev = 1;
		for (int i=0; i<h; i++) {
			nd++;
			cout << prev << ' ' << nd << '\n';
			prev = nd;
		}

		prev = 1;
		for (int i=0; i<d-h; i++) {
			nd++;
			cout << prev << ' ' << nd << '\n';
			prev = nd;
		}

		for (int i=0; i<n-1-d; i++) {
			nd++;
			cout << "1 " << nd << '\n';
		}
	} else {
		int nd = 1;

		int prev = 1;
		for (int i=0; i<h; i++) {
			nd++;
			cout << prev << ' ' << nd << '\n';
			prev = nd;
		}

		for (int i=0; i<n-1-d; i++) {
			nd++;
			cout << "2 " << nd << '\n';
		}
	}		

}