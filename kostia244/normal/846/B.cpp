#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 2e5 + 55, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, m, k;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> m;
	vi T;
	T.resize(k);
	ll s = 0;
	for(auto &i : T) cin >> i, s += i;
	sort(all(T));
	ll ans = 0;
	for(int i = 0; i <= n; i++) {
		ll t = m - s*i;
		if(t<0) break;
		ll tans = (k+1)*i;
		for(int x, j = 0; j < T.size(); j++) {
			x = min(t/T[j], n-i);
			tans += x;
			t -= x*1ll*T[j];
		}
		if(t>=0)
		ans = max(ans ,tans);
	}
	cout << ans;
}