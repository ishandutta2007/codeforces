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
    int r, d, n, ans = 0;
    cin >> r >> d >> n;
    d = r - d;
    FOR(i, 0, n) {
        int x, y, rr;
        cin >> x >> y >> rr;
        ans += x * x + y * y >= (d + rr) * (d + rr) && x * x + y * y <= (r - rr) * (r - rr) && r >= rr;
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