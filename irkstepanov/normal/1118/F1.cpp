#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

vector<int> color;
vector<int> sum[3];
vector<vector<int> > g;
int total[3];

int ans = 0;

void dfs(int v, int p) {
	sum[color[v]][v] = 1;
	for (int to : g[v]) {
		if (to == p) {
			continue;
		}
		dfs(to, v);
		if ((sum[1][to] == total[1] && sum[2][to] == 0) || (sum[2][to] == total[2] && sum[1][to] == 0)) {
			++ans;
		}
		for (int i = 0; i < 3; ++i) {
			sum[i][v] += sum[i][to];
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	g.resize(n);
	color.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> color[i];
		++total[color[i]];
	}
	for (int i = 0; i < 3; ++i) {
		sum[i].resize(n);
	}

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}

	dfs(0, 0);
	cout << ans << "\n";

}