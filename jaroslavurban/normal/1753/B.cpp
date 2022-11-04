#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, x; cin >> n >> x;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	sort(a.begin(), a.end());
	for (ll sm = 0, i = 0, num = 1; num <= x; ++num) {
		if (sm % num) { cout << "No\n"; return; }
		sm /= num;
		while (i < n && a[i] == num) ++i, ++sm;
	}
	cout << "Yes\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	// cin >> tc;
	while (tc--) ProGamerMove();
}