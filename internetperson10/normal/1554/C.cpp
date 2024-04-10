#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll f(ll n, ll m) {
	// cout << n << ' ' << m << ' ';
	ll i = 1;
	while((n | (i-1)) <= m) {
		i *= 2;
	}
	// cout << i << '\n';
	if(i == 1) return 0;
	return (i/2) + f(n, m - (i/2));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n, m;
		cin >> n >> m;
		cout << f(n, m) << '\n';
	}
}