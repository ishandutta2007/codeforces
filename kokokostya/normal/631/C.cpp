#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector< pair<int, int> > d(m);
	int j = 0;
	int k, t;
	for (int i = 0; i < m; i++) {
		cin >> k >> t;
		j++;
		while (j > 0 && t > d[j - 1].first) {
			j--;
		}
		d[j].first = t;
		d[j].second = k;
	}
	int l = 0;
	int r = d[0].first - 1;
	vector<int> ans(n);
	vector<int> p(d[0].first);
	for (int i = d[0].first; i < n; i++) {
		ans[i] = arr[i];
	}
	for (int i = 0; i < d[0].first; i++) {
		p[i] = arr[i];
	}
	sort(p.begin(), p.end());
	int h = d[0].first - 1;
	d.push_back({ 0, 0 });
	d[j + 1].first = 0;
	for (int i = 0; i <= j; i++) {
		if (d[i].second == 1) {
			for (int q = d[i].first; q > d[i + 1].first; q--) {
				ans[q - 1] = p[r];
				r--;
			}
		}
		else {
			for (int q = d[i].first; q > d[i + 1].first; q--) {
				ans[q - 1] = p[l];
				l++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';

	}

	return 0;
}