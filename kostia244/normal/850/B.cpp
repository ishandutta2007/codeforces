#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 2e6 + 20, mlg = 18, mod = 1e9 + 7;
mt19937 rng(1022327586883856909ll);//chrono::steady_clock::now().time_since_epoch().count());
using namespace __gnu_pbds;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
ll n, x, y, a[maxn], b[maxn], ans = 1ll << 50;
int C = 1000004;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> x >> y;
	memset(a, 0, sizeof a);
	for(int t, i = 0; i < n; i++) cin >> t, a[t]++, b[t]+=t;
	for(int i = 1; i <= C; i++) {
		a[i] += a[i-1];
		b[i] += b[i-1];
	}
	for(int i = 2; i <= C; i++) {
		ll cur = 0;
		int sp = min(x/y, (ll)i-1);
		for(int j = 0; j <= C; j+=i) {
			cur += x*(a[min(j+i-sp-1, C)]-a[j]);
			ll cnt = a[min(j+i-1, C)] - a[min(j+i-sp-1, C)];
			ll sm = b[min(j+i-1, C)] - b[min(j+i-sp-1, C)];
			sm -= j*cnt;
			sm = i*cnt - sm;
			cur += sm*y;
//			cout << j+i-1 << " " << cur << "\n";
		}
//		cout << i << " " << cur << "\n";
		ans = min(ans, cur);
	}
	cout << ans;
	return 0;
}