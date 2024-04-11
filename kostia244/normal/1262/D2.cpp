//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 7 * 17 * (1 << 23) + 1;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // order_of_key, find_by_order
vector<pi> q[300300];
int ans[300300];
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	vi a;
	vvi su, psum;
	cin >> n;
	a.resize(n);
	vector<pi> x;
	for(auto &i : a) cin >> i;
	for(int i = 0; i < n; i++)
		x.pb({a[i], -i});
	sort(rall(x));
	ordered_set s;
	cin >> m;
	int t, o;
	for(int i = 0; i < m; i++) {
		cin >> t >> o;
		q[t].pb({o, i});
	}
	for(int i = 0; i < n; i++) {
		s.insert({-x[i].second, x[i].first});
		for(auto j : q[i+1]) {
			ans[j.second] = s.find_by_order(j.first-1)->second;
		}
	}

	for(int i = 0; i < m; i++) cout << ans[i] <<"\n";
}