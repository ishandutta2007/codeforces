#pragma GCC target ("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < r; i++)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	G(T)
	while(T--) {
		G(n)
		vector<ll> mnidx, mxidx;
		for (ll i = 1; i <= n - 1; i+=2) {
			cout << "? " << i << ' ' << i + 1 << endl;
			char c; cin >> c;
			mnidx.push_back(i + (c == '>'));
			mxidx.push_back(i + !(c == '>'));
		}
		if (n&1) { mnidx.push_back(n); mxidx.push_back(n); }
		ll mn = mnidx[0], mx = mxidx[0];
		for (ll i = 1; i < mnidx.size(); i++) {
			cout << "? " << mn << ' ' << mnidx[i] << endl;
			char c; cin >> c;
			if (c == '>') mn = mnidx[i];
		}
		for (ll i = 1; i < mxidx.size(); i++) {
			cout << "? " << mx << ' ' << mxidx[i] << endl;
			char c; cin >> c;
			if (c == '<') mx = mxidx[i];
		}
		cout << "! " << mn << ' ' << mx << endl;
	}	
}