#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i].first >> x[i].second;
	}
	vector<pair<int, int>> y(m);
	for (int i = 0; i < m; i++) {
		cin >> y[i].first >> y[i].second;
	}
	bool fl = true;
	int ans = 0;
	vector<set<int>> f(n);
	set<int> total;
	int maxi = 0;
	vector<set<int>> fj(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((x[i].first == y[j].first and x[i].second != y[j].second) or (x[i].first == y[j].second and x[i].second != y[j].first) or (x[i].second == y[j].first and x[i].first != y[j].second) or (x[i].second == y[j].second and x[i].first != y[j].first)) {
				//cout << x[i].first << "     " << x[i].second << "        " << y[j].first << "       " << y[j].second << "    " << j << "\n";
				ans = x[i].first;
				if (x[i].second == y[j].first or x[i].second == y[j].second) {
					ans = x[i].second;
				}
				f[i].insert(ans);
				total.insert(ans);
				fj[j].insert(ans);
			}
		}
		maxi = max(maxi, int(f[i].size()));
	}
	//cout << total << "\n";
	if (total.size() == 1) {
		cout << ans << "\n";
	}
	else if (maxi != 1) {
		cout << -1 << "\n";
	}
	else {
		maxi = 0;
		for (int i = 0; i < m; i++) {
			maxi = max(int(fj[i].size()), maxi);
		}
		if (maxi == 1) {
			cout << 0 << "\n";
		}
		else {
			cout << -1 << "\n";
		}
	}
	//system("pause");
	return 0;
}