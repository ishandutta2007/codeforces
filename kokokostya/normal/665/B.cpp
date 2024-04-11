#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> arr(k);
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		arr[a - 1] = i + 1;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			ans += arr[a - 1];
			for (int q = 0; q < k; q++) {
				if (arr[q] < arr[a - 1]) { arr[q]++; }
			}
			arr[a - 1] = 1;
		}
	}
	cout << ans;

	return 0;
}