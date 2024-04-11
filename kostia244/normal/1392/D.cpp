#define SolutionToA 8bd96cf2dcad0ec7e9afce582c4bd1390179f4dec00841d13edc4420ce7de42b
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 3e5 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dp[maxn];
int solve(string s) {
	int n = s.size();
	dp[0] = 0;
	dp[1] = 1<<30;
	s = " " + s;
	for(int i = 2; i <= n; i++) {
		dp[i] = min(
			dp[i-2] + (s[i] == 'R') + (s[i-1] == 'L'),
			i > 2 ? dp[i-3] + (s[i] == 'R') + (s[i-2] == 'L') : 1<<30);
		if(i>3) {
			dp[i] = min(dp[i],
			dp[i-4] + (s[i-3] != 'R') + (s[i-2] != 'R') + (s[i-1] != 'L') + (s[i] != 'L'));
		}
	}
	return dp[n];
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
		int n;
		string s;
		cin >> n >> s;
		for(int i = 0; i < 4; i++) s += s[i];
		cout << min({solve(s.substr(0, n)), solve(s.substr(1, n)), solve(s.substr(2, n)), solve(s.substr(3, n))}) << '\n';
	}
}