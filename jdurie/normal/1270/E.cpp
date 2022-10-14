#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

ll x[1010], y[1010];
vector<ll> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll n, R = 10000000;
	cin >> n;
	for(ll i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	while(true) {
		for(ll i = 1; i <= n; i++)
			if((abs(x[i]) % 2) == (abs(y[i]) % 2)) ans.push_back(i);
		if(ans.size() != 0 && ans.size() != n) break;
		if(ans.size() == 0) for(ll i = 1; i <= n; i++) y[i]--;
		ans.clear();
		for(ll i = 1; i <= n; i++) {
			ll temp = x[i];
			x[i] = (x[i] - y[i]) / 2;
			y[i] = (temp + y[i]) / 2;
		}
	}
	cout << ans.size() << endl;
	for(ll a : ans) cout << a << " ";
	cout << endl;
}