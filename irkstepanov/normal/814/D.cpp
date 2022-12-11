#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int nmax = 1050;
const ll inf = 1e18;
const ld pi = 4 * atan(1.0);

ll dist2(ll a, ll b, ll c, ll d)
{
	return (a - c) * (a - c) + (b - d) * (b - d);
}

ll dp[nmax][2][2];

vector<vector<int> > g;
vector<ll> r;
vector<char> root;

void dfs(int v)
{
	for (int to : g[v]) {
		dfs(to);
	}
	for (int a = 0; a < 2; ++a) {
		for (int b = 0; b < 2; ++b) {
			ll val;
			if (a == 0) {
				val = -r[v];
			} else {
				val = r[v];
			}
			//cout << v + 1 << " " << a << " " << b << endl;
			for (int to : g[v]) {
				val += max(dp[to][1 - a][b], dp[to][b][1 - a]);
			}
			dp[v][a][b] = max(dp[v][a][b], val);
		}
	}
}

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int n;
	cin >> n;

	g.resize(n);
	vector<ll> x(n), y(n);
	r.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i] >> r[i];
		r[i] *= r[i];
	}

	root.assign(n, true);

	for (int i = 0; i < n; ++i) {
		int best = -1;
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				continue;
			}
			if (r[i] < r[j] && dist2(x[i], y[i], x[j], y[j]) <= r[j]) {
				if (best == -1 || r[best] > r[j]) {
					best = j;
				}
			}
		}
		if (best != -1) {
			g[best].pb(i);
			root[i] = false;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int a = 0; a < 2; ++a) {
			for (int b = 0; b < 2; ++b) {
				dp[i][a][b] = -inf;
			}
		}
	}

	/*for (int v = 0; v < n; ++v) {
		for (int to : g[v]) {
			cout << v + 1 << " " << to + 1 << endl;
		}
	}*/

	ll ans = 0;

	for (int v = 0; v < n; ++v) {
		if (root[v]) {
			dfs(v);
			ans += dp[v][1][1];
		}
	}

	ld res = ld(ans) * pi;
	cout << fixed;
	cout.precision(12);
	cout << res << "\n";

}