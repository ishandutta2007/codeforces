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
typedef double ld;
typedef pair<ll, ll> pi;
typedef pair<ld, ld> pd;
typedef map<int, int> mii;
typedef __V <ll> vi;
typedef __V <pi> vpi;
typedef __V <__V<int>> vvi;
typedef __V <__V<pi>> vvpi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, k, dp[100005], a, b;
int main() {
	doin();
	cin >> n >> k;
	dp[0] = 1;
	for (int i = 0; i <= 100000; i++) {
		if(i+k <= 100000)
			(dp[i + k] += dp[i] % mod) %= mod;
		(dp[i + 1] += dp[i] % mod)%=mod;
	}
	for (int i = 1; i <= 100000; i++)
		(dp[i] += dp[i - 1]) %= mod;
	while (n--) {
		cin >> a >> b;
		cout << fixed << (3ll*mod + dp[b] - dp[a - 1])%mod << "\n";
	}
	return 0;
}