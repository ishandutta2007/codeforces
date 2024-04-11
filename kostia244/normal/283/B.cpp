#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCAL
//  freopen("input.txt", "r", stdin);
#endif
}
typedef long long ll;
typedef ll _I;
typedef double ld;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, t, d = 0;
bool k = false;
vi a, dp[2];
set<int> v;
ll dfs(ll x, bool c = 1) {
	if (x > n || x <= 0)
		return 0;
	if (dp[c][x])
		return dp[c][x];
	dp[c][x] = -1;
	ll t = dfs(x + (c ? a[x] : -a[x]), c ^ 1);
	return (t == -1 ? (dp[c][x] = -1) : (dp[c][x] = t + a[x]));
}

int main() {
	doin();
	cin >> n;
	a.resize(n + 1);
	dp[0].resize(n + 1, 0);
	dp[1].resize(n + 1, 0);
	for (ll i = 2; i <= n; i++) {
		cin >> a[i];
	}
	for (ll i = 1; i < n; i++) {
		a[1] = i;
		dp[1][1] = dp[1][0] = 0;
		ll t = dfs(1, 1);
		cout << fixed << t << "\n";
	}
	return 0;
}