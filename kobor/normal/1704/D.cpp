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

void solve() {
	int n, m;
	cin >> n >> m;
	vector<ll> hasz(n);
	FOR(i, 0, n) {
		vector<ll> arr(m);
		TRAV(x, arr) cin >> x;
		FOR(j, 0, m) hasz[i] += 1ll * (m - j) * arr[j];
	}
	ll jed = hasz[0], dwa = hasz[1], trz = hasz[2];
	ll tru = 0;
	if(jed == dwa) tru = jed;
	if(jed == trz) tru = jed;
	if(dwa == trz) tru = dwa;
	FOR(i, 0, n) if(hasz[i] != tru) {
		cout << i + 1 << ' ' << tru - hasz[i] << '\n';
		return;
	}
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