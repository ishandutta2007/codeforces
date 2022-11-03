#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	long long l = 0, r = n;
	while (l * (l + 1) / 2 <= k) { l++; }
	 l--;
	 if (l * (l + 1) / 2 == k) { cout << arr[l - 1]; }
	 else {
		 cout << arr[k - (l + 1) * l / 2 - 1];
	 }
	return 0;
}