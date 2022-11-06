#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000;

int main() {
	int n, m, k, s, ii, jj, p_pos, d_pos;
	scanf("%d%d%d%d", &n, &m, &k, &s);
	vector<int> dollar(n), pound(n);
	for (int i = 0; i < n; ++i) scanf("%d", &dollar[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &pound[i]);
	vector<pair<int, int>> gadget_d, gadget_p;
	for (int i = 0; i < m; ++i) {
		int t, c;
		scanf("%d%d", &t, &c);
		if (t == 1) gadget_d.push_back({c, i});
		else gadget_p.push_back({c, i});
	}
	gadget_p.push_back({INF, 0});
	gadget_d.push_back({INF, 0});
	sort(gadget_d.begin(), gadget_d.end());
	sort(gadget_p.begin(), gadget_p.end());
	vector<ll> sum_d(gadget_d.size()), sum_p(gadget_p.size());
	int l = 0, r = n + 1;
	while (l < r - 1) {
		int m = (l + r) / 2;
		int min_d = INF, min_p = INF;
		for (int i = 0; i < m; ++i) {
			if (dollar[i] < min_d) {
				min_d = dollar[i];
				d_pos = i;
			}
			if (pound[i] < min_p) {
				min_p = pound[i];
				p_pos = i;
			}
		}
		int sum = s;
		ii = 0, jj = 0;
		while (ii + jj < k) {
			ll val_d = (ll)gadget_d[ii].first * min_d;
			ll val_p = (ll)gadget_p[jj].first * min_p;
			if (sum < min(val_d, val_p)) break;
			sum -= min(val_d, val_p);
			if (val_p < val_d) ++jj;
			else ++ii;
		}
		if (ii + jj == k) r = m;
		else l = m;
	}
	if (r == n + 1) printf("-1\n");
	else {
		int min_d = INF, min_p = INF;
		for (int i = 0; i < r; ++i) {
			if (dollar[i] < min_d) {
				min_d = dollar[i];
				d_pos = i;
			}
			if (pound[i] < min_p) {
				min_p = pound[i];
				p_pos = i;
			}
		}
		int sum = s;
		ii = 0, jj = 0;
		while (ii + jj < k) {
			ll val_d = (ll)gadget_d[ii].first * min_d;
			ll val_p = (ll)gadget_p[jj].first * min_p;
			if (sum < min(val_d, val_p)) break;
			sum -= min(val_d, val_p);
			if (val_p < val_d) ++jj;
			else ++ii;
		}
		printf("%d\n", r);
		for (int i = 0; i < ii; ++i) {
			printf("%d %d\n", gadget_d[i].second + 1, d_pos + 1);
		}
		for (int i = 0; i < jj; ++i) {
			printf("%d %d\n", gadget_p[i].second + 1, p_pos + 1);
		}

	}
}