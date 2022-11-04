#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll inf = 1e18;

struct L {
	int a, b, c, d, h;
	ll health = -inf;
};

void ProGamerMove() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> x(n);
	for (ll& v : x) cin >> v;
	vector<L> ladders(k);
	vector<vector<int>> f(n);
	for (int i = 0; i < k; ++i) {
		auto &[a, b, c, d, h, health] = ladders[i];
		cin >> a >> b >> c >> d >> h;
		--a, --b, --c, --d;
		f[a].push_back(i);
		f[c].push_back(i);
	}
	ladders.push_back({n - 1, m - 1, -1, -1, 0, -inf});
	ladders.push_back({-1, -1, 0, 0, 0, 0});
	f[n - 1].push_back(k);
	f[0].push_back(k + 1);
	for (int row = 0; row < n; ++row) {
		auto fx = [&](int id) { return ladders[id].a == row ? ladders[id].b : ladders[id].d; };
		sort(f[row].begin(), f[row].end(), [&](int x, int y) {
			return fx(x) < fx(y);
		});
		priority_queue<pair<ll, int>> q;
		for (int pos = 0; pos < f[row].size(); ++pos) {
			int id = f[row][pos];
			if (ladders[id].health != -inf) {
				q.push({ladders[id].health + ladders[id].h, pos});
				ladders[id].health = -inf;
			}
		}
//		cerr << row << " " << q.size() << endl;
		while (q.size()) {
			auto [chealth, pos] = q.top(); q.pop();
//			cerr << row << " " << chealth << " " << pos << endl;
			int id = f[row][pos];
			if (ladders[id].health >= chealth) continue;
			ladders[id].health = chealth;
			if (pos > 0) q.push({chealth - x[row] * abs(fx(id) - fx(f[row][pos - 1])), pos - 1});
			if (pos < (int)f[row].size() - 1) q.push({chealth - x[row] * abs(fx(id) - fx(f[row][pos + 1])), pos + 1});
		}
	}
	if (ladders[k].health == -inf) {
		cout << "NO ESCAPE\n";
		return;
	}
	else cout << -ladders[k].health << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}