#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 5e2 + 10, mlg = 17, mod = 1e9 + 7;
int a[maxn], n;
ll ans = 1ll<<60;
inline void go(ll x) {
	if(x<2) return;
	ll t = 0, z;
	for(int i = 1; i <= n; i++) {
		if(x-1>a[i]) return;
		z = a[i]/x;
		if(a[i]%x) {
			if(z+(a[i]%x)<x-1) return;
			z++;
		}
		t += z;
	}
	ans = min(ans, t);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 2; i < 32000; i++) go(i);
	for(int i = 1; i < 32000; i++) {
		if(a[1]%i==0) {
		go(a[1]/i);
		go((a[1]/i) - 1);
		}
		go((a[1]/i) + 1);
	}
	cout << ans;
	return 0;
}