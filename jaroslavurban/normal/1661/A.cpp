#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int& v : a) cin >> v;
	for (int& v : b) cin >> v;
	for (int i = 1; i < n; ++i) if (abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]) > abs(b[i] - a[i - 1]) + abs(a[i] - b[i - 1])) swap(a[i], b[i]);
	ll res = 0;
	for (int i = 1; i < n; ++i) res += abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]);
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