#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rnd(n) fixed << setprecision(n)

const int mod = 998244353, mod2 = 1e+7;

int main(){
    IOS;
	int n;
	ll mx = 0ll;
	cin >> n;
	vector<ll> a[n]; 
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		while(k--) {
			ll x;
			cin >> x;
			mx = max(mx, x);
			a[i].push_back(x);
		}
	}
	for (int i = 0; i < n; i++) {
		ll p = 0;
		for (ll x : a[i])
			p = max(p, x);
		ans += (mx - p) * (ll)a[i].size();
	}
	cout << ans;
    return 0;
}