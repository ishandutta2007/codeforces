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
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	int diff = n - m + 1;
	bool ok = false;
	FOR(i, 0, diff) if(a[i] == b[0]) ok = true;
	cout << (ok && a.substr(diff) == b.substr(1) ? "YES\n" : "NO\n");
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