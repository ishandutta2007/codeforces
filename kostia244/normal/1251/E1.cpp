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
vvi dp;
vector<pair<ll, ll>> a;

ll f(ll i, ll l) {
	if(i == 1) {
//		cout << i << " " << l << "\n";
		if(l>a[i-1].first)
			return 0;
		return a[i-1].second;
	}
	if(dp[i][l]!=-1) return dp[i][l];
	dp[i][l] = 0;
	dp[i][l] = a[i-1].second + f(i-1, l);
	if(a[i-1].first < l)
		dp[i][l] = min(dp[i][l], f(i-1, l-1));
//	cout << i << " " << l << "\n";
	return dp[i][l];
}

void solve() {
	ll n;
	cin >> n;
	a.assign(n, {0, 0});
	for(auto & i : a) cin >> i.first >> i.second, i.second *= -1;
	sort(all(a));
	for(auto & i : a) i.second *= -1;
	dp.assign(n+10, vi(n+10, -1));
	cout << f(n, n) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
}