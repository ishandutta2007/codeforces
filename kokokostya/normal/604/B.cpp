#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	vector <long long> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (k >= n) { cout << arr[n - 1]; return 0; }
	long long l = (n - k);
	long long ans = arr[n - 1];
	for (int i = 0; i < l; i++) {
		if (arr[i] + arr[2 * l - i - 1]>ans) {
			ans = arr[i] + arr[2 * l - i - 1];
		}
	}
	cout << ans;
	return 0;
}