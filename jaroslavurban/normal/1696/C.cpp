#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

vector<pair<ll, int>> decompose(vector<int> a, int m) {
	int n = a.size();
	vector<pair<ll, int>> res = {{0ll, 0}};
	for (int i = 0; i < n; ++i) {
		ll cnt = 1;
		while (a[i] % m == 0) cnt *= m, a[i] /= m;
		if (a[i] == res.back().second) res.back().first += cnt;
		else res.push_back({cnt, a[i]});
	}
	return res;
}

void ProGamerMove() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	int k; cin >> k;
	vector<int> b(k);
	for (int& v : b) cin >> v;
	if (decompose(a, m) == decompose(b, m)) cout << "YES\n";
	else cout << "NO\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}