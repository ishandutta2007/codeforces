#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 3e3 + 55, mlg = 20, mod = 1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int n;
map<int, vi> a;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	oset t;
	int n;
	cin >> n;
	for(int x, y, i = 0; i < n; i++) {
		cin >> x >> y;
		a[-y].pb(x);
	}
	ll ans = 0;
	for(auto i : a) {
		ll lst = 0, l = 0, r;
		sort(all(i.second));
		i.second.erase(unique(all(i.second)), i.second.end());
		for(auto j : i.second) {
			t.insert(j);
		}
		for(auto j : i.second) {
			l = t.order_of_key(j+1);
			r = t.size()-t.order_of_key(j);
//			cout << l << " " << r << "\n";
			ans += (l-lst)*r;
			lst = l;
		}
//		cout << -i.first << "\n";
	}
	cout << ans;
	return 0;
}