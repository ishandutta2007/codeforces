#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct SEG {
	int sz;
	vector <int> tag;

	void init(int n) {
		for (sz = 1; sz < n; sz <<= 1);
		tag.resize(sz << 1);
		rep(i, sz << 1) tag[i] = 0;
	}

	void upd(int l, int r, int v) {
		for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
			if (l & 1) tag[l] = max(tag[l], v), ++ l;
			if (r & 1) -- r, tag[r] = max(tag[r], v);
		}
	}

	int qry(int x) {
		int ans = 0;
		for (x += sz; x; x >>= 1) {
			ans = max(ans, tag[x]);
		}
		return ans;
	}
} sx, sy;

int n, q;
vector <pair <pair <int, int>, char> > qry;
vector <int> vx, vy;
set <pair <int, int> > vis;

int main() {
	scanf("%d %d", &n, &q);
	rep(i, q) {
		int x, y;
		char ch[5];
		scanf("%d %d %s", &x, &y, ch);
		vx.pb(x); vy.pb(y);
		qry.pb(mp(mp(x, y), ch[0]));
	}
	vx.pb(0); vy.pb(0);
	sort(vx.begin(), vx.end());
	vx.erase(unique(vx.begin(), vx.end()), vx.end());
	sort(vy.begin(), vy.end());
	vy.erase(unique(vy.begin(), vy.end()), vy.end());
	sx.init(vx.size());
	sy.init(vy.size());
	rep(i, q) {
		int x = lower_bound(vx.begin(), vx.end(), qry[i].first.first) - vx.begin();
		int y = lower_bound(vy.begin(), vy.end(), qry[i].first.second) - vy.begin();
		char tp = qry[i].second;
		if (vis.find(mp(x, y)) != vis.end()) {
			printf("0\n");
			continue;
		}
		vis.insert(mp(x, y));
		if (tp == 'U') {
			int w = sx.qry(x);
			sy.upd(w + 1, y + 1, x);
			printf("%d\n", vy[y] - vy[w]);
		} else {
			int w = sy.qry(y);
			sx.upd(w + 1, x + 1, y);
			printf("%d\n", vx[x] - vx[w]);
		}
	}
	return 0;
}