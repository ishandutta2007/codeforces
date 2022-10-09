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

	int x, y, z, sol = 0;
	cin >> x >> y >> z;

	for (int i=0; i<=z; i++) {
		sol = max(sol, min(x+i, y+z-i));
	}
	cout << sol*2 << '\n';
}