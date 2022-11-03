#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	int l = 0, r = 1000000000;
	int up, down;
	while (l != r) {
		int m = (l + r) / 2;
		long long u = k;
		for (int i = 0; i < n; i++) {
			if (arr[i] > m) { u -= arr[i] - m; }
		}
		if (u >= 0) { r = m; }
		else { l = m + 1; }
	}
	up = l;
	l = 0;
	r = 1000000000;
	while (l != r) {
		int m = (l + r + 1) / 2;
		long long u = k;
		for (int i = 0; i < n; i++) {
			if (arr[i] < m) { u -= m - arr[i]; }
		}
		if (u >= 0) { l = m; }
		else { r = m - 1; }
	}
	down = l;
	if (up - down <= 0) { 
		if (sum % n == 0) { up = down; }
		else {
			up = down + 1;
		}
	}
	cout << up - down;


	return 0;
}