#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

pair<int, int> p[300009];
int t[300009];
vector<pair<pair<int, int>, int> > ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].first; p[i].second = i;
	}
	for (int i = 1; i <= n; i++)
		cin >> t[i];
	sort(p + 1, p + n + 1); sort(t + 1, t + n + 1);
	long long s = 0;
	for (int i = 1; i <= n; i++) {
		p[i].first = t[i] - p[i].first;
		s += p[i].first;
	}
	if (s != 0) {
		cout << "NO" << '\n';
		return 0;
	}
	int bi = 1;
	for (int i = 1; i <= n; i++) {
		if (p[i].first <= 0) continue;
		while (bi <= n && p[bi].first >= 0) bi++;
		if (i >= bi) {
			cout << "NO" << '\n';
			return 0;
		}
		int t = p[i].first + p[bi].first;
		int r = min(p[i].first, -p[bi].first);
		ans.push_back(make_pair(make_pair(p[i].second, p[bi].second), r));
		p[i].first -= r; p[bi].first += r;
		if (t >= 0) bi++;
		if (t > 0) i--;
	}
	cout << "YES" << '\n';
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << '\n';
	return 0;
}