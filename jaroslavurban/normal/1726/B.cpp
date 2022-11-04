#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, m; cin >> n >> m;
	if (n > m) { cout << "NO\n"; return; }
	if (n & 1) {
		cout << "YES\n";
		for (int i = 0; i < n - 1; ++i) cout << "1 ";
		cout << m - n + 1 << '\n';
	} else if (!(n & 1) && !(m & 1)) {
		cout << "YES\n";
		for (int i = 0; i < n - 2; ++i) cout << "1 ";
		cout << (m - n + 2) / 2 << ' ' << (m - n + 2) / 2 << '\n';
	} else { cout << "NO\n"; return; }
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}