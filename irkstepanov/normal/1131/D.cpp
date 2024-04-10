#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int nmax = 1050;

string a[nmax];

int parent[2 * nmax];
int size[2 * nmax];

int get(int v) {
	if (parent[v] == v) {
		return v;
	}
	return parent[v] = get(parent[v]);
}

void unite(int u, int v) {
	u = get(u), v = get(v);
	if (u == v) {
		return;
	}
	if (size[u] < size[v]) {
		swap(u, v);
	}
	parent[v] = u;
	size[u] += size[v];
}

bool alive[2 * nmax];
vector<int> g[2 * nmax];
int color[2 * nmax];

bool dfs1(int v) {
	color[v] = 1;
	for (int to : g[v]) {
		if (color[to] == 1) {
			return false;
		}
		if (color[to] == 2) {
			continue;
		}
		if (!dfs1(to)) {
			return false;
		}
	}
	color[v] = 2;
	return true;
}

int dp[2 * nmax];

void dfs2(int v) {
	dp[v] = 1;
	for (int to : g[v]) {
		if (!dp[to]) {
			dfs2(to);
		}
		dp[v] = max(dp[v], 1 + dp[to]);
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n + m; ++i) {
		parent[i] = i;
		size[i] = 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '=') {
				unite(i, j + n);
			}
		}
	}

	for (int i = 0; i < n + m; ++i) {
		if (get(i) == i) {
			alive[i] = true;
		} else {
			alive[i] = false;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '=') {
				continue;
			}
			int x = get(i), y = get(j + n);
			if (a[i][j] == '>') {
				g[x].pb(y);
			} else {
				g[y].pb(x);
			}
		}
	}

	for (int i = 0; i < n + m; ++i) {
		if (!alive[i] || color[i]) {
			continue;
		}
		if (!dfs1(i)) {
			cout << "No\n";
			return 0;
		}
	}

	cout << "Yes\n";

	for (int i = 0; i < n + m; ++i) {
		if (!alive[i] || dp[i]) {
			continue;
		}
		dfs2(i);
	}

	for (int i = 0; i < n; ++i) {
		int x = get(i);
		cout << dp[x] << " ";
	}
	cout << "\n";
	for (int i = 0; i < m; ++i) {
		int x = get(i + n);
		cout << dp[x] << " ";
	}
	cout << "\n";

}