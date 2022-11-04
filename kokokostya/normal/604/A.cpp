#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	vector<int> m(5);
	vector<int> w(5);
	for (int i = 0; i < 5; i++) {
		cin >> m[i];
	}
	for (int i = 0; i < 5; i++) {
		cin >> w[i];
	}
	vector<int> arr(5);
	for (int i = 0; i < 5; i++) {
		arr[i] = 500 * (i + 1);
	}
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		ans += max(3 * arr[i] / 10, (250 - m[i]) * arr[i] / 250 - 50 * w[i]);
	}
	int n, k;
	cin >> n >> k;
	ans += 100 * n - 50 * k;
	cout << ans;

	return 0;
}