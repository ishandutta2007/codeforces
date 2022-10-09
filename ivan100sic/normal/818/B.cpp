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

int l[105], n, m;
int a[105];

int modd(int x) {
	if (x > n) {
		return x-n;
	}
	if (x < 1) {
		return x+n;
	}
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	set<int> unused;

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		cin >> l[i];
	}

	for (int i=1; i<=n; i++) {
		unused.insert(i);
	}

	for (int i=2; i<=m; i++) {
		int x = l[i-1];
		int y = l[i];

		int ax = modd(y-x);
		if (a[x] > 0 && a[x] != ax) {
			cout << -1;
			return 0;
		}

		if (a[x] == 0 && unused.count(ax) == 0) {
			cout << -1;
			return 0;
		}
		a[x] = ax;
		unused.erase(ax);
	}

	for (int i=1; i<=n; i++) {
		if (a[i] == 0) {
			if (unused.size() == 0) {
				cout << -1;
				return 0;
			}
			a[i] = *unused.begin();
			unused.erase(unused.begin());
		}
	}

	for (int i=1; i<=n; i++) {
		cout << a[i] << ' ';
	}

}