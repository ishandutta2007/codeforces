#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
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
const int maxn = 1<<18, mod = 1e9 + 7, lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	int n;
	cin >> n;
	vi a(n);
	for(auto &i : a) cin >> i;
	ll mn = 0, r = 0;
	for(int i = 1; i < n; i++) {
		if(a[i] < a[i-1])
			r = max(r, 64ll-__builtin_clzll(a[i-1]-a[i])), a[i] = a[i-1];
	}
	cout << r << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}