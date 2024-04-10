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

ll a[14];
ll b[14];

ll run(int i) {
	ll q = a[i] / 14;
	ll r = a[i] % 14;

	copy(a, a + 14, b);
	b[i] = 0;
	for (int j = 0; j < 14; j++) {
		b[j] += q;
	}
	for (int j = 0; j < r; j++) {
		b[(i + j + 1) % 14]++;
	}

	ll s = 0;

	for (int i = 0; i < 14; i++) {
		if (b[i] % 2 == 0) {
			s += b[i];
		}
	}

	return s;
}

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n = 14;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ll sol = 0;
	for (int i = 0; i < n; i++) {
		sol = max(sol, run(i));
	}
	cout << sol << '\n';
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}