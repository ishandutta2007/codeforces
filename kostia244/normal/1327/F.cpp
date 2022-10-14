#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using ld = long double;
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
//using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1<<19, mod = (119<<23)+1, lg = 19;
int n, k, m, dp[maxn], pref[maxn], forced[maxn], fend[maxn];
vector<array<int, 3>> q;
int solve(int K) {
	memset(fend, 0, sizeof fend);
	memset(forced, 0, sizeof forced);
	memset(dp, 0, sizeof dp);
	memset(pref, 0, sizeof pref);
	for(auto i : q) {
		if((i[2]>>K)&1) {
			forced[i[0]]++;
			forced[i[1]+1]--;
		} else {
			fend[i[1]+1] = max(fend[i[1]+1], i[0]);
		}
	}
	for(int i = 1; i <= n+1; i++) {
		fend[i] = max(fend[i], fend[i-1]);
		forced[i] += forced[i-1];
	}
	dp[0] = pref[0] = 1;
	for(int i = 1; i <= n; i++) {
		pref[i] = pref[i-1];
		if(forced[i]) continue;
		if(fend[i]>=1) dp[i] = (mod + pref[i] - pref[fend[i]-1])%mod;
		else dp[i] = pref[i];
		pref[i] += dp[i];
		if(pref[i] >= mod) pref[i] -= mod;
	}
	int ans = 0;
	for(int i = n; i >= fend[n+1]; i--) {
		ans += dp[i];
		if(ans >= mod) ans -= mod;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> m;
	q.resize(m);
	for(auto &i : q) cin >> i[0] >> i[1] >> i[2];
	ll ans = 1;
	for(int i = 0; i < k; i++) ans = ans*1ll*solve(i)%mod;
	cout << ans;
	return 0;
}