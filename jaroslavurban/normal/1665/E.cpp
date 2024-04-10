#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct Tree {
	int n, ln;
	vector<vector<int>> t;
	Tree(vector<int> a) : n(a.size()), ln(1 << int(log2(2 * n - 1))), t(2 * ln) {
		for (int i = 0; i < a.size(); ++i) t[i + ln].push_back(a[i]);
		for (int i = ln - 1; i >= 1; --i) {
			t[i].resize(t[2 * i].size() + t[2 * i + 1].size());
			merge(t[2 * i].begin(), t[2 * i].end(), t[2 * i + 1].begin(), t[2 * i + 1].end(), t[i].begin());
			if (t[i].size() > 33) t[i].erase(t[i].begin() + 34, t[i].end());
		}
	}
	int query(int l, int r) {
		vector<int> res;
		query(0, ln, l, r, 1, res);
		sort(res.begin(), res.end());
		int rs = INT_MAX;
		for (int i = 0; i < min((int)res.size(), 33); ++i)
			for (int j = i + 1; j < min((int)res.size(), 33); ++j)
				rs = min(rs, res[i] | res[j]);
		return rs;
	}
	void query(int l, int r, int ql, int qr, int id, vector<int>& res) {
		if (qr <= l || r <= ql) return;
		if (ql <= l && r <= qr) { res.insert(res.end(), t[id].begin(), t[id].end()); return; }
		int m = (l + r) / 2;
		query(l, m, ql, qr, 2 * id, res);
		query(m, r, ql, qr, 2 * id + 1, res);
	}
};


void ProGamerMove() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	Tree t(a);
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r, --l;
		cout << t.query(l, r) << "\n";
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}