#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> need(n);
	vector<int> have(n);
	for (int i = 0; i < n; i++) {
		cin >> need[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> have[i];
	}
	long long l = 0, r = 4000000000;
	while (r - l > 1) {
		long long m = (l + r) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (m * need[i] > have[i]) {
				sum += have[i];
				sum -= m*need[i];
			}
			if (sum < -1000000000000) { i = n; }
		}
		if (sum + k >= 0) { l = m; }
		else {r = m - 1; }
	}
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (r * need[i] > have[i]) {
			sum += have[i];
			sum -= r*need[i];
			if (sum < -1000000000000) { i = n; }
		}
	}
	if (sum + k >= 0) { l = r; }

	cout << l;
	return 0;
}