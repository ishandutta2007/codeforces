#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<pair<int, int>> e;
int n;

void napravi(int o, int k) {
	int n = k + 2;
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++) {
			bool ok = true;
			if ((i == 0 || i == n-2) && j == n-1)
				ok = false;
			if (i % 2 && j == i+1)
				ok = false;
			if (ok)
				e += {o+i, o+j};
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int k;
	cin >> k;

	if (k % 2 == 0) {
		cout << "NO\n";
		return 0;
	}

	if (k == 1) {
		e += {1, 2};
		n = 2;
	} else {
		napravi(1, k);
		napravi(k+3, k);
		e += {k+2, 2*k+4};
		n = 2*k+4;
	}

	cout << "YES\n";
	cout << n << ' ' << e.size() << '\n';
	for (auto [x, y] : e)
		cout << x << ' ' << y << '\n';
}