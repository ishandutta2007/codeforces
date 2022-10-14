#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
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
const int maxn = 2e5 + 10, mlg = 17, mod = 1e9 + 7;
int n, x, a[maxn], ans;
void solve() {
	cin >> n >> x;
	ans = 1<<30;
	for(int t, i =1; i <= n; i++) {
		cin >> t;
		if(t>x) {
			ans = min(ans, 2);
		} else {
			ans = min(ans, (x+t-1)/t);
		}
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}