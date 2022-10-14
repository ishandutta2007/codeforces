//#pragma GCC optimize("trapv")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 2e5 + 55, mod = 1e9 + 7 , i2 = (mod+1)/2;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define find asdfjsadjf
ll n, a, b;
ll get(ll l, ll r) {
	return (2*a + (l-1)*b + (r-1)*b)*(r-l+1)/2;
}
ll find(ll l, ll t, ll m) {
	ll ans = l;
	for(ll z = 1ll<<25; z>>=1;)
		if(get(l, ans+z)<=t*m&&get(ans+z, ans+z)<=t) ans += z;
	if(get(l, ans)>t*m||get(ans, ans)>t) return -1;
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> n;
	for(int l, t, m, i = 0; i < n; i++) {
		cin >> l >> t >> m;
		cout << find(l, t, m) << '\n';
	}
}