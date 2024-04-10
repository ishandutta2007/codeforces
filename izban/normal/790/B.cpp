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

const int MAXK = 18;
const int MAXN = 1 << MAXK;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;

int n, k;
vector<int> e[MAXN];

ll ans = 0;

vector<pair<ll, ll> > dfs(int v, int pr) {
	vector<pair<ll, ll> > cnt(k, make_pair(0, 0));
	cnt[0] = make_pair(1, 0);
	for (int to : e[v]) {
		if (to == pr) continue;
		vector<pair<ll, ll> > ncnt = dfs(to, v);

		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				ans += 1LL * cnt[i].first * ncnt[j].second;
				ans += 1LL * ncnt[j].first * cnt[i].second;
				if ((i + j) > 0) ans += 1LL * cnt[i].first * ncnt[j].first;
				if ((i + j) > k) ans += 1LL * cnt[i].first * ncnt[j].first;
			}
		}
		for (int i = 0; i < k; i++) {
			cnt[i].first += ncnt[i].first;
			cnt[i].second += ncnt[i].second;
		}
	}
	vector<pair<ll, ll> > res(k);
	for (int i = 1; i < k; i++) res[i] = cnt[i - 1];
	res[0] = make_pair(cnt[k - 1].first, cnt[k - 1].second + cnt[k - 1].first);
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d%d", &n, &k) == 2) {
		for (int i = 0; i < n; i++) e[i].clear();

		for (int i = 0; i < n - 1; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u; --v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		ans = 0;
		dfs(0, 0);
		cout << ans << endl;
	}

	return 0;
}