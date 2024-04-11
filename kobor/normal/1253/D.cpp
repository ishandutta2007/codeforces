#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef double K;
constexpr int INF = 0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define X first
#define Y second

constexpr int N = 2e5 + 5;

bool vis[N];
vi G[N];
int wierzcholki, maks;

void dfs(int v) {
	vis[v] = true;
	wierzcholki++;
	maks = max(maks, v);
	TRAV(x, G[v]) if(!vis[x]) dfs(x);
}

void solve() {
	int n, m;
	cin >> n >> m;
	FOR(i, 0, m) {
		int a, b;
		cin >> a >> b;
		G[a].PB(b), G[b].PB(a);
	}
	int ans = 0;
	FOR(i, 1, n) {
		if(!vis[i]) {
			dfs(i);
			if(wierzcholki != maks) ans++;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// int tt; cin >> tt;
	// FOR(te, 0, tt) {
	// 	// cout << "Case #" << te + 1 << ": ";
	// 	solve();
	// }
	solve();
	return 0;
}