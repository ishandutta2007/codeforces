#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
	long long n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int a[5000];
	for (int i = 0; i < 5000; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			a[arr[j] - arr[i]]++;
		}
	}
	long double s[5000];
	long double r = 1;
	s[0] = 0;
	for (int i = 1; i < 5000; i++) {
		s[i] = s[i - 1] + (a[i] / (r * n * (n - 1)));
	}
	long double res = 0;
	for (int i = 4999; i > 0; i--) {
		for (int j = i - 1; j > 0; j--) {
			res += a[i] * a[j] * s[i - j - 1];
		}
	}
	res *= 8;
	res /= n * (n - 1);
	res /= n * (n - 1);
	cout << setprecision(12) << res;
	return 0;
}