#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int STANDARD = 1;
const int MOVE = 2;

int n, m, k, c, d;

struct edge {
	int u, v, c, w, f, t;

	bool can_flow() const {
		if (t == MOVE)
			return true;
		if (t == -MOVE)
			return f < 0;
		return f < c;
	}

	int cost() const {
		if (t == MOVE)
			return ::c+d+2*d*f;
		else if (t == -MOVE)
			return d+2*d*f-::c;
		return w;
	}
};

edge e[42000]; int ec;
vector<pair<int, int>> g;
int a[55];

int run_flow(int source, int sink) {
	vector<int> d(6666, 1123123123);
	vector<int> p(6666, -1);
	d[source] = 0;
	p[source] = -1;

	bool something = true;
	while (something) {
		something = false;
		for (int i=0; i<ec; i++) {
			if (d[e[i].v] > d[e[i].u] + e[i].cost() && e[i].can_flow()) {
				d[e[i].v] = d[e[i].u] + e[i].cost();
				p[e[i].v] = i;
				something = true;
			}
		}
	}

	// for (int i=0; i<=source; i++)
		// cerr << i << ' ' << d[i] << ' ' << p[i] << '\n';

	for (int x=sink; x!=source;) {
		int i = p[x];
		// cerr << "using edge " << e[i].u << ' ' << e[i].v << ' '
			// << e[i].cost() << ' ' << e[i].f << ' ' << e[i].t << '\n';
		e[i].f += 1;
		e[i^1].f -= 1;
		x = e[i].u;
	}

	// cerr << "dist: " << d[sink] << '\n';
	return d[sink];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k >> c >> d;
	for (int i=0; i<k; i++) {
		int x;
		cin >> x;
		x--;
		a[x]++;
	}

	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g.emplace_back(u, v);
		g.emplace_back(v, u);
	}

	const int layers = k+m;

	for (int t=0; t<layers; t++) {
		// stoji u mestu
		for (int i=0; i<n; i++) {
			e[ec++] = {t*n+i, (t+1)*n+i, 1000,  i? c:0, 0, STANDARD};
			e[ec++] = {(t+1)*n+i, t*n+i,    0,  i?-c:0, 0, STANDARD};
		}
		// pomeri se
		for (auto [u, v] : g) {
			e[ec++] = {t*n+u, (t+1)*n+v, 0, 0, 0,  MOVE};
			e[ec++] = {(t+1)*n+v, t*n+u, 0, 0, 0, -MOVE};
		}
	}
	const int source = (layers+1)*n;
	const int sink = layers*n;
	// pocetni
	for (int i=0; i<n; i++) {
		e[ec++] = {source, i, a[i], 0, 0, STANDARD};
		e[ec++] = {i, source,    0, 0, 0, STANDARD};
	}

	// rokaj
	int sol = 0;
	for (int iter=0; iter<k; iter++) {
		sol += run_flow(source, sink);
	}
	cout << sol << '\n';
}