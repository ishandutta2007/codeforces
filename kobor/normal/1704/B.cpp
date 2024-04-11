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

constexpr int N = 2e5 + 5;

void solve() {
	int n, x, ans = 0;
	cin >> n >> x;
	vi arr(n);
	TRAV(xx, arr) cin >> xx;
	int down = arr[0] - x, up = arr[0] + x;
	TRAV(xx, arr) {
		int cd = xx - x, cu = xx + x;
		down = max(down, cd);
		up = min(up, cu);
		if(down > up) ans++, down = cd, up = cu;
	}
	cout << ans << '\n';
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