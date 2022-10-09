#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

vector<pair<int, int>> e[100005];
long long a[100005], b[100005];
int n;

long long safemul(long long a, long long b) {
	double x = a * 1.0 * b;
	if (-4e18 < x && x < 4e18) {
		return a * b;
	} else if (x < 0) {
		return -4e18;
	} else {
		return 4e18;
	}
}

long long safeadd(long long a, long long b) {
	long long c = a + b;
	if (c < -4e18) {
		return -4e18;
	}
	if (c > 4e18) {
		return 4e18;
	}

	return c;
}

long long dfs(int x) {
	long long supply = 0;

	for (auto ee : e[x]) {
		long long r = dfs(ee.first);
		if (r > 0) {
			supply = safeadd(supply, r);
		} else {
			supply = safeadd(supply, safemul(r, ee.second));
		}
	}

	supply = safeadd(supply, b[x] - a[x]);

	// cerr << x << ' ' << supply << '\n';

	return supply;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> b[i];
	}
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for (int i=2; i<=n; i++) {
		int x, k;
		cin >> x >> k;
		e[x].push_back({i, k});
	}

	long long r = dfs(1);
	if (r < 0) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}