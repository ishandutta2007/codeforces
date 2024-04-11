#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = (119 * (1 << 23) + 1);
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
	int n;
	multiset<ll> z;
	ll ans = 0;
	vvi u;
	cin >> n;
	u.resize(n);
	for (ll m, p, i = 0; i < n; i++) {
		cin >> m >> p;
		u[m].pb(p);
	}
	int le = n, b = 0;
	for (int i = n - 1; i >= 0; i--) {
		sort(all(u[i]));
		int tb = u[i].size();
		le -= u[i].size();
//		cout << i << " " << le << " " << b << "\n";
		for (auto j : u[i]) {
			z.insert(j);
			if (le + b < i){
				tb--;
				b++;
				ans += *z.begin();
				z.erase(z.begin());
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
}