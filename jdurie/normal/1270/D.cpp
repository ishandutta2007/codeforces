#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

map<ll, ll> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll n, k;
	cin >> n >> k;
	for(ll i = 1; i <= k + 1; i++) {
		cout << "? ";
		for(ll j = 1; j <= k + 1; j++)
			if(j != i) cout << j << " ";
		cout << endl;
		cout.flush();
		ll pos, val; cin >> pos >> val;
		s[val]++;
	}
	ll m;
	for(auto q : s) m = q.second;
	cout << "! " << m << endl;
	cout.flush();
}