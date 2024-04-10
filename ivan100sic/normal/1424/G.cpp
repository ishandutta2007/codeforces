// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	map<int, int> e;

	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		e[x]++;
		e[y]--;
	}

	int to, zo=-1, z=0;

	for (auto [t, v] : e) {
		z += v;
		if (z > zo) {
			zo = z;
			to = t;
		}
	}

	cout << to << ' ' << zo << '\n';
}