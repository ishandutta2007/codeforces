#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

ll worksOd(ll x, ll n, ll k) {
	ll a = x, b = x + 1, ans = 0;
	while(a <= n) {
		ans += min(b, n + 1) - a;
		a *= 2;
		b *= 2;
	}
	return ans;
}

ll worksEv(ll x, ll n, ll k) {
	if(x == 0) return 1;
	return worksOd(x, n, k) + worksOd(x + 1, n, k) >= k;
}

ll bSearchOd(ll l, ll r, ll n, ll k) {
	if(l == r) return l;
	ll m = (l + r + 1) / 2;
	return worksOd(2 * m - 1, n, k) >= k ? bSearchOd(m, r, n, k) : bSearchOd(l, m - 1, n, k);
}

ll bSearchEv(ll l, ll r, ll n, ll k) {
	if(l == r) return l;
	ll m = (l + r + 1) / 2;
	return worksEv(2 * m, n, k) ? bSearchEv(m, r, n, k) : bSearchEv(l, m - 1, n, k);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, k;
	cin >> n >> k;
	ll ev = 2 * bSearchEv(0, n, n, k), od = 2 * bSearchOd(1, n, n, k) - 1;	
	cout << max(ev, od) << endl;
}