#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<20, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, a[maxn], l[maxn], r[maxn];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		if(i == 1 || a[i-1] == a[i]) l[i] = i;
		else l[i] = l[i-1];
	}
	for(int i = n; i; i--) {
		if(i == n || a[i+1] == a[i]) r[i] = i;
		else r[i] = r[i+1];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = max(ans, min(abs(l[i]-i), abs(r[i]-i)));
		if(abs(l[i]-i) < abs(r[i]-i)) a[i] = a[l[i]];
		else a[i] = a[r[i]];
	}
	cout << ans << endl;
	for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
}