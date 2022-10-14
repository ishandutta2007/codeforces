#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
//using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = 1e9 + 7;
//using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll dp[33][4][4];
ll l, r;
int getbt(int x, int y) {
	return (x>>y)&1;
}
ll get(ll L, bool al=0, bool ar=0, bool bl = 0, bool br=0) {
	if(L == -1) return 1;
	ll ac = al+2*ar;
	ll bc = bl+2*br;
//	cout << L << ac << " " << bc << "\n";
	if(dp[L][ac][bc]!=-1) return dp[L][ac][bc];
	int lbit = getbt(l, L);
	int rbit = getbt(r, L);
	dp[L][ac][bc] = 0;
	for(int x = 0; x < 3; x++) {
		if(getbt(x, 0) < lbit && al == 0) continue;
		if(getbt(x, 0) > rbit && ar == 0) continue;
		if(getbt(x, 1) < lbit && bl == 0) continue;
		if(getbt(x, 1) > rbit && br == 0) continue;
		bool tal = al|(getbt(x, 0) > lbit);
		bool tar = ar|(getbt(x, 0) < rbit);

		bool tbl = bl|(getbt(x, 1) > lbit);
		bool tbr = br|(getbt(x, 1) < rbit);

		dp[L][ac][bc] += get(L-1, tal, tar, tbl, tbr);
	}
	return dp[L][ac][bc];
}
void solve() {

	memset(dp, -1, sizeof dp);
	cin >> l >> r;
	cout << get(29) << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}