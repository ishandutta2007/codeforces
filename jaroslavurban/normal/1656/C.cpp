#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	sort(a.begin(), a.end());
	int c[2] = {(int)count(a.begin(), a.end(), 0), (int)count(a.begin(), a.end(), 1)};
	if (c[0] && c[1]) {
		cout << "NO\n";
		return;
	}
	bool pos = true;
	for (int i = 0; i < n - 1; ++i)
		if (a[i] + 1 == a[i + 1])
			pos = false;
	if (!c[1] || (!c[0] && pos && !count(a.begin(), a.end(), 2))) cout << "YES\n";
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