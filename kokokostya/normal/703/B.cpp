#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<long long> arr(n);
	long long sum = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < n; i++) {
		ans += arr[i] * arr[(i + 1) % n];
	}
	long long sum2 = 0;
	long long sum3 = 0;
	vector<bool> is(n);
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		a--;
		is[a] = 1;
		sum2 += arr[a];
		sum3 += arr[a] * arr[a];
	}
	for (int i = 0; i < n; i++) {
		if (!is[i]) {
			ans += sum2 * arr[i];
			if (is[(i + n - 1) % n])
				ans -= arr[i] * arr[(i + n - 1) % n];
			if (is[(i + 1) % n])
				ans -= arr[i] * arr[(i + 1) % n];
		}
		else {
			if (is[(i + n - 1) % n])
				ans -= arr[i] * arr[(i + n - 1) % n];
		}
	}
	cout << ans + (sum2 * sum2 - sum3) / 2;
	return 0;
}