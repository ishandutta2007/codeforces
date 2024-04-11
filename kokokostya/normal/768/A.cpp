#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mx = 0, mn = 2e9;
	for (int i = 0; i < n; i++) {
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	int ans = 0;
	for (int i : a)
		if (mn < i && i < mx)
			ans++;
	cout << ans;
	return 0;
}