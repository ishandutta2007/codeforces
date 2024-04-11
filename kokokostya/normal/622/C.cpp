#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> a(n);
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] == arr[i + 1]) { a[i] = a[i + 1] + 1; }
	}
	int l, r, x;
	for (int i = 0; i < m; i++) {
		cin >> l >> r >> x;
		if (arr[l - 1] != x) { cout << l; }
		else {
			if (l + a[l - 1] < r) { cout << a[l - 1] + l + 1; }
			else { cout << -1; }
		}
		cout << '\n';
	}

	return 0;
}