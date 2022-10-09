#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, sol=2.05e9, cnt=1;
	cin >> n;
	vector<int> a(n);
	for (int& x : a) {
		cin >> x;
	}
	sort(a.begin(), a.end());
	for (int i=1; i<n; i++) {
		int d = a[i] - a[i-1];
		if (d == sol) {
			cnt++;
		} else if (d < sol) {
			sol = d;
			cnt = 1;
		}
	}
	cout << sol << ' ' << cnt;
}