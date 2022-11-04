#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	for (int it = -1; it < 2; ++it) {
		bool pos = true;
		for (int i = 0; i < n; ++i) if (abs(a[i] - (a[0] + it + i)) > 1) pos = false;
		if (pos) { cout << "YES\n"; return; }
	}
	cout << "NO\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}