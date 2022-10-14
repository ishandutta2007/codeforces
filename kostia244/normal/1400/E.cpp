#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,fma")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 5022, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dp[maxn][maxn];
void minq(int &a, int b) {
	a = min(a, b);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b;
	for(auto &i : a) cin >> i;
	b = a;b.push_back(0);
	sort(all(b));
	for(auto &i : a) i = lower_bound(all(b), i)-b.begin();
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = n-1; j; j--)
			minq(dp[i][j-1], dp[i][j]);
		for(int j = 0; j < b.size(); j++) {
			if(j+1 < n)
				minq(dp[i][j+1], dp[i][j] + b[j+1]-b[j]);
			if(a[i] >= j)
				minq(dp[i+1][j], dp[i][j] + (a[i] != j));
			//cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	int ans = (1<<30);
	for(int i = 0; i < b.size(); i++) ans= min(ans, dp[n][i]);
	cout << ans << '\n';
}