#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1<<18, mod = 1e9 + 7;
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // order_of_key, find_by_order
int a[maxn], n;
ll check(int x) {
	ordered_set f;
	ll cnt = 0;
	f.insert({0, 0});
	for(int p = 0, i = 1; i <= n; i++) {
		int t = a[i] >= x ? 1 : -1;
		//cout << t << " ";
		p += t;
		f.insert({p, i});
		cnt += f.order_of_key({p, -1});
	}
	return cnt;
}
void solve() {
	int k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	ll t = check(k);
	ll y = 0, x = 0;
	for(int i = 1; i <= n; i++) y += a[i] >= k, x += a[i] == k;
	cout << (x && (t > y || x == n) ? "yes\n": "no\n");
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
}