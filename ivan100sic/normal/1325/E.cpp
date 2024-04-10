// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int SITO_MAX = 1000000;

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

const int N = 80000;
const int K = 170;

int n, sol = 1e9;
int mark[N];
set<pair<int, int>> edges;
basic_string<int> e[N];

void sp_markirani() {
	vector<int> d(N, -1), p(N, -2);
	basic_string<int> q;
	for (int i=0; i<N; i++)
		if (mark[i])
			q += i, d[i] = 0, p[i] = i;
	size_t qs = 0;
	while (qs != q.size()) {
		int x = q[qs++];
		for (int y : e[x]) {
			if (d[y] == -1) {
				d[y] = d[x] + 1;
				p[y] = p[x];
				q += y;
			}
		}
	}

	for (int i=0; i<N; i++) {
		for (int j : e[i]) {
			if (p[j] != p[i] && d[i] >= 0 && d[j] >= 0) {
				sol = min(sol, 3 + d[i] + d[j]);
			}
		}
	}
}

int d[K][K], d0[K][K];

void min_cikl() {
	memset(d, 31, sizeof d);
	for (int i=0; i<K; i++)
		d[i][i] = 0;
	for (int i=0; i<K; i++)
		for (int j : e[i])
			if (j < K)
				d[i][j] = 1;
	memcpy(d0, d, sizeof d);
	for (int k=0; k<K; k++) {
		for (int i=0; i<k; i++) {
			for (int j=i+1; j<k; j++) {
				sol = min(sol, d0[i][k] + d0[j][k] + d[i][j]);
			}
		}

		for (int i=0; i<K; i++) {
			for (int j=0; j<K; j++) {
				d[i][j] = min(d[i][j], d[k][i] + d[k][j]);
			}
		}
	}

	// odavde su validni samo d[x][y] gde je x <= y

	for (int k=K; k<N; k++) {
		basic_string<int> t;
		for (int i : e[k])
			if (i < k)
				t += i;
		int m = t.size();
		sort(t.begin(), t.end());
		for (int u=0; u<m; u++) {
			for (int v=u+1; v<m; v++) {
				sol = min(sol, 2 + d[t[u]][t[v]]);
			}
		}

		if (t.size() >= 2) {
			for (int u=0; u<m; u++) {
				for (int v=u+1; v<m; v++) {
					int x = t[u], y = t[v];
					if (d[x][y] > 2) {
						// premosti
						for (int i=0; i<K; i++) {
							for (int j=i+1; j<K; j++) {
								int v1 = i < x ? d[i][x] : d[x][i];
								int v2 = y < j ? d[y][j] : d[j][y];
								int v3 = i < y ? d[i][y] : d[y][i];
								int v4 = x < j ? d[x][j] : d[j][x];
								d[i][j] = min({d[i][j], v1 + v2 + 2, v3 + v4 + 2});
							}
						}
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		auto v = factor_small(x);
		vector<int> w;
		for (auto [p, e] : v) {
			if (e % 2) {
				w.emplace_back(lower_bound(prosti.begin(), prosti.end(), p) - prosti.begin());
			}
		}

		if (w.size() == 0) {
			sol = min(sol, 1);
		} else if (w.size() == 1) {
			if (mark[w[0]])
				sol = min(sol, 2);
			mark[w[0]] = 1;
		} else {
			sort(begin(w), end(w));
			if (edges.count({w[0], w[1]})) {
				sol = min(sol, 2);
			} else {
				edges.insert({w[0], w[1]});
				e[w[0]] += w[1];
				e[w[1]] += w[0];
			}
		}
	}

	sp_markirani();
	min_cikl();

	if (sol > 1e7)
		sol = -1;
	cout << sol << '\n';
}

// I will still practice daily...