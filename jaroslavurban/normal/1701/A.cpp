#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

void ProGamerMove() {
	int cnt = 0;
	for (int v, i = 0; i < 4; ++i) cin >> v, cnt += v;
	if (cnt == 0) cout << "0\n";
	if (cnt == 1) cout << "1\n";
	if (cnt == 2) cout << "1\n";
	if (cnt == 3) cout << "1\n";
	if (cnt == 4) cout << "2\n";
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}