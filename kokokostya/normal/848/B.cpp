#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>

using namespace std;

const int MX = 1e5 + 5;

int main() {
	ios_base::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, w, h;
	cin >> n >> w >> h;
	vector< vector< pair<int, int> > > x(w), y(h);
	vector< pair<int, int> > ans(n);
	for (int i = 0; i < n; i++) {
		int g, p, t;
		cin >> g >> p >> t;
		if (g == 1) {
			x[p].push_back({t, i});
		}
		else {
			y[p].push_back({t, i});
		}
	}
	vector< vector< pair<int, int> > > tm(2 * MX);
	for (int i = h - 1; i >= 0; i--) {
		for (pair<int, int> j : y[i])
			tm[j.first + (h - i)].push_back({ i, j.second });
	}
	vector<int> pos(2 * MX);
	for (int i = 0; i < w; i++) {
		if(!x[i].empty())
		sort(x[i].begin(), x[i].end());
		for (pair<int, int> j : x[i]) {
			int val = j.first - i + h;
			if (val >= 0) {
				if (!tm[val].empty()) {
					ans[tm[val][pos[val]].second] = { i, h };
					pos[val]++;
					tm[val].push_back({ 0, j.second });
				}
				else {
					ans[j.second] = { i, h };
				}
			}
			else {
				ans[j.second] = { i, h };
			}
		}
	}
	for (int i = 0; i < 2 * MX; i++) {
		for (int j = pos[i]; j < tm[i].size(); j++) {
			ans[tm[i][j].second] = { w, tm[i][j - pos[i]].first};
		}
	}
	for (pair<int, int> i : ans)
		cout << i.first << ' ' << i.second << '\n';
	return 0;
}