#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, m; cin >> n >> m;
	string a, b;
	cin >> a >> b;
	for (auto& v : a) v -= '0';
	for (auto& v : b) v -= '0';
	int one = false, zero = false;
	for (int i = 0; i <= n - m; ++i) {
		if (a[i] == 0) zero = true;
		else one = true;
	}
	if ((b[0] == 1 && !one) || (b[0] == 0 && !zero) || a.substr(n - m + 1, m - 1) != b.substr(1, m - 1)) { cout << "NO\n"; return; }
	cout << "YES\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}