#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = -1;
const int MAXN = 1 << MAXK;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;
const int INF = 1.01e9;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	
	int n;
	vector<int> c(2);
	while (scanf("%d%d%d", &n, &c[0], &c[1]) == 3) {
		vector<int> b(n), p(n), t(n);

		vector<vector<pair<int, int> > > a(2);
		for (int i = 0; i < n; i++) {
			char cc;
			scanf("%d%d %c", &b[i], &p[i], &cc);
			t[i] = cc - 'C';
			a[t[i]].push_back(make_pair(p[i], b[i]));
		}
		
		for (int i = 0; i < 2; i++) sort(a[i].begin(), a[i].end());
		
		vector<int> mx(2, -1);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < (int)a[i].size(); j++) {
				if (a[i][j].first <= c[i]) {
					mx[i] = max(mx[i], a[i][j].second);
				}
			}
		}

		int ans = 0;
		if (mx[0] != -1 && mx[1] != -1) ans = mx[0] + mx[1];

		for (int i = 0; i < 2; i++) {
			vector<pair<int, int> > vct;
			for (int j = 0; j < (int)a[i].size(); j++) {
				while (!vct.empty() && a[i][j].first + vct.back().first > c[i]) vct.pop_back();
				if (!vct.empty()) ans = max(ans, a[i][j].second + vct.back().second);
				if (vct.empty() || vct.back().second < a[i][j].second) vct.push_back(a[i][j]);
			}
		}
		cout << ans << endl;
	}

	return 0;
}