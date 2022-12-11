#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int nmax = 200500;
const int kmax = 6;

ll cnt[nmax][kmax];
ll sum[nmax][kmax];
ll ans = 0;

vector<vector<int> > g;
int n, k;

void dfs(int v, int p)
{
	cnt[v][0] = 1;
	if (sz(g[v]) == 1 && g[v][0] == p) {
		return;
	}
	for (int to : g[v]) {
		if (to != p) {
			dfs(to, v);
			for (int r1 = 0; r1 < k; ++r1) {
				for (int r2 = 0; r2 < k; ++r2) {
					ans += ll((r1 + r2 + k) / k) * cnt[v][r1] * cnt[to][r2];
					ans += sum[v][r1] * cnt[to][r2];
					ans += sum[to][r2] * cnt[v][r1];
				}
			}
			for (int r = 0; r < k; ++r) {
				int newr = r + 1;
				if (newr == k) {
					newr = 0;
				}
				cnt[v][newr] += cnt[to][r];
				if (newr) {
					sum[v][newr] += sum[to][r];
				} else {
					sum[v][newr] += sum[to][r] + cnt[to][r];
				}
			}
		}
	}
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

	cin >> n >> k;
	g.resize(n);
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