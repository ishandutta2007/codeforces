#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define pcnt(x) __builtin_popcount(x)
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1e5 + 3, mod = 1e9 + 7;
int C, B;
ll n, k;
int  a[maxn];
ll ans = 1;
vi t;
int check(ll d) {
	ll ans = 0;
	for(int i = 0; ans <= k && i < n; i++) if(a[i]%d) ans += d - (a[i]%d);
	return ans<=k;
}
ll get(ll l, ll r) {
	if(!check(l)) return 0;
	for(ll z = 2ll<<__lg(r-l+1); z>>=1;)
		if(l+z<r&&check(l+z)) l+=z;
	return l;
}
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	C = 2e6 + 55, B = (20000009000ll/(C*n)) + 55;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 2; i < C; i++) if(check(i)) ans = i;
	for(int i = 0; i < n; i++) {
		for(int j = 1; j < B && (a[i]/j)-1 > 0; j++) {
			t.pb((a[i]/j) - 1);
			t.pb((a[i]/j));
			t.pb((a[i]/j) + 1);
		}
	}
	sort(all(t));
	t.erase(unique(all(t)), t.end());
	int p = 2;
	for(auto i : t) {
		if(i<2) continue;
		ans = max(ans, get(p, i));
		p = i;
	}
	ans = max(ans, get(p, 1000000900000ll));
	cout << ans;
}