#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	int r = 1, s = 500000000;
	for (int i = 1; i <= n; i++) {
		int t = (i - 1) / 2;
		if (m == 0) {
			ans.push_back(s);
			s += r;
			continue;
		}
		if (m - t > 0) {
			ans.push_back(i);
			m -= t;
		}
		else {
			int t = 2 * (i - 1) - (m * 2 - 1);
			ans.push_back(t);
			m = 0;
			s = t + i; r = t + 1;
			if (s % r == 0) s++;
		}
	}
	if (m != 0) {
		cout << -1 << '\n';
		return 0;
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << '\n';
	return 0;
}