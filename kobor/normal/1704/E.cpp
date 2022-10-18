#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long double K;
constexpr int INF = 0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define X first
#define Y second

constexpr int N = 1010;
constexpr int mod = 998'244'353;

int arr[N];
vi G[N];
bool vis[N];
vi topo;
vector<pair<ii, int>> pr[N]; // {{start, czyBig}, len}

void dfs(int v) {
	vis[v] = 1;
	TRAV(x, G[v]) if(!vis[x]) dfs(x);
	topo.PB(v);
}

void solve() {
	int n, m;
	cin >> n >> m;
	FOR(i, 0, n) cin >> arr[i];
	FOR(i, 0, n) G[i].clear();
	FOR(i, 0, m) {
		int a, b;
		cin >> a >> b;
		G[a - 1].PB(b - 1);
	}
	topo.clear();
	FOR(i, 0, n) vis[i] = 0;
	FOR(i, 0, n) if(!vis[i]) dfs(i);
	reverse(topo.begin(), topo.end());
	// TRAV(x, topo) cout << x << '\n';
	FOR(i, 0, n) pr[i].clear();
	TRAV(i, topo) {
		pr[i].PB({{0, arr[i] >= mod}, arr[i] % mod});
		sort(pr[i].begin(), pr[i].end());
		vector<pair<ii, int>> nw;
		pair<ii, int> akt = {{0, 0}, 0};
		TRAV(cur, pr[i]) {
			if(1ll * akt.X.X + akt.X.Y * mod + akt.Y >= cur.X.X) {
				akt.Y += cur.Y;
				if(akt.Y >= mod) akt.Y -= mod, akt.X.Y = 1;
				if(cur.X.Y == 1) akt.X.Y = 1;
			}
			else nw.PB(akt), akt = cur;
		}
		nw.PB(akt);
		pr[i].clear();
		TRAV(x, nw) if(x.Y || x.X.Y) pr[i].PB(x);
		TRAV(x, G[i]) TRAV(el, pr[i]) pr[x].PB({{el.X.X + 1, el.X.Y}, el.Y});
	}
	int last = topo.back();
	if(SZ(pr[last]) == 0) cout << "0\n";
	else cout << (pr[last].back().X.X + pr[last].back().Y) % mod << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	FOR(te, 0, tt) {
		// cout << "Case #" << te + 1 << ": ";
		solve();
	}
    // solve();
	return 0;
}