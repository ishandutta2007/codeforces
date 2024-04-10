#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int mod = 998244353;

void ProGamerMove() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	if (count(a.begin(), a.end(), 1) != 1) {
		cout << "NO\n";
		return;
	}
	rotate(a.begin(), find(a.begin(), a.end(), 1), a.end());
	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i - 1] + 1 || a[i] == 1) {
			cout << "NO\n";
			return;
		}
	}
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