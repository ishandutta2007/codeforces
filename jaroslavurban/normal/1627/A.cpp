#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, m, r, c;
	cin >> n >> m >> r >> c;
	vector<string> f(n);
	for (auto& s: f) cin >> s;
	--c, --r;
	if (f[r][c] == 'B') {
		cout << "0\n";
		return;
	}
	bool found = 0;
	for (int i = 0; i < n; ++i) {
		if (f[i][c] == 'B') found = true;
	}
	for (int i = 0; i < m; ++i) {
		if (f[r][i] == 'B') found = true;
	}
	if (found) {
		cout << "1\n";
		return;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (f[i][j] == 'B') found = true;
	if (found) {
		cout << "2\n";
	} else cout << "-1\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}