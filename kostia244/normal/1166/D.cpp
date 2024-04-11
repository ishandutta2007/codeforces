#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<20, mod = 1e9 + 7, rt = 565042129, i2 = (mod+1)/2;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll x[maxn], r[maxn];
void solve() {
	ll a, b, m, k, sm = 0, pref = 0;
	cin >> a >> b >> m;
	r[0] = x[0] = pref = a;
	for(k = 1; pref < b;k++) {
		r[k] = 1;
		x[k] = pref + r[k];
		pref += x[k];
	}
	b -= x[k-1];
	for(int i = 1; i < k; i++) {
		ll t = 1ll<<max(0ll, k-i-2);
		r[i] += min(b/t, m-1);
		b -= t*min(b/t, m-1);
	}
	r[0] = x[0] = pref = a;
	for(int i = 1; i < k; i++) {
		x[i] = pref + r[i];
		pref += x[i];
	}
	if(b) {cout << "-1\n";return;}
	cout << k << " ";
	for(int i = 0; i < k; i++) cout << x[i] << " ";cout << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}