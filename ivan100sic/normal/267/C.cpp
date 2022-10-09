#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[105];
bool g[105];
int u[5005], v[5005], w[5005];
const double eps = 1e-9;

struct gaus {
	vector<valarray<double>> g;

	gaus() {
		g.resize(105, valarray<double>(0.0, 105));
	}

	void add_eqn(valarray<double> b) {
		for (int i=0; i<105; i++) {
			if (abs(b[i]) >= eps) {
				if (abs(g[i][i]) < eps) {
					g[i] = b / b[i];
					return;
				} else {
					b -= g[i] * b[i];
				}
			}
		}
	}

	void dump() {
		for (int i=1; i<=7; i++) {
			for (int j=1; j<=7; j++)
				cerr << g[i][j] << ' ';
			cerr << " = " << g[i][104] << '\n';
		}
	}

	vector<double> readsol() {
		vector<double> sol(n+1);
		for (int i=n; i>=1; i--) {
			if (abs(g[i][i]) >= eps) {
				double w = g[i][104];
				for (int j=i+1; j<=n; j++)
					w -= sol[j] * g[i][j];
				sol[i] = w;
			}
		}
		return sol;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		e[u[i]] += v[i];
		e[v[i]] += u[i];
	}

	basic_string<int> q = {1};
	g[1] = 1;
	size_t qs = 0;
	while (q.size() != qs) {
		int x = q[qs++];
		for (int y : e[x]) {
			if (!g[y]) {
				g[y] = 1;
				q += y;
			}
		}
	}
	if (!g[n]) {
		for (int i=0; i<=m; i++)
			cout << "0\n";
		return 0;
	}

	gaus ga;
	for (int i=2; i<n; i++) {
		valarray<double> a(0.0, 105);
		for (int j : e[i])
			a[j] += 1, a[i] -= 1;
		ga.add_eqn(a);
	}

	{
		valarray<double> a(0.0, 105);
		a[1] = 1;
		ga.add_eqn(a);
		a[1] = 0, a[n] = 1, a[104] = 1;
		ga.add_eqn(a);
	}

	ga.dump();

	auto d = ga.readsol();
	double factor = 1e9;
	for (int i=0; i<m; i++) {
		if (!g[u[i]])
			continue;
		double dabs = abs(d[u[i]] - d[v[i]]);
		if (dabs < eps)
			continue;
		factor = min(factor, w[i] / dabs);	
	}

	cout << setprecision(14) << fixed;
	double sol = 0;
	for (int j : e[1])
		sol += factor * d[j];
	cout << sol << '\n';
	for (int i=0; i<m; i++) {
		if (!g[u[i]]) {
			cout << "0\n";
		} else {
			cout << factor * (d[v[i]] - d[u[i]]) << '\n';
		}
	}
}