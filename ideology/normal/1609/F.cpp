#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

// const int P = 998244353;

// int norm(int x) { return x >= P ? x - P : x; }
// void add(int& x, int y) { if ((x += y) >= P) x -= P; }
// void sub(int& x, int y) { if ((x -= y) < 0) x += P; }

// int mpow(int x, int k) {
// 	if (k == 0) return 1;
// 	int ret = mpow(x * (ull)x % P, k >> 1);
// 	if (k & 1) ret = x * (ull)ret % P;
// 	return ret;
// }

int popcnt(ull x) { return __builtin_popcountll(x); }

const int _ = 1000010;

ull a[_];
int s1[_], s2[_];

using pii = pair<int, int>;

pii val[1 << 21];
int tag[1 << 21];

pii operator+(const pii& lhs, const pii& rhs) {
	pii ret(max(lhs.first, rhs.first), 0);
	if (ret.first == lhs.first) ret.second += lhs.second;
	if (ret.first == rhs.first) ret.second += rhs.second;
	return ret;
}

void upd(int o) { val[o] = val[o << 1] + val[o << 1 | 1]; val[o].first += tag[o]; }

void build(int o, int l, int r) {
	if (l == r) { val[o] = make_pair(0, 1); return; }
	int mid = (l + r) >> 1;
	build(o << 1, l, mid); build(o << 1 | 1, mid + 1, r);
	upd(o);
}
void chg(int o, int l, int r, int ql, int qr, int x) {
	if (l == ql && r == qr) { tag[o] += x; val[o].first += x; return; }
	int mid = (l + r) >> 1;
	if (qr <= mid) chg(o << 1, l, mid, ql, qr, x);
	else if (ql > mid) chg(o << 1 | 1, mid + 1, r, ql, qr, x);
	else {
		chg(o << 1, l, mid, ql, mid, x);
		chg(o << 1 | 1, mid + 1, r, mid + 1, qr, x);
	}
	upd(o);
}

vector<tuple<int, int, int>> op[100];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N; cin >> N;
	for (int i = 1; i <= N; ++i) cin >> a[i];
	int z1 = 0, z2 = 0;
	for (int i = 1; i <= N; ++i) {
		while (z1 && a[s1[z1]] < a[i]) {
			op[popcnt(a[s1[z1]])].emplace_back(-(s1[z1 - 1] + 1), -s1[z1], i);
			--z1;
		}
		op[popcnt(a[i])].emplace_back(s1[z1] + 1, i, i);
		s1[++z1] = i;

		while (z2 && a[s2[z2]] > a[i]) {
			op[popcnt(a[s2[z2]])].emplace_back(-(s2[z2 - 1] + 1), -s2[z2], i);
			--z2;
		}
		op[popcnt(a[i])].emplace_back(s2[z2] + 1, i, i);
		s2[++z2] = i;
	}
	build(1, 1, N);
	ull ans = 0;
	for (int i = 0; i <= 60; ++i) {
		// cerr << "FOR " << i << '\n';
		for (int j = 0; j != op[i].size(); ++j) {
			int l, r, t; tie(l, r, t) = op[i][j];
			// cerr << l << ' ' << r << ' ' << t << '\n';
			if (l > 0) chg(1, 1, N, l, r, 1);
			else chg(1, 1, N, -l, -r, -1);
			int tot = (j + 1 == op[i].size()) ? N + 1 : get<2>(op[i][j + 1]);
			if (val[1].first == 2) {
				// cerr << "POS " << t << " to " << tot << " contr " << val[1].second << '\n';
				ans += ull(tot - t) * val[1].second;
			}
		}
		for (int j = 0; j != op[i].size(); ++j) {
			int l, r, t; tie(l, r, t) = op[i][j];
			if (l > 0) chg(1, 1, N, l, r, -1);
			else chg(1, 1, N, -l, -r, 1);
		}
		// cerr << val[1].first << ", " << val[1].second << '\n';
	}
	cout << ans << '\n';

	return 0;
}