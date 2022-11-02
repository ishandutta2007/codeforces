#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

vector<pair<pair<int, int>, int> > ans;
int a[10009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		ans.clear();
		int s = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			s += a[i];
			if (i == 1) continue;
			if (a[i] % i != 0) {
				ans.push_back(make_pair(make_pair(1, i), i - (a[i] % i)));
				a[i] = (a[i] / i + 1) * i;
			}
			ans.push_back(make_pair(make_pair(i, 1), a[i] / i));
			a[1] += a[i];
			a[i] = 0;
		}
		if (s % n != 0) {
			cout << -1 << '\n';
			continue;
		}
		s /= n;
		for (int i = 2; i <= n; i++)
			ans.push_back(make_pair(make_pair(1, i), s));
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << '\n';
	}
	return 0;
}