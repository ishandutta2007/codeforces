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

bool check(int n, int m, vi cols) {
	vi ile;
	TRAV(x, cols) if(x / n > 1) ile.PB(x / n);
	sort(ile.begin(), ile.end(), greater<int>());
	ll rem = m;
	TRAV(x, ile) {
		if(rem == 1) return ile.front() > 2;
		rem -= x;
	}
	return rem <= 0;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vi cols(k);
	TRAV(x, cols) cin >> x;
	cout << (check(n, m, cols) || check(m, n, cols) ? "Yes\n" : "No\n");
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