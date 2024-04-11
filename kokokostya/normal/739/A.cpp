#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int l, r;
	int mn = 1e9;
	for (int i = 0; i < m; i++) {
		cin >> l >> r;
		mn = min(mn, r - l + 1);
	}
	cout << mn << '\n';
	int now = 0;
	for (int i = 0; i < n; i++) {
		cout << now << ' ';
		now = (now + 1) % mn;
	}
	return 0;
}