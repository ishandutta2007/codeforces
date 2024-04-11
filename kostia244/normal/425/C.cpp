#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/STACK:26777216")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
//const ll mod = 1e9 + 7;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, s, e, a[100100], b[100100], dp[100010][310];
set<int> ap[100100];
set<int> bp[100100];
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> m >> s >> e;
	for(int i = 1; i <= n; i++) cin >> a[i], ap[a[i]].insert(i);
	for(int i = 1; i <= m; i++) cin >> b[i], bp[b[i]].insert(i);
	int ans = 0;
	memset(dp, 0x2f, sizeof dp);
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= 301 && j <= i; j++) {
			dp[i][j] = dp[i-1][j];
			auto it = bp[a[i]].upper_bound(dp[i-1][j-1]);
			if(j&&it!=bp[a[i]].end()) {
				dp[i][j] = min(dp[i][j], *it);
			}
			if(e*j + i + dp[i][j] <= s)
				ans = max(ans, j);
		}
	}
	cout << ans;
}