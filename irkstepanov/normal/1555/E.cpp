#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

vector<int> t;
vector<int> pro;
int n;

void push(int v) {
	pro[v * 2] += pro[v];
	pro[v * 2 + 1] += pro[v];
	t[v * 2] += pro[v];
	t[v * 2 + 1] += pro[v];
	pro[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val) {
	if (tl == l && tr == r) {
		t[v] += val;
		pro[v] += val;
		return;
	}
	push(v);
	int tm = (tl + tr) >> 1;
	if (l <= tm) {
		update(v * 2, tl, tm, l, min(r, tm), val);
	}
	if (r > tm) {
		update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
	}
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

struct datum {
	int l, r;
	int cost;
	bool operator<(const datum& other) const {
		return cost < other.cost;
	}
};

const int inf = 1e9;

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);


	int q, len;
	cin >> q >> len;
	vector<datum> d(q);
	for (int i = 0; i < q; ++i) {
		int l, r, c;
		cin >> l >> r >> c;
		--l, --r;
		--r;
		d[i] = {l, r, c};
	}
	sort(all(d));
	n = len - 1;
	t = vector<int>(4 * n, 0);
	pro	= vector<int>(4 * n, 0);
	int rg = -1;
	while (t[1] == 0) {
		++rg;
		update(1, 0, n - 1, d[rg].l, d[rg].r, 1);
	}
	int ans = d[rg].cost - d[0].cost;
	for (int lf = 1; lf < sz(d); ++lf) {
		update(1, 0, n - 1, d[lf - 1].l, d[lf - 1].r, -1);
		if (t[1] > 0) {
			ans = min(ans, d[rg].cost - d[lf].cost);
			continue;
		}
		while (t[1] == 0 && rg + 1 < sz(d)) {
			++rg;
			update(1, 0, n - 1, d[rg].l, d[rg].r, 1);
		}
		if (t[1] == 0) {
			break;
		}
	}
	cout << ans << "\n";

}