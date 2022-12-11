#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

struct edge {
	int from, to;
	int id;
};

vector<vector<edge> > g;

void dfs(int v, int p, ld s) {
	ld delta = ld(2) / ld(sz(g[v]));
	for (edge& e : g[v]) {
		if (e.to == p) {
			continue;
		}
		s += delta;
		if (s >= 2) {
			s -= 2;
		}
		cout << "1 " << e.id << " ";
		if (s <= 1) {
			cout << e.to + 1 << " " << e.from + 1 << " " << 1 - s << "\n";
			dfs(e.to, v, 1 + s);
		} else {
			cout << e.from + 1 << " " << e.to + 1 << " " << 2 - s << "\n";
			dfs(e.to, v, s - 1);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	int n;
	cin >> n;

	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb({u, v, i + 1});
		g[v].pb({v, u, i + 1});
	}

	cout << n - 1 << "\n";
	cout << fixed;
	cout.precision(12);
	dfs(0, 0, 0);

}