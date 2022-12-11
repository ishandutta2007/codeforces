#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

vector<vector<int> > g;
vector<int> comp;

void dfs(int v, int cc)
{
	comp[v] = cc;
	for (int to : g[v]) {
		if (comp[to] == -1) {
			dfs(to, cc);
		}
	}
}

const int mod = 1e9 + 7;

void mul(int& a, int b)
{
	ll c = ll(a) * ll(b);
	if (c >= mod) {
		c %= mod;
	}
	a = c;
}

int main()
{

	//ifstream cin("strictly-off.in");
	//ofstream cout("strictly-off.out");
	//freopen("input.txt", "r", stdin);
	//freopen("threed.out", "w", stdout);
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, m, k;
	cin >> n >> m >> k;
	g.resize(n);

	for (int i = 0; i + k - 1 < n; ++i) {
		for (int j = i; j <= i + k - 1; ++j) {
			g[j].pb(i + k - 1 - (j - i));
			g[i + k - 1 - (j - i)].pb(j);
		}
	}

	comp.assign(n, -1);

	int cc = 0;
	for (int i = 0; i < n; ++i) {
		if (comp[i] == -1) {
			dfs(i, cc);
			++cc;
		}
	}

	int ans = 1;
	for (int i = 0; i < cc; ++i) {
		mul(ans, m);
	}
	cout << ans << '\n';

}