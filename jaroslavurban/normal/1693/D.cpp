#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

const int LN = log2(200200);
const int inf = INT_MAX;

struct ST {
	int n;
	vector<int> t;
	ST(int n_) : n(1 << int(log2(2 * n_ - 1))), t(2 * n, inf) {}
	void update(int i, int x) {
		for (t[i += n] = x; i /= 2;) t[i] = min(t[2 * i], t[2 * i + 1]);
	}
	int query(int l, int r) {
		int res = inf;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) res = min(res, t[l++]);
			if (r & 1) res = min(res, t[--r]);
		}
		return res;
	}
};

void ProGamerMove() {
	int n; cin >> n;
	vector<int> p(n);
	for (int& v : p) cin >> v, --v;
	vector<int> a[2], nxt[2][LN + 1];
	a[0].push_back(-inf);
	a[1].push_back(inf);
	for (int i = 0; i <= LN; ++i) {
		nxt[0][i].assign(n, inf);
		nxt[1][i].assign(n, inf);
	}
	ST st(n);
	for (int i = n - 1; i >= 0; --i) {
		nxt[0][0][i] = st.query(p[i], n);
		nxt[1][0][i] = st.query(0, p[i]);
		st.update(p[i], i);
		for (int t = 0; t < 2; ++t)
			for (int j = 1; j <= LN; ++j)
				nxt[t][j][i] = nxt[t][j - 1][i] == inf ? inf : nxt[t][j - 1][nxt[t][j - 1][i]];
	}
	ll res = 0;
	for (int j = 0, i = 0; i < n; ++i) {
		if (i && p[i - 1] == a[0].back()) a[0] = {INT_MIN};
		if (i && p[i - 1] == a[1].back()) a[1] = {INT_MAX};
		for (; j < n && p[j] > a[0].back() && p[j] < a[1].back(); ++j)
			a[j + 1 == n || p[j] > p[j + 1]].push_back(p[j]);
		if (j != n) {
			bool dec = p[j] < a[1].back();
			int mx = j;
			for (int diff = LN; diff >= 0; --diff) if (mx + (1 << diff) < n) {
				int covered = 0, cmx = mx + (1 << diff);
				int x = j, y = nxt[!dec][0][j];
				if (y != inf && (p[y] < a[!dec].back()) == dec) y = inf;
				for (int diff2 = LN; diff2 >= 0; --diff2) if (nxt[dec][diff2][x] <= cmx) {
					covered += 1 << diff2;
					x = nxt[dec][diff2][x];
				}
				if (y <= cmx) {
					++covered;
					for (int diff2 = LN; diff2 >= 0; --diff2) if (nxt[!dec][diff2][y] <= cmx) {
						covered += 1 << diff2;
						y = nxt[!dec][diff2][y];
					}
				}
				if (covered == cmx - j) mx = cmx;
			}
			res += mx + 1 - i;
		} else res += n - i;
	}
	cout << res << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
//	cin >> tc;
	while (tc--) ProGamerMove();
}