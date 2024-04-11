#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 55;
int n, lazy[4 * maxn], vl[maxn];
string s;
pair<int, int> tree[4 * maxn];
inline void push(int v, int l, int r) {
	tree[v].first += lazy[v];
	tree[v].second += lazy[v];
	if (l != r) {
		lazy[v << 1] += lazy[v];
		lazy[v << 1 | 1] += lazy[v];
	}
	lazy[v] = 0;
}
void upd(int v, int l, int r, int ql, int qr, int add) {
	push(v, l, r);
	if (l > qr || r < ql)
		return;
	if (ql <= l && r <= qr) {
//		cout << l << " - " << r << "\n";
		lazy[v] = add;
		push(v, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	upd(v << 1, l, mid, ql, qr, add);
	upd(v << 1 | 1, mid + 1, r, ql, qr, add);
	tree[v].first = min(tree[v << 1].first, tree[v << 1 | 1].first);
	tree[v].second = max(tree[v << 1].second, tree[v << 1 | 1].second);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s;
	int p = 0;
	int bal = 0;
	for (auto i : s) {
		if (i == 'L') {
			if (p)
				p--;
		} else if (i == 'R') {
			p++;
		} else {
			int v = 0;
			if (i == ')')
				v--;
			else if (i == '(')
				v++;
//			cout << i << " "<< p << " " << n << " " << v-vl[p] << "\n";
			if (v - vl[p]) {
				bal += v - vl[p];
				upd(1, 0, n, p, n, v - vl[p]);
			}
			vl[p] = v;
//			cout << tree[1].first << " " << tree[1].second << "\n";
		}
//		cout << bal << " ";
		if(bal||tree[1].first<0) cout << "-1 ";
		else cout << tree[1].second << " ";
	}
}