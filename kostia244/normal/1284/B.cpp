#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 88, mod = 1e9 + 7;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vi mn, mx;
	ll n, g = 0;
	cin >> n;
	vi a, b;
	for(ll l, t, i = 0; i < n; i++) {
		cin >> l;
		ll p = 1e9, mx = -1, mn = 1e9, vo = 0;
		while(l--) {
			cin >> t;
			mx = max(mx, t);
			mn = min(mn, t);
			if(p<t) {
				vo = 1;
			}
			p = t;
		}
		if(vo) g++;
		else {
			a.pb(mn);
			b.pb(mx);
		}
	}
	sort(all(a));
	sort(all(b));
	ll j = 0;
	ll ans = 0;
	for(auto i : b) {
		while(j < a.size() && a[j] < i) j++;
		ans += j;
	}
	ans += g*g;
	ans += (n-g)*g*2;
	cout << ans << "\n";
}