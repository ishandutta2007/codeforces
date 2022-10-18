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

const int N = 2e5 + 5;
const int mod = 998244353;

int x[N], y[N], s[N];
int dp[N], prefDp[N], ans[N];

void solve() {
	int n;
	cin >> n;
	FOR(i, 0, n) cin >> x[i] >> y[i] >> s[i];
	FOR(i, 0, n) {
		int pos = lower_bound(x, x + n, y[i]) - x;
		dp[i] = (2ll * mod + x[i] - y[i] + prefDp[i] - prefDp[pos]) % mod;
		prefDp[i + 1] = (prefDp[i] + dp[i]) % mod;
	}
	FOR(i, 0, n) {
		ans[i] = (i == 0 ? x[i] : (x[i] - x[i - 1] + ans[i - 1]) % mod);
		if(s[i]) ans[i] = (ans[i] + dp[i]) % mod;
	}
	cout << (ans[n - 1] + 1) % mod << '\n';
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