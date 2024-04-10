#include<bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5, M = 1e6 + 5;

int n, m, a[N], d[M], rnk[M], tag[N << 2];
int64_t st[N << 2];

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

void build(int id = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		tag[id] = rnk[a[tl]], st[id] = a[tl];
	} else {
		build(left), build(right);
		st[id] = st[id << 1] + st[id << 1 | 1];
		tag[id] = max(tag[id << 1], tag[id << 1 | 1]);
	}
}

void update(int l, int r, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r || !tag[id]) return ;
	if (tl == tr) {
		tag[id] --, st[id] = d[st[id]];
		return ;
	}
	update(l, r, left), update(l, r, right);
	st[id] = st[id << 1] + st[id << 1 | 1];
	tag[id] = max(tag[id << 1], tag[id << 1 | 1]);
}

int64_t query(int l, int r, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return 0;
	if (l <= tl && tr <= r) return st[id];
	return query(l, r, left) + query(l, r, right);
}

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

	for (int i = 1; i < M; i++)
		for (int j = i; j < M; j += i) d[j] ++;

	for (int i = 3; i < M; i++)
		rnk[i] = rnk[d[i]] + 1;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build();

	for (int t, l, r; m --; ) {
		cin >> t >> l >> r;
		if (t == 1) {
			update(l, r);
		} else {
			cout << query(l, r) << '\n';
		}
	}
}