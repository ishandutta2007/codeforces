#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int mn = 1e9 + 1;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mn = min(mn, a[i]);
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if ((a[i] - mn) % k == 0)
			ans += (a[i] - mn) / k;
		else {
			cout << -1;
			return 0;
		}
	}
	cout << ans;
	return 0;
}