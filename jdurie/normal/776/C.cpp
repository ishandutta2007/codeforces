#pragma GCC target("avx2")
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin>>x;
#define F(i, l, r) for (ll i=l i<(r); ++i)
#define all(a) begin(a), end(a)
#define K first
#define V second

int main() {
	cin.tie(0)->sync_with_stdio(0);
	G(n) G(k)
	map<ll, ll> ct;
	ct[0]++; ll cur = 0, ans = 0;
	while(n--) {
		G(x) cur += x;
		ll c = 1;
		while(1) {
			ans += ct[cur - c];
			c *= k;
			if(abs(k) == 1 && c == 1) break;
			if(c >= 1e15) break;
		}
		ct[cur]++;
	}
	cout << ans << '\n';
}