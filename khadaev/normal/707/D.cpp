#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 1010;

int n, m, q;
vector<int> t, x, y;
vector<vector<int>> ch;
vector<char> inv;
vector<bitset<N>> a;
vector<int> cnt;
int cur = 0;
vector<int> ans;

void dfs(int i) {
	ans[i] = cur;
	for (int j : ch[i]) {
		if (t[j - 1] == 4) dfs(j);
		if (t[j - 1] == 3) {
			int p = x[j - 1];
			inv[p] = 1 - inv[p];
			cur -= cnt[p];
			cnt[p] = m - cnt[p];
			cur += cnt[p];
			dfs(j);
			inv[p] = 1 - inv[p];
			cur -= cnt[p];
			cnt[p] = m - cnt[p];
			cur += cnt[p];
		}
		if (t[j - 1] == 2) {
			int p = x[j - 1], r = y[j - 1];
			if (!(a[p][r] ^ inv[p])) dfs(j);
			else {
				--cnt[p];
				a[p][r] = inv[p];
				--cur;
				dfs(j);
				++cur;
				a[p][r] = 1 - inv[p];
				++cnt[p];
			}
		}
		if (t[j - 1] == 1) {
			int p = x[j - 1], r = y[j - 1];
			if (a[p][r] ^ inv[p]) dfs(j);
			else {
				++cnt[p];
				a[p][r] = 1 - inv[p];
				++cur;
				dfs(j);
				--cur;
				a[p][r] = inv[p];
				--cnt[p];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	x.resize(q), y.resize(q), t.resize(q), ch.resize(q + 1), inv.resize(n), a.resize(n), cnt.resize(n), ans.resize(q + 1);
	forn(i, 0, q) {
		cin >> t[i] >> x[i];
		if (t[i] != 4) --x[i];
		if (t[i] <= 2) {
			cin >> y[i];
			--y[i];
		}
		if (t[i] == 4) {
			ch[x[i]].eb(i + 1);
		} else ch[i].eb(i + 1);
	}
	dfs(0);
	fore(i, 1, q) cout << ans[i] << '\n';
	return 0;
}