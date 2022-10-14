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
ll n, a[maxn], pref[maxn], suf[maxn], op[maxn], os[maxn], s[maxn];
ll sum(ll l, ll r){return (r?s[r-1]:0) - (l?s[l-1]:0);}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i], s[i] = a[i] + (i?s[i-1]:0);
	for(int i = 0; i < n; i++) {
		pref[i] = -(1ll<<60);
		for(int j = 0; j <= i; j++) {
			pref[i] = max(pref[i], sum(0, j) - sum(j, i));
			if(pref[i] == sum(0, j) - sum(j, i)) op[i] = j;
		}
	}
	for(int i = 0; i < n; i++) {
		suf[i] = -(1ll<<60);
		for(int j = i; j <= n; j++) {
			suf[i] = max(suf[i], sum(i, j) - sum(j, n));
			if(suf[i] == sum(i, j) - sum(j, n)) os[i] = j;
		}
	}
	ll ans = -(1ll<<60), x = -1;
	for(int i = 0; i < n; i++) {
		ll t = pref[i] + suf[i];
		if(ans < t) ans = t, x = i;
	}
	cout << op[x] << " " << x << " " << os[x] << '\n';
}