#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 3e5 + 55;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, a[maxn], ans, c[2];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	ll s = 0, mx;
	c[0]++;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = __builtin_popcountll(a[i]);
		s += a[i];
		ans += c[s&1]++;
	}
	for(int i = 1; i <= n; i++) {
		s = mx = 0;
		for(int j  = i; j <= n && j <= i+60; j++) {
			s += a[j];
			mx = max(mx, a[j]);
			if(!(s&1) && s-mx < mx) ans--;
		}
	}
	cout << ans;
}