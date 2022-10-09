#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <list>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[100005], n, A, B;

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> A >> B;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + n);
	int sol = 0, c = 1, t = a[0];
	for (int i = 1; i < n; i++) {
		if (B * 1ll * t <= a[0] * 1ll * A) {
			sol = c;
		}
		c += 1;
		t += a[i];
	}
	if (B * 1ll * t <= a[0] * 1ll * A) {
		sol = c;
	}
	cout << n - sol << '\n';
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}