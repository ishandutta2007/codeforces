#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<pair<int, int>, int> r1, r2;

map<ll, vector<int>> pov1, pov2;

ll ar(pair<int, int> p) {
	return p.first * 1ll * p.second;
}

void upd(vector<int>& a, const vector<int>& b) {
	if (a.size() == 0 || a[0] > b[0]) {
		a = b;
	}
}

void napravi(map<pair<int, int>, int>& r, map<ll, vector<int>>& pov) {
	for (auto p : r) {
		upd(pov[ar(p.first)], {p.second, p.first.first, p.first.second});
	}
}

template<class T>
void dfs(int x, int y, int t, T& r) {
	if (r.count({x, y}) && r[{x, y}] <= t) return;
	r[{x, y}] = t;
	if (x % 2 == 0) dfs(x/2  , y    , t+1, r);
	if (x % 3 == 0) dfs(2*x/3, y    , t+1, r);
	if (y % 2 == 0) dfs(x    , y/2  , t+1, r);
	if (y % 3 == 0) dfs(x    , 2*y/3, t+1, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	dfs(a, b, 0, r1);
	dfs(c, d, 0, r2);
	ll sol = 123123123;
	pair<int, int> o1, o2;

	napravi(r1, pov1);
	napravi(r2, pov2);

	for (auto p : pov1) {
		if (pov2.count(p.first)) {
			int tot = p.second[0] + pov2[p.first][0];
			if (tot < sol) {
				sol = tot;
				o1 = {p.second[1], p.second[2]};
				o2 = {pov2[p.first][1], pov2[p.first][2]};
			}
		}
	}

	if (sol == 123123123)
		sol = -1;
	cout << sol << '\n';
	if (sol != -1) {
		cout << o1.first << ' ' << o1.second << '\n';
		cout << o2.first << ' ' << o2.second << '\n';
	}
}