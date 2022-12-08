#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;

bool comp(pair<int, int> x, pair<int, int> y) {
	if (x.first > y.first) return true;
	return false;
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		if (n > 1) {
			cout << "0\n";
		}
		else {
			cout << "1\n";
		}
	}
	else if (n > m) {
		cout << "0\n";
	}
	else {
		sort(a.begin(), a.end());
		vector<int> count(101);
		vector<pair<int, int>> ans;
		for (int i = 0; i < m; i++) {
			count[a[i]]++;
			if (i != 0 and a[i - 1] != a[i]) {
				ans.push_back({ count[a[i - 1]], a[i - 1] });
			}
		}
		ans.push_back({ count[a[m - 1]], a[m - 1] });
		sort(ans.begin(), ans.end());
		vector<pair<int, int>> f(n, { 0, 0 });
		for (int i = ans.size() - 1; i >= max(0, (int)ans.size() - n); i--) {
			f[ans.size() - 1 - i] = ans[i];
		}
		while (!(f[0].second == f[n - 1].second and abs(f[0].first - f[n - 1].first) <= 1) and !(f[0].second != f[n - 1].second and f[n - 1].first > floor(f[0].first / 2))) {
			if (f[0].second == f[n - 1].second) {
				int h = (f[0].first + f[n - 1].first) / 2;
				f[n - 1].first = f[0].first + f[n - 1].first - h;
				f[0].first = h;
				//cout << "wedew______1\n";
			}
			else {
				int h = f[0].first / 2;
				f[n - 1] = { f[0].first - h, f[0].second };
				f[0].first = h;
				//cout << "wdwedewd________2      " << f[n - 1].first << "\n";
			}
			sort(f.begin(), f.end(), comp);
		}
		cout << f[n - 1].first << "\n";
	}
	//system("pause");
	return 0;
}