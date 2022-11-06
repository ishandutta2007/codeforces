#include<bits/stdc++.h>
#define inf 1000000000000000000ll
#define maxn 500000
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;

void update(vector<pair<ll, int>>& t, int now, int l, int r, int pos, ll val) {
	if(l == r) {
		t[now].first = val;
		return;
	}
	int mid = (l + r) / 2;
	if(mid >= pos) {
		update(t, now * 2, l, mid, pos, val);
	} else {
		update(t, now * 2 + 1, mid + 1, r, pos, val);
	}
	t[now] = max(t[now * 2], t[now * 2 + 1]);
}

pair<ll, int> get(vector<pair<ll, int>>& t, int now, int l, int r, int l1, int r1) {
	if(l1 > r || l > r1 || l1 > r1) return {-inf, -1};
	if(l1 <= l && r <= r1) return t[now];
	int mid = (l + r) / 2;
	return max(get(t, now * 2, l, mid, l1, r1), get(t, now * 2 + 1, mid + 1, r, l1, r1));
}

void build(vector<pair<ll, int>>& t, int now, int l, int r) {
	if(l == r) {
		t[now] = {-inf, l};
		return;
	}
	int mid = (l + r) / 2;
	build(t, now * 2, l, mid);
	build(t, now * 2 + 1, mid + 1, r);
}

struct Node {
	ll x;
	ll y;
	ll ans;
};

Node t[maxn * 4 + 7];

void build(vl& x, vl& y, int now, int l, int r) {
	if(l == r) {
		t[now].x = x[l];
		t[now].y = y[l];
		t[now].ans = x[l] + y[l];
		return;
	}
	int mid = (l + r) / 2;
	build(x, y, now * 2, l, mid);
	build(x, y, now * 2 + 1, mid + 1, r);
	t[now].x = max(t[now * 2].x, t[now * 2 + 1].x);
	t[now].y = max(t[now * 2].y, t[now * 2 + 1].y);
	t[now].ans = max(max(t[now * 2].ans, t[now * 2 + 1].ans), t[now * 2].x + t[now * 2 + 1].y);
}

Node get(int now, int l, int r, int l1, int r1) {
	if(l > r1 || l1 > r) return Node(-inf, -inf, -inf);
	if(l1 <= l && r <= r1) return t[now];
	int mid = (l + r) / 2;
	auto p1 = get(now * 2, l, mid, l1, r1);
	auto p2 = get(now * 2 + 1, mid + 1, r, l1, r1);
	Node p;
	p.x = max(p1.x, p2.x);
	p.y = max(p1.y, p2.y);
	p.ans = max(max(p1.ans, p2.ans), p1.x + p2.y);
	return p;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, q;
	cin >> n >> q;
	vvi a(3, vi(n));
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	vector<vl> pref(3, vl(n + 1, 0));
	for(int i = 0; i < 3; i++) {
		for(int j = 1; j <= n; j++) {
			pref[i][j] = pref[i][j - 1] + a[i][j - 1];
		}
	}
	vl x(n), y(n);
	for(int i = 0; i < n; i++) {
		x[i] = pref[0][i + 1] - pref[1][i];
		y[i] = pref[2][n] - pref[2][i] + pref[1][i + 1];
	}
	vector<pair<ll, int>> tx(4 * n + 7);
	build(tx, 1, 0, n - 1);
	for(int i = 0; i < n; i++) {
		update(tx, 1, 0, n - 1, i, x[i]);
	}
	vector<vector<pair<int, int>>> otr(n);
	for(int i = 0; i < q; i++) {
		int l, r, c;
		cin >> l >> r >> c;
		--l;
		--r;
		otr[r].push_back({l, c});
	}
	vl dp(n);
	vector<pair<ll, int>>  tdp(4 * n + 7);
	build(tdp, 1, 0, n - 1);
	vector<vector<pair<ll, int>>> here(n);
	for(int i = 0; i < n; i++) {
		dp[i] = -inf;
		for(const auto& el : otr[i]) {
			int l = el.first;
			int c = el.second;
			dp[i] = max(dp[i], get(tx, 1, 0, n - 1, l, i).first - c);
			dp[i] = max(dp[i], get(tdp, 1, 0, n - 1, max(0, l - 1), i - 1).first - c);
		}
		update(tdp, 1, 0, n - 1, i, dp[i]);
	}
	for(int i = 0; i < n; i++) {
		if(i != 0) {
			x[i] = max(x[i], dp[i - 1]);
		}
		//cout << x[i] << ' ' << y[i] << endl;
	}
	build(x, y, 1, 0, n - 1);
	ll ans = -inf;
	for(int i = 0; i < n; i++) {
		for(const auto& el : otr[i]) {
			ans = max(ans, get(1, 0, n - 1, el.first, i).ans - el.second);
		}
	}
	cout << ans;
}