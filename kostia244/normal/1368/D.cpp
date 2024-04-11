#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<19, mod = 1e9 + 7, i2 = (mod+1)/2;
int cnt[maxn], v[maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n,t ;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> t;
		for(int j = 0;j  < 30; j++) {
			cnt[j] += (t>>j)&1;
		}
	}
	for(int i = 0; i < 30; i++) v[0] += 1<<i, v[cnt[i]] -= 1<<i;
	ll ans = 0, r = 0;
	for(int i = 0; i < n; i++) {
		r += v[i];
		ans += r*r;
	}
	cout << ans << '\n';
	return 0;
}