#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 404, mod = (119<<23)+1, lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll eval(ll a, ll b, ll c) {
	return (a-b)*(a-b) + (b-c)*(b-c) + (a-c)*(a-c);
}
void solve() {
	vi a[3];
	vi x = {0, 1, 2};
	int n[3];
	for(int i = 0; i < 3; i++) cin >> n[i];
	for(int i = 0; i < 3; i++) {
		a[i].resize(n[i]);
		for(auto &j : a[i]) cin >> j;
		sort(all(a[i]));
	}
	ll ans = 1ll<<62;
	do {
		int u = x[1], v = x[2], w = x[0];
		for(int j = 0, k = 0, i = 0; i < n[w]; i++) {
			while(j+1<n[v]&&a[v][j+1]<=a[w][i]) j++;
			while(k+1<n[u]&&a[u][k]<a[v][j]) k++;
			ans = min(ans, eval(a[w][i], a[v][j], a[u][k]));
		}
	} while(next_permutation(all(x)));
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}