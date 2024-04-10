// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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

	ll u, v;
	cin >> u >> v;
	if (u > v || (v-u) % 2 == 1) {
		cout << "-1\n";
		return 0;
	}

	if (u + v == 0)
		return cout << "0\n", 0;

	if (u == v) {
		cout << "1\n" << u << '\n';
		return 0;
	}

	if (((v-u)/2 ^ (v+u)/2) == u)
		return cout << "2\n" << (v-u)/2 << ' ' << (v+u)/2 << '\n', 0;

	cout << "3\n";
	cout << u << ' ' << (v-u)/2 << ' ' << (v-u)/2 << '\n';

}

// I will still practice daily...