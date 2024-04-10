#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void solve() {
	int n;
	cin >> n;
	map<int, int> bf;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		bf[x]++;
	}

	map<int, int> ms;
	for (auto [x, y] : bf)
		ms[y]++;

	int xd = 0, candies = 0;
	for (int i=n; i>=1; i--) {
		xd += ms[i];
		if (xd > 0) {
			xd--;
			candies += i;
		}
	}
	cout << candies << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}