#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, L = 18;

int n, q, a[N];
int64_t pre[N];

template<class T, const T& merge(const T&, const T&)> struct sparse_table {
	vector<T> st[L];
	sparse_table () {}
	sparse_table (const vector<T> &a) {
		st[0] = a; int n = a.size(); __build__(n);
	}
	sparse_table (int n, T * a) {
		st[0] = vector<T> (a, a + n); __build__(n);
	}
	sparse_table (T * __first, T * __last) {
		st[0] = vector<T> (__first, __last);
		int n = __last - __first; __build__(n);
	}

	inline void __build__(int n) {
		for (int j = 1; 1 << j <= n; j++) {
			st[j].resize(n - (1 << j) + 1);
			for (int i = 0; i + (1 << j) <= n; i++)
				st[j][i] = merge(st[j - 1][i], st[j - 1][i + (1 << j - 1)]);
		}
	}

	inline T query(int l, int r) {
		int j = __lg(r - l + 1);
		// return merge(st[j][l], st[j][r - (1 << j) + 1]); // 0 base
		return merge(st[j][l - 1], st[j][r - (1 << j)]); // 1 base
	}
};

signed main() {
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	cin >> n >> q;
	for (int i = 1, x; i <= n; i++) cin >> x, a[i] += x;
	for (int i = 1, x; i <= n; i++) cin >> x, a[i] -= x;
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];

	sparse_table<int64_t, min<int64_t>> stmin(pre + 1, pre + n + 1);
	sparse_table<int64_t, max<int64_t>> stmax(pre + 1, pre + n + 1);

	for (int l, r; q--; ) {
		cin >> l >> r;
		cout << (pre[r] != pre[l - 1] || stmax.query(l, r) > pre[l - 1] 
			? -1 : pre[l - 1] - stmin.query(l, r)) << '\n';
	}
}