
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <functional>
#include <cstring>
//#include "optimization.h"

using namespace std;

typedef long long ll;
typedef long double ld;
const ll md = 1e9 + 7;
const ld eps = 1e-8;

struct frac {
	ll x, y;
	frac(){}
	frac(ll x, ll y): x(x), y(y){}
	bool operator==(const frac& ot) {
		return x * ot.y == y * ot.x;
	}
	bool operator<(const frac& ot) {
		return x * ot.y < y * ot.x;
	}
};

vector<int> tr;
int sz = 1;

void add(int v, int val) {
	v += sz - 1;
	tr[v] += val;
	while (v) {
		v = (v - 1) >> 1;
		tr[v] += val;
	}
	return;
}

int get(int v, int l, int r, int bg, int en) {
	if (bg >= r || l >= en) {
		return 0;
	}
	if (l >= bg && r <= en) {
		return tr[v];
	}
	int m = (l + r) >> 1;
	return get(2 * v + 1, l, m, bg, en) + get(2 * v + 2, m, r, bg, en);
}

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	ll w;
	cin >> n >> w;
	vector<ll> v(n), x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> v[i];
	}
	vector<frac> f1(n), f2(n);
	for (int i = 0; i < n; i++) {
		f1[i] = {-x[i], v[i] + w};
		if (f1[i].y < 0) {
			f1[i].x = -f1[i].x;
			f1[i].y = -f1[i].y;
		}
		f2[i] = {-x[i], v[i] - w};
		if (f2[i].y < 0) {
			f2[i].x = -f2[i].x;
			f2[i].y = -f2[i].y;
		}
	}

	vector<int> all(n);
	for (int i = 0; i < n; i++) {
		all[i] = i;
	}

	vector<int> F2(n);
	sort(all.begin(), all.end(), [&](int a, int b) {
		return f2[a] < f2[b];
	});
	F2[all[0]] = 0;
	for (int i = 1; i < n; i++) {
		F2[all[i]] = F2[all[i - 1]] + !(f2[all[i]] == f2[all[i - 1]]);
	}

	sort(all.begin(), all.end(), [&](int a, int b) {
		if (f1[a] < f1[b]) {
			return true;
		}
		if (f1[b] < f1[a]) {
			return false;
		}
		return F2[b] < F2[a];
	});

	while (sz < n) {
		sz <<= 1;
	}
	tr.resize(2 * sz - 1, 0);

	ll ans = 0;

	for (int i : all) {
		ans += get(0, 0, sz, F2[i], n);
		add(F2[i], 1);
	}

	cout << ans << '\n';

    return 0;
}