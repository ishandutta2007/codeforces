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

int n, m, k;
vector<int> e;

int pw(int x, int y) {
	if (y < 0) return 0;
	if (y == 0) return 1;
	int ans = pw(x, y / 2);
	ans = 1LL * ans * ans % mod;
	if (y & 1) ans += ans; if (ans >= mod) ans -= mod;
	return ans;
}

bool reading() {
	e.clear();
	if (!(cin >> n >> m >> k)) return 0;
	bool ok = 1;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if (!(v - u == 1 || v - u == k + 1)) {
			ok = 0;
		}
		if (v - u == k + 1) e.push_back(u);
	}
	if (!ok) {
		cout << "0\n";
		return 1;
	}
	sort(e.begin(), e.end());
	if (!e.empty() && e.front() + k + 1 <= e.back()) {
		cout << "0\n";
		return 1;
	}

	int ans = 1, toadd = e.size();
	for (int i = 1; i <= n; i++) {
		if (!e.empty() && (i + k + 1 <= e.back() || e.front() + k + 1 <= i)) continue;
		int len = min(n - k - 1, min(i + k, !e.empty() ? e.front() + k : inf)) - i;
		toadd -= binary_search(e.begin(), e.end(), i);
		ans += pw(2, len - toadd) - (!e.empty() && e[0] == i);
		if (ans >= mod) ans -= mod;
		if (!e.empty() && e[0] == i) break;
	}
	cout << ans << endl;

	return 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (reading());

	return 0;
}