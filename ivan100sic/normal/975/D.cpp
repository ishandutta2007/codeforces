#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, a, b;
map<ll, int> p1, p2;

ll kek(map<ll, int>& m) {
	ll z = 0;
	for (auto p : m) {
		z += p.second * (p.second - 1ll);
	}
	return z;
}

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		ll x, vx, vy;
		cin >> x >> vx >> vy;
		p1[a*vx - vy]++;
		p2[4123123123ll * vx + vy]++;
	}

	cout << kek(p1) - kek(p2) << '\n';
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}