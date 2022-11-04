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
	int res = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j <= n; ++j)
			for (int k = i; k < j; ++k)
				res += 1 + !a[k];
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