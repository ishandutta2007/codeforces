#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, m; cin >> n >> m;
	int mr = 0, mw = 0;
	for (int r, w, i = 0; i < m; ++i) cin >> r >> w, mr = max(mr, r), mw = max(mw, w);
	cout << (mr + mw <= n ? string(mr, 'R') + string(n - mr, 'W') : "IMPOSSIBLE") << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}