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

const double eps = 1e-9;

const int MAXN = 1 << 17;
const int MOD = 1000 * 1000 * 1000 + 7;

int n, m, k;
int a[MAXN], f[MAXN];
vector<int> e[MAXN];
pair<int, int> o[MAXN];

struct comparator {
	bool operator() (const int &i, const int &j) const {
		ll x = 1LL * o[i].first * o[j].second - 1LL * o[j].first * o[i].second;
		if (x == 0) return i < j;
		return x < 0;
	}
};

pair<int, int> solve(bool print, pair<int, int> need) {
	set<int, comparator> st;
	for (int i = 0; i < n; i++) {
		if (f[i]) continue;
		o[i] = make_pair(0, 0);
		for (int j = 0; j < (int)e[i].size(); j++) {
			o[i].first += !f[e[i][j]];
			o[i].second++;
		}
		st.insert(i);
	}

	pair<int, int> ans = make_pair(-1, 1);
	while (!st.empty()) {
		int v = *st.begin();

		if (print && 1LL * need.first * o[v].second == 1LL * o[v].first * need.second) {
			printf("%d\n", st.size()); 
			for (set<int, comparator> :: iterator it = st.begin(); it != st.end(); it++) {
				printf("%d ", *it + 1);
			}
			printf("\n");
			return need;
		}

		st.erase(st.begin());

		if (1LL * ans.first * o[v].second < 1LL * o[v].first * ans.second) {
			ans = o[v];
		}

		vector<int> ooo;
		for (int i = 0; i < (int)e[v].size(); i++) {
			if (st.count(e[v][i]) != 0) {
				ooo.push_back(e[v][i]);
				st.erase(e[v][i]);
			}
		}
		for (int i = 0; i < (int)ooo.size(); i++) {
			o[ooo[i]].first--;
			st.insert(ooo[i]);
		}
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d%d%d", &n, &m, &k) == 3) {
		memset(f, 0, sizeof(f));
		for (int i = 0; i < n; i++) e[i].clear();

		for (int i = 0; i < k; i++) {
			scanf("%d", &a[i]);
			f[--a[i]] = 1;
		}

		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u; --v;
			e[u].push_back(v);
			e[v].push_back(u);
		}

		solve(1, solve(0, make_pair(-1, -1)));
	}

	return 0;
}