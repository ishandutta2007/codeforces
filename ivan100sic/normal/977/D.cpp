#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int n, k;

int p(ll x, int y) {
	int z = 0;
	while (x % y == 0) {
		x /= y;
		z++;
	}
	return z;
}

bool cmp(ll x, ll y) {
	return p(x, 2) - p(x, 3) < p(y, 2) - p(y, 3);
}

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<ll> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end(), cmp);
	for (ll x : a) {
		cout << x << ' ';
	}
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}