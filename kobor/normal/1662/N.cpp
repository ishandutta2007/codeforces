#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define SZ(x) ((int)x.size())
#define PB push_back
using vi = vector<int>;
using ll = long long;
using ii = pair<int, int>;

constexpr int N = 1501 * 1501;

ii tab[N];
int row[N], col[N];

void solve() {
	int n;
	cin >> n;
	FOR(i, 0, n) FOR(j, 0, n) {
		int a; cin >> a;
		tab[a - 1] = {i, j};
	}
	ll ans = 0;
	FOR(i, 0, n * n) {
		auto [x, y] = tab[i];
		row[x]++, col[y]++;
		ans += 1ll * (n - row[x]) * (n - col[y]);
	}
	ans = 1ll * n * (n - 1) / 2 * n * (n - 1) - ans;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt = 1; //cin >> tt;
	FOR(te, 0, tt) solve();
	return 0;
}