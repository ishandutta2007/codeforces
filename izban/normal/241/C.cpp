#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int hl, hr, n;
vector<pair<pair<int, int>, int> > v[2];
int ans;

void work() {
	for (int i = 1; i <= n; i++) {
		int dx = 1e5;
		int dy = hl + (i - 1) * 100;
		if (i % 2) dy += hr;
		else dy += 100 - hr;

		vector<vector<int> > cnt(2, vector<int>());
		cnt[0].resize(v[0].size());
		cnt[1].resize(v[1].size());

		bool ok = true;
		for (int j = 1; j <= i; j++) {
			double x = (double)hl * dx / dy + (j - 1) * 100.0 / dy * dx;
			bool ok2 = false;
			for (int k = 0; k < v[!(j%2)].size(); k++) {
				if (v[!(j%2)][k].first.first <= x && v[!(j%2)][k].first.second >= x) {
					cnt[!(j%2)][k]++;
					ok2 = true;
					break;
				}
			}
			ok &= ok2;
		}
		if (!ok) continue;
		int res = 0;
		for (int k = 0; k < 2; k++) {
			for (int j = 0; j < v[k].size(); j++) {
				if (cnt[k][j] > 1) ok = 0;
				if (cnt[k][j] == 1) res += v[k][j].second;
			}
		}
		if (ok) ans = max(ans, res);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> hl >> hr >> n) {
		v[0].clear(); v[1].clear();
		for (int i = 0; i < n; i++) {
			int V, a, b;
			char c;
			cin >> V >> c >> a >> b;
			if (c == 'F') {
				v[0].push_back(make_pair(make_pair(a, b), V));
			}
			if (c == 'T') {
				v[1].push_back(make_pair(make_pair(a, b), V));
			}
		}
		sort(v[0].begin(), v[0].end());
		sort(v[1].begin(), v[1].end());

		ans = 0;
		work();
		hl = 100 - hl; 
		hr = 100 - hr;
		swap(v[0], v[1]);
		work();

		cout << ans << endl;
	}

	return 0;
}