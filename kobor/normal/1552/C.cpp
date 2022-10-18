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

bool inter(ii a, ii b) {
	if(b.X < a.X) swap(a, b);
	return b.X < a.Y && a.Y < b.Y;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<ii> pairs;
	n *= 2;
	vi taken(n), fre;
	FOR(i, 0, k) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		pairs.PB({min(a, b), max(a, b)});
		taken[a] = taken[b] = 1;
	}
	FOR(i, 0, n) if(!taken[i]) fre.PB(i);
	FOR(i, 0, SZ(fre) / 2) pairs.PB({fre[i], fre[i + SZ(fre) / 2]});
	// TRAV(x, pairs) cout << x.X << ' ' << x.Y << '\n';
	int ans = 0;
	// cout << inter(pairs[0], pairs[1]) << '\n';
	FOR(i, 0, SZ(pairs)) FOR(j, 0, i) {
		if(inter(pairs[i], pairs[j])) {
			// cout << i << ' ' << j << '\n';
			ans++;
		}
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