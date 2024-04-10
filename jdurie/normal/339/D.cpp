#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

ll a[500000][20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, m, p, b;
	cin >> n >> m;
	for(ll i = 0; i < (1 << n); i++) cin >> a[i][0];
	for(ll j = 1; j <= n; j++)
		for(ll i = 0; i < (1 << (n - j)); i++)
			a[i][j] = j % 2 ? a[2 * i][j - 1] | a[2 * i + 1][j - 1] : a[2 * i][j - 1] ^ a[2 * i + 1][j - 1];
	while(m--) {
		cin >> p >> b;
		p--;
		a[p][0] = b;
		for(ll j = 1; j <= n; j++) {
			p /= 2;
			a[p][j] = j % 2 ? a[2 * p][j - 1] | a[2 * p + 1][j - 1] : a[2 * p][j - 1] ^ a[2 * p + 1][j - 1];
		}
		cout << a[0][n] << endl;
	}
}