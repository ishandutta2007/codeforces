#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int SITO_MAX = 200000;

int f[SITO_MAX+1];
vector<int> prosti;

struct sito {
	sito() {
		for (int i=2; i<=SITO_MAX; i++) {
			if (f[i] == 0) {
				f[i] = i;
				prosti.push_back(i);
			}
			int j = 0;
			while (j < (int)prosti.size()) {
				if (prosti[j] > f[i]) {
					break;
				}
				int x = i * prosti[j];
				if (x > SITO_MAX) {
					break;
				}
				f[x] = prosti[j];
				j++;
			}
		}
	}
} sito_obj_983431;

vector<pair<int, int>> factor_small(int x) {
	vector<pair<int, int>> v;
	while (x > 1) {
		int p = f[x];
		int c = 0;
		while (x % p == 0) {
			x /= p;
			c++;
		}
		v.push_back({p, c});
	}
	return v;
}

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

int n;
int a[200005];
basic_string<pair<int, int>> g[200005];

basic_string<int> alive;
basic_string<int> e[200005];

int d[200005];

basic_string<int> dfs_reach;

void dfs(int x, int dist = 0) {
	d[x] = dist;
	dfs_reach += x;
	for (int y : e[x]) {
		if (d[y] == -1) {
			dfs(y, dist + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;

		auto w = factor_small(gcd(a[u], a[v]));
		for (auto p : w) {
			g[p.first] += {u, v};
		}
	}

	int sol = 0;

	for (int i=1; i<=n; i++)
		if (a[i] > 1)
			sol = 1;

	for (int p : prosti) {
		for (auto q : g[p]) {
			int u, v;
			tie(u, v) = q;
			alive += {u, v};
			e[u] += v;
			e[v] += u;
		}
		for (int x : alive)
			d[x] = -1;
		for (int x : alive)
			if (d[x] == -1) {
				dfs_reach = {};
				dfs(x, 0);
				int best = x;
				for (int y : dfs_reach) {
					if (d[y] > d[best]) {
						best = y;
					}
				}
				for (int y : dfs_reach)
					d[y] = -1;
				dfs_reach = {};
				dfs(best, 0);
				for (int y : dfs_reach) {
					if (d[y] > d[best]) {
						best = y;
					}
				}
				sol = max(sol, d[best] + 1);
			}
		for (int y : alive)
			e[y] = {};
		alive = {};
	}

	cout << sol << '\n';
}