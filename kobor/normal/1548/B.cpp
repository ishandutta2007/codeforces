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

ll t[N];
vector<pair<ll, int>> gst[N];

void solve() {
	int n, odp = 0;
	cin >> n;
	FOR(i, 0, n) cin >> t[i];
	n--;
	FOR(i, 0, n) t[i] -= t[i + 1];
	FOR(i, 0, n) t[i] = abs(t[i]);
	gst[n].clear();
	for(int i = n - 1; i >= 0; i--) {
		gst[i] = {{t[i], i}};
		TRAV(x, gst[i + 1]) {
			ll ans = gcd(x.X, gst[i].back().X);
			if(ans != gst[i].back().X) gst[i].PB({ans, 0});
			gst[i].back().Y = x.Y;
		}
	}
	FOR(i, 0, n) TRAV(x, gst[i]) if(x.X != 1) odp = max(odp, x.Y - i + 1);
	cout << odp + 1 << '\n';
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