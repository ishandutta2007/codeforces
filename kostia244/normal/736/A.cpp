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
const int maxn = 2e5 + 55, mlg = 18, mod =1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, la, lb, dp[300];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	dp[0] = 1;
	dp[1] = 2;
	cin >> n;
	for(int i = 2; i <= 100; i++) {
		dp[i] = dp[i-1]+dp[i-2];
		if(dp[i]>n) return cout << i-1, 0;
	}
	return 0;
}