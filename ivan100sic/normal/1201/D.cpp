#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<int, vector<int>> e;
int n, m, k, q;
bool safe[200005];
int sl[200005], sr[200005];

const ll inf = 1e18;

struct stanje {
	int x, y;
	ll cost;
};

ll mn(vector<stanje> vs) {
	ll z = inf;
	for (auto s : vs)
		z = min(z, s.cost);
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k >> q;
	for (int i=0; i<k; i++) {
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
	}
	for (int i=0; i<q; i++) {
		int x;
		cin >> x;
		safe[x] = true;
	}

	memset(sl, 255, sizeof(sl));
	memset(sr, 255, sizeof(sr));
	for (int i=1; i<=m; i++) {
		sl[i] = sl[i-1];
		if (safe[i])
			sl[i] = i;
	}
	for (int i=m; i>=1; i--) {
		sr[i] = sr[i+1];
		if (safe[i])
			sr[i] = i;
	}

	vector<stanje> st;

	if (e.count(1)) {
		int y = *max_element(e[1].begin(), e[1].end());
		st.push_back({1, y, y-1});
		e.erase(1);
	} else {
		st.push_back({1, 1, 0});
	}

	for (auto [x, vy] : e) {
		int yl = *min_element(vy.begin(), vy.end());
		int yr = *max_element(vy.begin(), vy.end());
		
		stanje tl = {x, yl, inf}, tr = {x, yr, inf};

		for (auto [xx, yy, vv] : st) {
			if (sl[yy] != -1) {
				ll cost = vv + yy - sl[yy];
				cost += x - xx;
				cost += yr - yl;
				tl.cost = min(tl.cost, cost + abs(sl[yy] - yr));
				tr.cost = min(tr.cost, cost + abs(sl[yy] - yl));
			}

			if (sr[yy] != -1) {
				ll cost = vv + sr[yy] - yy;
				cost += x - xx;
				cost += yr - yl;
				tl.cost = min(tl.cost, cost + abs(sr[yy] - yr));
				tr.cost = min(tr.cost, cost + abs(sr[yy] - yl));
			}
		}

		st = {tl, tr};
	}

	cout << mn(st) << '\n';
}