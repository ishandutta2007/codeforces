#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

int count(ll x) {
	int res = 1;
	while (x /= 10) ++res;
	return res;
}

int mxdig(ll x) {
	ll mx = 0;
	for (; x; x /= 10) mx = max(mx, x % 10);
	return mx;
}

int upper_bound(ll x, ll n) {
	int res = 0;
	while (count(x) != n) {
		int mx = mxdig(x);
		if (mx <= 1) return 1e9;
		x *= mx;
		++res;
	}
	return res;
}

int lower_bound(ll x, ll n) {
	int res = 0;
	while (count(x) != n) x *= 9, ++res;
	return res;
}

vector<int> digs(ll x) {
	vector<int> res;
	while (x) {
		res.push_back(x % 10);
		x /= 10;
	}
	sort(res.rbegin(), res.rend());
	while (res.size() && res.back() <= 1) res.pop_back();
	reverse(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	return res;
}

void ProGamerMove() {
	ll n, x; cin >> n >> x;
	if (upper_bound(x, n) == 0) { cout << "0\n"; return; }
	if (mxdig(x) <= 1) { cout << "-1\n"; return; }
	int ub = upper_bound(x, n);
	queue<pair<int, ll>> q; q.push({0, x});
	while (q.size()) {
		auto [d, u] = q.front(); q.pop();
		cerr << d << ' ' << u << endl;
		if (d + lower_bound(u, n) >= ub) continue;
		ub = min(ub, d + upper_bound(u, n));
		if (upper_bound(u, n) == 0) continue;
		for (auto y : digs(u)) q.push({1 + d, u * y});
	}
	cout << ub << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
//	cin >> tc;
	while (tc--) ProGamerMove();
}