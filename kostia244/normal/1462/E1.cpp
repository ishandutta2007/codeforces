#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 1<<18, mod = 1e9 + 7;
int n, m, k, a[maxn];
ll fact[maxn], inv[maxn];
ll nc2(ll n) {
	return n*(n-1)/2;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;cin >> t;
	while(t--) {
		cin >> n; m = 3, k = 2;
		for(int i = 1; i <= n; i++) cin >> a[i];
		sort(a+1, a+n+1);
		ll ans = 0;
		for(int j = 1, i = 1; i <= n; i++) {
			while(a[i]-a[j] > k) j++;
			ans = (ans + nc2(i-j));
		}
		cout << ans << '\n';
	}
}