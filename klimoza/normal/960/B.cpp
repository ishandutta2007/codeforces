#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(long long int x, long long int y) {
	if (y < x) return true;
	return false;
}



int main() {
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	vector<long long int> diff(n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long int t1 = 0;
	for (int i = 0; i < n; i++) {
		cin >> t1;
		diff[i] = abs(t1 - a[i]);
	}
	sort(diff.begin(), diff.end(), comp);
	int j = 0;
	for (int i = 0; i < k1 + k2; i++) {
		diff[0] = abs(diff[0] - 1);
		j = 0;
		while (j < n - 1 and diff[j] < diff[j + 1]) {
			t1 = diff[j];
			diff[j] = diff[j + 1];
			diff[j + 1] = t1;
			j++;
		}
	}
	long long int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += diff[i] * diff[i];
	}
	cout << ans << "\n";
}