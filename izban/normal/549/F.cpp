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

const int MAXN = 1 << 19;

int n, k;
int a[MAXN];
int b[MAXN];

pair<int, int> t[2 * MAXN];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = make_pair(a[tl], tl);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}

pair<int, int> get(int v, int tl, int tr, int l, int r) {
	if (l > r) return make_pair(-1, -1);
	if (l == tl && r == tr) return t[v];
	int tm = (tl + tr) >> 1;
	return max(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

struct item {
	map<int, int> mp;
	int add;

	item() {
		add = 0;
	}
};

typedef item * pitem;

item tmp[MAXN];

ll ans;

pitem dfs(int l, int r) {
	if (l > r) {
		pitem res = new item();
		res->mp[b[l]]++;
		return res;
	}
	/*if (l == r) {
		pitem res = &tmp[l];
		res->mp[0]++;
		res->mp[b[l]]++;
		return res;
	}*/

	int cur = get(1, 0, n - 1, l, r).second;
	pitem a1 = dfs(l, cur - 1);
	pitem a2 = dfs(cur + 1, r);

	if (a1->mp.size() <= a2->mp.size()) {
		for (map<int, int> :: iterator it = a1->mp.begin(); it != a1->mp.end(); it++) {
			int sl = it->first;
			// (sr - sl - a[cur]) == 0
			int need = (a[cur] + sl) % k;
			if (a2->mp.count(need)) {
				ans += 1LL * it->second * a2->mp[need];
			}
		}
		for (map<int, int> :: iterator it = a1->mp.begin(); it != a1->mp.end(); it++) {
			a2->mp[it->first] += it->second;
		}
		return a2;
	} else {
		for (map<int, int> :: iterator it = a2->mp.begin(); it != a2->mp.end(); it++) {
			int sr = it->first;
			// (sr - sl - a[cur]) == 0
			int need = (sr - a[cur] % k + k) % k;
			if (a1->mp.count(need)) {
				ans += 1LL * it->second * a1->mp[need];
			}
		}
		for (map<int, int> :: iterator it = a2->mp.begin(); it != a2->mp.end(); it++) {
			a1->mp[it->first] += it->second;
		}
		return a1;
	}
}

ll slowsolve() {
	ll ans = 0;
	for (int l = 0; l < n; l++) {
		ll sum = 0;
		int mx = -1;
		for (int r = l; r < n; r++) {
			sum += a[r];
			mx = max(mx, a[r]);
			if (sum % k == mx && r > l) ans++;
		}
	}
	return ans;
}

ll fastsolve() {
	b[0] = 0;
	for (int i = 1; i <= n; i++) b[i] = (b[i - 1] + a[i - 1]) % k;

	ans = 0;
	build(1, 0, n - 1);
	dfs(0, n - 1);
	ans -= n;
	return ans;
}

void gen() {
	int C = 10;
	n = rand() % 50 + 1;
	k = rand() % C + 1;
	for (int i = 0; i < n; i++) a[i] = rand() % C % k;
}

void stress(bool f) {
	if (!f) return;
	for (int it = 0;; it++) {
		cerr << it << endl;
		gen();
		ll ans1 = fastsolve();
		ll ans2 = slowsolve();
		if (ans1 != ans2) {
			cout << fastsolve();
			cout << " instead of ";
			cout << slowsolve() << endl;
			cout << n << " " << k << endl;
			for (int i = 0; i < n; i++) cout << a[i] << " \n"[i + 1 == n];
			exit(0);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	stress(0);

	while (scanf("%d%d", &n, &k) == 2) {
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		cout << fastsolve() << endl;
	}

	return 0;
}