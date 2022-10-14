#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
const int maxn = 1e5 + 55;
void solve() {
	ll n, m;
	vi dp(40), nxt(40);
	cin >> n >> m;
	ll ans = 0;
	for(int i = 0; 1<<i <= n; i++) dp[i] = (min((2ll<<i)-1, n)-(1ll<<i)+1)%m;
	for(int cur = 1; cur < 33; cur++) {
	nxt = vi(40, 0);
	//cout << dp[0] << ":" << ans << ":";
	for(auto i : dp) ans = (ans+i)%m;
	for(int i = 0; 1<<i <= n; i++) {
		for(int j = i+1; 1<<j <= n; j++) {
			nxt[j] += dp[i] * (min((2ll<<j)-1, n)-(1ll<<j)+1)%m;
			//if(dp[i]) cout << i << " " << j << " " << dp[i] * (min((2ll<<j)-1, n)-(1ll<<j)+1)%m << '\n';
			nxt[j] %= m;
		}
	}
	dp = nxt;
	//for(auto i : dp) cout << i << " "; cout << '\n';
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}