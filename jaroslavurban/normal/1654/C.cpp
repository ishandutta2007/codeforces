#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	vector<ll> a(n);
	for (ll& v : a) cin >> v;
	sort(a.begin(), a.end());
	ll sm = accumulate(a.begin(), a.end(), 0ll);
	multiset<ll> st(a.begin(), a.end());
	function<bool(ll)> slv = [&](ll x) {
		if (st.find(x) != st.end()) {
			st.erase(st.find(x));
			return true;
		}
		if (x == 1) return false;
		return slv(x / 2) && slv((x + 1) / 2);
	};
	if (slv(sm)) cout << "YES\n";
	else cout << "NO\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}