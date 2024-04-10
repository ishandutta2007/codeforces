#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const ll inf = 1e18;

struct data {
	int lf, rg;
	ll cost;
	bool operator<(const data& other) const {
		return lf < other.lf;
	}
};

struct query {
	int rem;
	ll cost;
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	int n, x;
	cin >> n >> x;

	vector<data> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].lf >> v[i].rg >> v[i].cost;
	}

	sort(all(v));
	vector<vector<query> > q(n);
	for (int i = 0; i < n; ++i) {
		if (v[i].rg - v[i].lf + 1 >= x) {
			continue;
		}
		if (v[n - 1].lf <= v[i].rg) {
			continue;
		}
		int lf = -1, rg = n - 1;
		while (rg - lf > 1) {
			int md = (lf + rg) >> 1;
			if (v[md].lf > v[i].rg) {
				rg = md;
			} else {
				lf = md;
			}
		}
		q[rg].pb({x - (v[i].rg - v[i].lf + 1), v[i].cost});
	}

	ll ans = inf;
	map<int, ll> mapa;
	for (int i = n - 1; i >= 0; --i) {
		int len = v[i].rg - v[i].lf + 1;
		if (!mapa.count(len)) {
			mapa[len] = v[i].cost;
		} else {
			mapa[len] = min(mapa[len], v[i].cost);
		}
		for (query& curr : q[i]) {
			if (mapa.count(curr.rem)) {
				ans = min(ans, mapa[curr.rem] + curr.cost);
			}
		}
	}

	cout << (ans == inf ? -1 : ans) << "\n";

}