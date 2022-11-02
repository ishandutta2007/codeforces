#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> a[109];
vector<int> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int r = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
		r += a[i].first;
	}
	r = r / 2 + 1;
	ans.push_back(1);
	sort(a + 1, a + n);
	int s = a[0].first;
	for (int i = n - 1; i >= 1; i--) {
		if (a[i].first * 2 > a[0].first) continue;
		s += a[i].first;
		ans.push_back(a[i].second);
		if (s >= r) break;
	}
	if (s < r) cout << 0 << '\n';
	else {
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
	return 0;
}