#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[505], b[505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	basic_string<int> big, small;
	for (int i=1; i<=n; i++) {
		if (a[i] > 1)
			big += i;
		else
			small += i;
	}

	// ima resenja?
	int mesta = 0;
	if (big.size() == 0) {
		cout << "NO\n";
		return 0;
	} else if (big.size() == 1) {
		int x = big[0];
		mesta = b[x] = a[x];
	} else {
		for (int i=0; i<(int)big.size(); i++) {
			int x = big[i];
			if (i == 0 || i == (int)big.size() - 1)
				b[x] = a[x] - 1;
			else
				b[x] = a[x] - 2;
			mesta += b[x];
		}
	}

	if ((int)small.size() > mesta) {
		cout << "NO\n";
		return 0;
	}

	int diam = big.size() - 1;

	cerr << "small size " << small.size() << '\n';

	basic_string<pair<int, int>> grane;
	for (int i=0; i<(int)big.size()-1; i++) {
		int x = big[i];
		int y = big[i+1];
		grane += {x, y};
	}

	int prvi = big[0];
	int zadnji = big.back();

	if (small.size() && b[prvi]) {
		int s = small.back();
		small.pop_back();
		diam++;
		grane += {prvi, s};
		b[prvi]--;
	}

	if (small.size() && b[zadnji]) {
		int s = small.back();
		small.pop_back();
		diam++;
		grane += {zadnji, s};
		b[zadnji]--;
	}

	// sad rokaj sve ostalo

	while (small.size()) {
		for (int x : big) {
			if (b[x] > 0) {
				int s = small.back();
				small.pop_back();
				grane += {x, s};
				b[x]--;
				break;
			}
		}
	}

	cout << "YES " << diam << '\n';
	cout << grane.size() << '\n';
	for (auto p : grane) {
		cout << p.first << ' ' << p.second << '\n';
	}
}