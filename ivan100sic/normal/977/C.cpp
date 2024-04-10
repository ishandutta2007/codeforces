#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;

int n, k;

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	if (k > 0) {
		int x = a[k - 1];
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] <= x) {
				c++;
			}
		}

		if (c != k) {
			cout << -1;
		}
		else {
			cout << x;
		}
	}
	else {
		if (a[0] == 1) {
			cout << -1;
		}
		else {
			cout << 1;
		}
	}

	
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}