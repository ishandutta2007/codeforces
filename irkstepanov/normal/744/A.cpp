#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int nmax = 1050;

int g[nmax][nmax];
char used[nmax];

int n;
vector<int> comp;

int dfs(int v)
{
	used[v] = true;
	comp.pb(v);
	int ans = 1;
	for (int to = 0; to < n; ++to) {
		if (g[v][to] && !used[to]) {
			ans += dfs(to);
		}
	}
	return ans;
}

int main()
{

	int m, k;

	scanf("%d%d%d", &n, &m, &k);
	vector<int> capitals;

	for (int i = 0; i < k; ++i) {
		int x;
		scanf("%d", &x);
		capitals.pb(x - 1);
	}

	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		g[u][v] = g[v][u] = 1;
	}

	vector<int> bestComp;
	int ans = 0;

	for (int i = 0; i < k; ++i) {
		int curr = dfs(capitals[i]);
		if (curr > sz(bestComp)) {
			bestComp = comp;
		}
		for (int u : comp) {
			for (int v : comp) {
				if (u != v && !g[u][v]) {
					g[u][v] = g[v][u] = 1;
					++ans;
				}
			}
		}
		comp.clear();
	}

	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			for (int v : bestComp) {
				if (!g[v][i]) {
					g[v][i] = g[i][v] = 1;
					++ans;
				}
			}
			bestComp.pb(i);
		}
	}

	cout << ans << '\n';

}