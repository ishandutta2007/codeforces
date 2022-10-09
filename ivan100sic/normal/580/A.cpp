#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
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
	int r=1, s=1;
	for (int i=1; i<n; i++) {
		if (a[i-1] <= a[i]) {
			r++;
		} else {
			r = 1;
		}
		s = max(s, r);
	}
	cout << s;
}