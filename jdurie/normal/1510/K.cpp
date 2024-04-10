#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin>>x;
#define F(i,l, r) for (ll i=(l); i<(r); ++i)
#define all(x) begin(x), end(x)
#define K first
#define V second
#define N 2020

ll n, a[N], b[N];

ll solve(ll x) {
	copy_n(a, 2 * n, b);
	if(x) F(i, 0, n) swap(b[2 * i], b[2 * i + 1]);
	ll ans = x;
	while(ans < N && !is_sorted(b, b + 2 * n)) {
		if(ans % 2 == x % 2) F(i, 0, n) swap(b[i], b[i + n]);
		else F(i, 0, n) swap(b[2 * i], b[2 * i + 1]);
		ans++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	F(i, 0, 2 * n) cin >> a[i];
	ll ans = min(solve(0), solve(1));
	cout << (ans == N ? -1 : ans) << '\n';
}