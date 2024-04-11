#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long double K;
constexpr int INF = 0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define X first
#define Y second

pair<ll, ll> rot(pair<ll, ll> pt) {
	return {pt.X - pt.Y, pt.X + pt.Y};
}

bool cmp(const pair<pair<ll, ll>, int> &a, const pair<pair<ll, ll>, int> &b) {
	return make_pair(a.X.X, make_pair(a.Y, a.X.Y)) < make_pair(b.X.X, make_pair(b.Y, b.X.Y));
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<ii> pole(n);
	TRAV(x, pole) cin >> x.X >> x.Y;
	vector<pair<int, ii>> eve;
	TRAV(x, pole) {
		eve.PB({x.X - x.Y, {1, -x.X + x.Y}});
		eve.PB({x.X + 1, {-1, x.X - x.Y}});
		eve.PB({x.X + 1, {-1, x.X + x.Y}});
		eve.PB({x.X + x.Y + 1, {1, -x.X - x.Y}});
		eve.PB({x.X + x.Y, {0, 0}});
		eve.PB({x.X, {0, 0}});
	}
	sort(eve.begin(), eve.end());
	vector<pair<ll, ll>> pts;
	pair<ll, ll> fun;
	FOR(i, 0, SZ(eve)) {
		int j = i;
		while(j < SZ(eve) && eve[i].X == eve[j].X) j++;
		FOR(k, i, j) fun = {fun.X + eve[k].Y.X, fun.Y + eve[k].Y.Y};
		pts.PB({eve[i].X, fun.X * eve[i].X + fun.Y});
		i = j - 1;
	}
	vector<pair<ll, ll>> prefPts = pts, sufPts = pts;
	FOR(i, 1, SZ(prefPts)) prefPts[i].Y = max(prefPts[i].Y, prefPts[i - 1].Y);
	for(int i = SZ(sufPts) - 2; i >= 0; i--) sufPts[i].Y = max(sufPts[i].Y, sufPts[i + 1].Y);
	vi ans(n);
	vector<pair<pair<ll, ll>, int>> ev;
	FOR(i, 0, n) {
		ll prefMax = (*lower_bound(prefPts.begin(), prefPts.end(), make_pair(1ll * pole[i].X - pole[i].Y, -1ll))).Y;
		ll sufMax = (*lower_bound(sufPts.begin(), sufPts.end(), make_pair(1ll * pole[i].X + pole[i].Y, -1ll))).Y;
		if(max(prefMax, sufMax) > m) ans[i] = 1;
		else ev.PB({rot({pole[i].X - pole[i].Y, m}), i}), ev.PB({rot({pole[i].X + pole[i].Y, m}), i});
	}
	// TRAV(x, pts) cout << x.X << ' ' << x.Y << '\n';
	TRAV(x, pts) ev.PB({rot(x), INF});
	sort(ev.begin(), ev.end(), cmp);
	set<ll> wsp;
	TRAV(x, ev) {
		if(x.Y == INF) wsp.insert(x.X.Y);
		else if(wsp.upper_bound(x.X.Y) != wsp.end()) {
			ans[x.Y] = 1;
			// cout << x.Y << '\n';
		}
	}
	TRAV(x, ans) cout << (x ^ 1);
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	FOR(te, 0, tt) {
		// cout << "Case #" << te + 1 << ": ";
		solve();
	}
    // solve();
	return 0;
}