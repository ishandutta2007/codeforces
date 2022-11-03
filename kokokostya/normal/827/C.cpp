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

//#define LOCAL
const int MX = 10;
vector<int> t[4][MX + 1][MX];
map<char, int> b = { {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3} };
int n;

void update(int pos, int mod, int ost, int val, int ch) {
	int v = 1;
	int tl = 0, tr = ((n - 1) / mod);
	pos = (pos - ost) / mod;
	while (tl != tr) {
		int tm = (tl + tr) >> 1;
		if (pos <= tm) {
			tr = tm;
			v <<= 1;
		}
		else {
			tl = tm + 1;
			v = (v << 1) | 1;
		}
	}
	t[ch][mod][ost][v] += val;
	while (v) {
		v >>= 1;
		t[ch][mod][ost][v] += val;
	}
	return;
}

int get(int v, int tl, int tr, int l, int r, int mod, int ost, int ch) {
	if (l > r)
		return 0;
	if (tl == l && r == tr)
		return t[ch][mod][ost][v];
	int tm = (tl + tr) >> 1;
	return get(v << 1, tl, tm, l, min(r, tm), mod, ost, ch) + get((v << 1) | 1, tm + 1, tr, max(tm + 1, l), r, mod, ost, ch);
}

int main() {
	ios_base::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;
	cin >> s;
	n = int(s.length());
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= MX; j++) {
			for (int q = 0; q < MX; q++) {
				t[i][j][q].resize(4 * ((n / j) + 1));
			}
		}
	}
	for (int mod = 1; mod <= MX; mod++) {
		for (int i = 0; i < s.length(); i++) {
			update(i, mod, i % mod, 1, b[s[i]]);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int pos;
			char c;
			cin >> pos >> c;
			pos--;
			for (int mod = 1; mod <= MX; mod++) {
				update(pos, mod, pos % mod, -1, b[s[pos]]);
				update(pos, mod, pos % mod, 1, b[c]);
			}
			s[pos] = c;
		}
		else {
			int l, r;
			string t;
			cin >> l >> r >> t;
			l--; r--;
			int res = 0;
			for (int i = 0; i < t.length(); i++) {
				int mod = int(t.length());
				int ost = (i + l) % mod;
				res += get(1, 0, (n - 1) / mod, (l + mod - ost - 1) / mod, (r - ost + mod) / mod - 1, mod, ost, b[t[i]]);
			}
			cout << res << '\n';
		}
	}

	return 0;
}