#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int mod = 998244353;

void ProGamerMove() {
	int n; cin >> n;
	if (n & 1) {
		cout << "0\n";
		return;
	}
	ll n1 = 1, n2 = 1;
	for (int i = 1; i <= n / 2; ++i) n1 = n1 * i % mod;
	for (int i = 1; i <= (n + 1) / 2; ++i) n2 = n2 * i % mod;
	cout << n1 * n2 % mod << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}