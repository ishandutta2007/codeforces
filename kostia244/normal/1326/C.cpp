#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 5e3 + 22, mod = 998244353;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	vi a;
	cin >> n >> k;
	a.resize(n);
	for(auto &i : a) cin >> i;
	ll ans = 0, l = n-k+1, r = n;
	for(ll i = l; i <= r; i++) ans += i;
	ll enc = 0, cur = 0, c = 1;
	for(int i = 0; i < n; i++) {
		if(a[i]>=l) {
			if(enc) c = (c*(cur+1))%mod;
			enc = 1;
			cur = 0;
		} else
			cur++;
	}
	cout << ans << " " << c << '\n';
}