// Hydro submission #61aad71fef9a89de1e7604a9@1638586144253
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void solve() {
	int n, l, r, s, dis;
	cin >> n >> l >> r >> s;
	dis = r - l + 1;
	vector<int>ans(n + 1, -1);
	vector<bool>vis(n + 1, false);

	if (s < dis * (1 + dis) / 2 || s > dis * (2 * n + 1 - dis) / 2) {
		cout << -1 << endl;
		return;
	}
	int now = dis * (1 + dis) / 2;	
	int cnt = 0;	//nows
	int left = 0;	
	while (now + (cnt + 1 ) * dis <= s && dis + (cnt + 1) <= n) {
		++cnt;
	}
	left = s - (now + cnt * dis);

	for (int i = l, num; i <= r; ++i) {
		num = (i - l + 1) + cnt;
		if (i <= r - left);
		else
			num += 1;

		if (!vis[num]) {
			ans[i] = num;
			vis[num] = true;
		}
	}

	int index = 1;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			while (index >= l && index <= r)
				++index;

			ans[index] = i;
			++index;
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	cout << endl;
	return;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}