#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	map<int, int> cnt;
	int mx = 0, res = 0;
	for (int v, i = 0; i < n; ++i) cin >> v, mx = max(mx, ++cnt[v]);
	while (mx < n) {
		res += min(n - mx, mx) + 1;
		mx += mx;
	}
	cout << res << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}