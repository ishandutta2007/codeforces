



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
#include <cstring>

using namespace std;

//#define FAST_ALLOCATOR_MEMORY 1e8
#undef LOCAL
//#include "optimization.h"

const int INF = 1e9;
const int MX = 2e6 + 7;

int h[MX], h2[MX], h3[MX];
long long arrp[MX], arrp2[MX], arrp3[MX];
const long long p = 239;
const int mod = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int mod3 = 1e9 + 33;
string s;
int n;
vector<int> b;

int t[8 * MX];

void build(int v, int tl, int tr) {
	if (tl == tr)
		t[v] = b[tl];
	else {
		int tm = (tl + tr) >> 1;
		build(v << 1, tl, tm);
		build((v << 1) | 1, tm + 1, tr);
		t[v] = min(t[v << 1], t[(v << 1) | 1]);
	}
}

int get(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return INF;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) >> 1;
	return min(get(v << 1, tl, tm, l, min(r, tm)), get((v << 1) | 1, tm + 1, tr, max(tm + 1, l), r));
}


int push(long long a) {
	return ((a % mod) + mod) % mod;
}

int push2(long long a) {
	return ((a % mod2) + mod2) % mod2;
}
int push3(long long a) {
	return ((a % mod3) + mod3) % mod3;
}

int get_h(int l, int r) {
	return push(h[r + 1] - h[l] * arrp[r - l + 1]);
}

int get_h2(int l, int r) {
	return push2(h2[r + 1] - h2[l] * arrp2[r - l + 1]);
}
int get_h3(int l, int r) {
	return push3(h3[r + 1] - h3[l] * arrp3[r - l + 1]);
}


bool same(int l1, int r1, int l2, int r2) {
	if (get_h(l1, r1) != get_h(l2, r2))
		return 0;
	if (get_h2(l1, r1) != get_h2(l2, r2))
		return 0;
	if (get_h3(l1, r1) != get_h3(l2, r2))
		return 0;
	return 1;
}

bool smaller(int st, int ans) {
	int l = -1, r = n;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (same(st, st + m, ans, ans + m))
			l = m;
		else
			r = m;
	}
	if (l != n - 1 && (s[st + l + 1] < s[ans + l + 1]))
		return 1;
	return 0;
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> s;
	n = (int)s.length();
	s += s;

	b.resize(2 * n + 1);
	b[0] = 0;
	for (int i = 1; i <= 2 * n; i++) {
		b[i] = b[i - 1];
		if (s[i - 1] == '(')
			b[i]++;
		else
			b[i]--;
	}
	vector<bool> good(n);
	build(1, 0, 2 * n);
	int add = max(0, -b[n]);
	
	for (int i = 0; i < n; i++) {
		int val = get(1, 0, 2 * n, i, i + n);
		if (val - b[i] + add >= 0)
			good[i] = 1;
	}

	

	h[0] = 0;
	for (int i = 0; i < 2 * n; i++)
		h[i + 1] = (h[i] * p + s[i]) % mod;
	arrp[0] = 1;
	for (int i = 1; i < MX; i++) {
		arrp[i] = (arrp[i - 1] * p) % mod;
	}


	h2[0] = 0;
	for (int i = 0; i < 2 * n; i++)
		h2[i + 1] = (h2[i] * p + s[i]) % mod2;
	arrp2[0] = 1;
	for (int i = 1; i < MX; i++) {
		arrp2[i] = (arrp2[i - 1] * p) % mod2;
	}


	h3[0] = 0;
	for (int i = 0; i < 2 * n; i++)
		h3[i + 1] = (h3[i] * p + s[i]) % mod3;
	arrp3[0] = 1;
	for (int i = 1; i < MX; i++) {
		arrp3[i] = (arrp3[i - 1] * p) % mod3;
	}

	int ans = -1;
	for (int i = 0; i < n; i++) {
		if (good[i]) {
			if (ans == -1 || smaller(i, ans))
				ans = i;
		}
	}
	
	for (int i = 0; i < -b[n]; i++)
		cout << '(';

	for (int i = 0; i < n; i++)
		cout << s[ans + i];

	for (int i = 0; i < b[n]; i++)
		cout << ')';
	
	return 0;
}