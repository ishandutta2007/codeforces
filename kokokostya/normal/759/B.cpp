#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> t(n), ans(n + 1);
	for (int i = 0; i < n; i++)
		cin >> t[i];
	for (int i = 0; i < n; i++) {
		ans[i + 1] = ans[i] + 20;
		int fr = t[i] + 1 - 90;
		int l = 0, r = i;
		while (l != r) {
			int m = (l + r) / 2;
			if (t[m] >= fr)
				r = m;
			else
				l = m + 1;
		}
		ans[i + 1] = min(ans[i + 1], ans[l] + 50);
		fr = t[i] + 1 - 1440;
		l = 0, r = i;
		while (l != r) {
			int m = (l + r) / 2;
			if (t[m] >= fr)
				r = m;
			else
				l = m + 1;
		}
		ans[i + 1] = min(ans[i + 1], ans[l] + 120);
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] - ans[i - 1] << '\n';
	return 0;
}