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

int n, q;
ll a[200005];
ll b[200005];

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = b[i - 1] + a[i];
	}

	ll z = 0;

	while (q--) {
		ll y;
		cin >> y;
		
		z += y;

		auto it = upper_bound(b + 1, b + n + 1, z) - b - 1;
		
		if (z >= b[n]) {
			it = 0;
			z = 0;
		}

		cout << n - it << '\n';
	}
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}