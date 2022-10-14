#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

ll a[100010];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	ll n = s.size();
	for(ll i = 1; i < n; i++)
		a[i] = a[i - 1] + (s[i] == s[i - 1] ? 1 : 0);
	ll m;
	cin >> m;
	for(ll i = 0; i < m; i++) {
		ll l, r;
		cin >> l >> r;
		cout << a[r - 1] - a[l - 1] << endl;
	}
}