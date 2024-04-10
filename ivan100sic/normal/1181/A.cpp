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

	ll x, y, z;
	cin >> x >> y >> z;
	if (x%z + y%z >= z) {
		cout << x/z+y/z+1 << ' ' << min(z-x%z, z-y%z) << '\n';
	} else {
		cout << x/z+y/z << " 0\n";
	}
}