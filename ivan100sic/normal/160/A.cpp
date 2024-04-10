#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a) {
		cin >> x;
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	int sum = accumulate(a.begin(), a.end(), 0);
	int s = 0;
	for (int i=0; i<n; i++) {
		s += a[i];
		if (s > sum-s) {
			cout << i+1;
			return 0;
		}
	}
}