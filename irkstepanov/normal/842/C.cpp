#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int nmax = 200500;

int cnt[nmax];
vector<vector<int> > g;
vector<int> a;
vector<int> divs[nmax];
vector<int> ans;

void dfs(int v, int p, int h) {
	for (int d : divs[a[v]]) {
		++cnt[d];
	}
	if (v == p) {
		ans[v] = a[v];
	} else {
		for (int d : divs[a[v]]) {
			if (cnt[d] >= h - 1) {
				ans[v] = max(ans[v], d);
			}
		}
		for (int d : divs[a[p]]) {
			if (cnt[d] >= h - 1) {
				ans[v] = max(ans[v], d);
			}
		}
	}
	for (int to : g[v]) {
		if (to != p) {
			dfs(to, v, h + 1);
		}
	}
	for (int d : divs[a[v]]) {
		--cnt[d];
	}
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

	int n;
	cin >> n;
	g.resize(n);
	a.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}

	for (int x = 1; x < nmax; ++x) {
		for (int d = 1; d * d <= x; ++d) {
			if (x % d == 0) {
				divs[x].pb(d);
				if (d * d != x) {
					divs[x].pb(x / d);
				}
			}
		}
	}

	ans.resize(n);
	dfs(0, 0, 1);

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";

}