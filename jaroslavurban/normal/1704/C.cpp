#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, m; cin >> n >> m;
	vector<int> a(m);
	for (int& v : a) cin >> v;
	sort(a.begin(), a.end());
	vector<int> sizes(m);
	for (int i = 0; i + 1 < m; ++i) sizes[i] = a[i + 1] - a[i] - 1;
	sizes[m - 1] = n - a[m - 1] + a[0] - 1;
	sort(sizes.rbegin(), sizes.rend());
	int res = 0;
	for (int i = 0, days = 0; i < m; ++i) {
		int nsz = max(0, sizes[i] - 2 * days);
		if (nsz == 1 || nsz == 2) {
			++days;
			++res;
		} else if (nsz >= 3) {
			days += 2;
			res += nsz - 1;
		}
	}
	cout << n - res << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}