#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>

using namespace std;

typedef long long ll;

ll INF = 1e18;
ll INFi = 2e9;
long double eps = 1e-6;
ll mod = 1e9 + 7;

struct Tree_mi {
	vector<int> tree;
	vector<int> ar;

	Tree_mi() {}
	Tree_mi(vector<int> _ar) {
		ar = _ar;
		tree.resize(4 * ar.size());
		build(0, 0, ar.size());
	}

	void build(int pos, int l, int r) {
		if (r - l == 1) {
			tree[pos] = ar[l];
			return;
		}
		build(2 * pos + 1, l, (l + r) / 2);
		build(2 * pos + 2, (l + r) / 2, r);
		tree[pos] = min(tree[2 * pos + 1], tree[2 * pos + 2]);
	}

	int get_min(int pos, int l, int r, int vl, int vr) {
		if (vl >= r || l >= vr) return INFi;
		if (vl <= l && r <= vr) {
			return tree[pos];
		}
		return min(get_min(2 * pos + 1, l, (l + r) / 2, vl, vr), get_min(2 * pos + 2, (l + r) / 2, r, vl, vr));
	}
};


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);

	int n, m;
	cin >> n >> m;
	vector<string> fd(n);
	for (string& st : fd) cin >> st;
	vector<int> lf(n);
	vector<int> bk(n);
	ll ans = 0;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (j == 0 || fd[i][j] != fd[i][j - 1]) lf[i] = 1;
			else lf[i] += 1;
			if (i == 0 || fd[i][j] != fd[i - 1][j]) bk[i] = 1;
			else bk[i] = bk[i - 1] + 1;
		}
		//cout << j << endl;
		Tree_mi tree = Tree_mi(lf);
		for (int i = 0; i < n; i++) {
			//cout << i << " " << bk[i] << " flex\n";
			if (bk[i] == i + 1) continue;
			int i2 = i - bk[i];
			//cout << i2 << " " << bk[i2] << endl;
			if (bk[i2] == i2 + 1) continue;
			int i3 = i2 - bk[i2];
			//cout << i3 << " " << bk[i3] << endl;
			if (bk[i] != bk[i2]) continue;
			if (bk[i3] < bk[i]) continue;
			int r = i;
			int l = i - 3 * bk[i] + 1;
			ll f = tree.get_min(0, 0, n, l, r + 1);
			ans += f;
		}
		//cout << ans << " ans\n";
	}
	cout << ans << endl;
	return 0;
}