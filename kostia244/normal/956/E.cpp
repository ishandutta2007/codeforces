#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 1e5 + 666, mlg = 18, mod =1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, l, r, h = 0;
vector<pair<int, int>> t;
int dp[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n >> l >> r;
	t.resize(n);
	for(auto &i : t) cin >> i.second, h += i.second;
	for(auto &i : t) cin >> i.first, i.first*=-1;
	sort(rall(t));
	l = h-l, r = h-r;
	swap(l, r);
	memset(dp, -0x3f, sizeof dp);
	dp[0] = 0;
	for(auto i : t) {
		for(int k = 10000-i.second; k>=0; k--) {
			dp[k+i.second] = max(dp[k+i.second], dp[k] + (i.first!=0)*(l <= k+i.second && k+i.second <= r));
		}
	}
	int ans = 0;
	for(int k = 10000; k; k--) {
		ans = max(ans, dp[k]);
	}
	cout << ans;

	return 0;
}