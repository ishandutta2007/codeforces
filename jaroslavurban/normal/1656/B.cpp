#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	sort(a.begin(), a.end());
	for (int i = 0; i < n - 1; ++i) {
		if (binary_search(a.begin() + i + 1, a.end(), k + a[i])) {
			cout << "YES\n";
			return;
		}
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