#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	int t, s;
	cin >> n >> k >> s >> t;
	vector< pair<int, int> > car(n);
	for (int i = 0; i < n; i++)
		cin >> car[i].first >> car[i].second;
	vector<int> d;
	vector<int> y(k);
	int now = 0;
	for (int i = 0; i < k; i++) {
		cin >> y[i];
	}
	sort(y.begin(), y.end());
	for (int i = 0; i < k; i++) {
		d.push_back(y[i] - now);
		now = y[i];
	}
	d.push_back(s - now);
	k++;
	int l = 0, r = 1e9 + 7;
	while (l != r) {
		int m = (l + r) / 2;
		long long res = 0;
		for (int i = 0; i < k; i++) {
			if (d[i] > m) {
				res = t + 1;
				i = k;
			}
			else {
				int e = m - d[i];
				if (e >= d[i])
					res += d[i];
				else
					res += e + (d[i] - e) * 2;
			}
		}
		if (res > t) {
			l = m + 1;
		}
		else
			r = m;
	}
	int mn = 2 * 1e9;
	for (int i = 0; i < n; i++) {
		if (car[i].second >= l && car[i].first < mn)
			mn = car[i].first;
	}
	if (mn == 2 * 1e9)
		cout << -1;
	else
		cout << mn;
	return 0;
}