//#pragma GCC optimize("trapv")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 3555;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int t, n, m, k, a[maxn];
int go(int l, int r, int t) {
	int len = r-l+1-t, ans = 1<<30;
	for(int i = l; i+len-1 <= r; i++) {
		ans = min(ans, max(a[i], a[i+len-1]));
	}
//	cout << l << " " << r << " " << ans << "\n";
	return ans;
}
void solve() {
	cin >> n >> m >> k;
	k = min(k, m-1);
//	cout << m-1-k << "\n";
	for(int i = 1; i <= n; i++) cin >> a[i];//, cout << a[i] << " "; cout << "\n";
	int ans = 0;
	for(int i = 1; i+(n-k)-1 <= n; i++) {
		ans = max(ans, go(i, i+(n-k)-1, m-1-k));
	}
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--) solve();
}