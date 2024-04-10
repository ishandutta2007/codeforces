#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int bit[26][N], q;
char s[N];

inline void upd(int c, int p, int v) {
	for (; p < N; p += p & -p)
		bit[c][p] += v;
}

inline int query(int c, int p) {
	int r = 0;
	for (; p > 0; p -= p & -p)
		r += bit[c][p];
	return r;
}

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

	cin >> (s + 1) >> q;
	for (int i = 1; i <= strlen(s + 1); i++)
		upd(s[i] - 'a', i, +1);
	for (int t, p, l, r; q --; ) {
		cin >> t;
		if (t == 1) {
			cin >> p;
			upd(s[p] - 'a', p, -1);
			cin >> s[p];
			upd(s[p] - 'a', p, +1);
		} else {
			cin >> l >> r;
			int res = 0;
			for (int i = 0; i < 26; i++)
				if (query(i, l - 1) ^ query(i, r)) ++ res;
			cout << res << '\n';
		}
	}
}