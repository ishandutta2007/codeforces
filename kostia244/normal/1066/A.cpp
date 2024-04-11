#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1000000007ll;
ll get(ll n, ll x) {
	if(n < 0) return 0;
	return n/x;
}


int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	ll t, L, v, l, r, ans;
	cin >> t;
	while(t--) {
		cin >> L >> v >> l >> r;
		ans = get(L, v)-get(r, v)+get(l-1, v);
		cout << ans << "\n";
	}
}