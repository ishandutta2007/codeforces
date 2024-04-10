#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long int ll;

int main() {
	int n, m, t;
	cin >> n >> m;
	vector<pair<int, int>> taxi;
	vector<int> man;
	vector<int> a(n + m);
	for (int i = 0; i < n + m; i++) cin >> a[i];
	for (int i = 0; i < n + m; i++) {
		cin >> t;
		if (t == 0) {
			man.push_back(a[i]);
		}
		else {
			if (taxi.size() == 0) {
				taxi.push_back({ a[i], 0 });
			}
			else {
				taxi.push_back({ a[i], taxi[taxi.size() - 1].second + 1 });
			}
		}
	}
	vector<int> ans(m);
	for (int i = 0; i < n; i++) {
		int l = 0;
		int r = m;
		while (r - l > 1) {
			int mid = (r + l) / 2;
			if (taxi[mid].first > man[i]) {
				r = mid;
			}
			else {
				l = mid;
			}
		}
		if (r == m || (man[i] - taxi[l].first <= taxi[r].first - man[i])) {
			ans[l]++;
		}
		else {
			ans[r]++;
		}
	}
	//cout << "hui\n";
	for (int i = 0; i < m; i++) cout << ans[i] << " ";
	//system("pause");
	return 0;
}