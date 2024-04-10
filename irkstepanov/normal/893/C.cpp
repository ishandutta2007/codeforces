#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

vector<vector<int> > g;
vector<int> c;
vector<char> used;

void dfs(int v, int& val) {
	val = min(val, c[v]);
	used[v] = true;
	for (int to : g[v]) {
		if (!used[to]) {
			dfs(to, val);
		}
	}
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	c.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	g.resize(n);
	while (m--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}

	ll ans = 0;
	used.assign(n, false);
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			int val = c[i];
			dfs(i, val);
			ans += val;
		}
	}

	cout << ans << "\n";

}