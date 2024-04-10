#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	vector<int> f(n);
	for (int i = 0; i < n; ++i) {
		cin >> f[i];
	}
	sort(f.begin(), f.end(), greater<int>());
	int result = 0;
	for (int i = 0; i < n; i += k) {
		result += (f[i] - 1) * 2;
	}
	cout << result << endl;
	return 0;
}