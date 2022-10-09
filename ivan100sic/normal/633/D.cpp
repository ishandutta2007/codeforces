#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[1005];

unordered_multiset<int> b;

int napravi(int x, int y) {
	vector<int> erased;
	b.erase(b.find(x));
	b.erase(b.find(y));
	erased = { x, y };
	while (1) {
		int z = x + y;
		auto it = b.find(z);
		if (it == b.end()) {
			break;
		}
		b.erase(it);
		erased.push_back(z);
		int x1 = y;
		int y1 = z;
		x = x1;
		y = y1;
	}
	for (int z : erased) {
		b.insert(z);
	}
	return erased.size();
}

int f[1005], c[1005];

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b.insert(a[i]);
	}

	copy(a, a + n, f);
	sort(f, f + n);
	c[0] = 1;
	int k = 1;
	int sol = 0;
	for (int i = 1; i < n; i++) {
		if (f[i] == f[i - 1]) {
			c[k - 1]++;
		}
		else {
			k++;
			c[k - 1] = 1;
			f[k - 1] = f[i];
		}
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (j == i && c[j] == 1) {
				continue;
			}
			sol = max(sol, napravi(f[i], f[j]));
		}
	}

	cout << sol << '\n';
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}