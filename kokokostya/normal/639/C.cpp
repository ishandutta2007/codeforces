#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	n++;
	vector<long long> arr(n);
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<long long> res = arr;
	long long h = n - 1;
	for (long long i = 0; i < n - 1; i++) {
		if (res[i] % 2 != 0) { h = i; break; }
		res[i + 1] = res[i + 1] + (res[i] / 2);
		res[i] %= 2;
	}
	long long sum = 0;
	bool is = 1;
	for (long long i = n - 1; i > h; i--) {
		sum += arr[i];
		if (abs(sum) > 20 * k) { is = 0; break; }
		sum *= 2;
		if (abs(sum) > 20 * k) { is = 0; break; }
	}
	long long ans = 0;
	if (is) {
		for (long long i = h; i >= 0; i--) {
			if (i == n - 1) {
				if (arr[h] == res[h] && (abs(sum - arr[i]) <= k)) { ans--; }
			}
			sum += res[i];
			if (abs(sum - arr[i]) <= k) { ans++; }
			sum *= 2;
			if (abs(sum) > 20 * k) { break; }
		}
	}
	cout << ans;
	return 0;
}