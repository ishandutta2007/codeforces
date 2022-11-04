#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	vector<int> done(n + 1), pos(n + 1);
	for (int i = 0; i < n; ++i) pos[a[i]] = i;
	for (int i = n - 1; i >= 0; --i) pos[i] = min(pos[i], pos[i + 1]);
	int res = 0;
	for (int j = n, i = n - 1, mn; i >= 0; ++res) {
		while (j >= 0 && done[j]) --j;
		mn = pos[j];
		for (; i >= mn; --i) {
			done[a[i]] = true;
			mn = min(mn, pos[a[i]]);
		}
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