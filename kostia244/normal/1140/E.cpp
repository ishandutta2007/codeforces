#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 2e5 + 33, mod = (119 << 23) + 1;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
ll n, k,dp[maxn][2];
vi a[2];
ll bp(ll a, ll p) {
	ll r = 1;
	while(p) {
		if(p&1) r = (r*a)%mod;
		p>>=1, a = (a*a)%mod;
	}
	return r;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	a[0].pb(0), a[1].pb(0);
	for(int t, i = 0; i < n; i++)
		cin >> t, a[i&1].pb(t);
	ll ans = 1;
	ll inv = bp(k-1, mod-2);
	for(int z = 0; z < 2; z++) {
	ll lst = -33;
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	for(int i = 1; i < a[z].size(); i++) {
		if(a[z][i]==-1) {
			dp[i][0] = (dp[i-1][1]*(k-1) + dp[i-1][0]*(k-2+(i==1)))%mod;
			dp[i][1] = dp[i-1][0]*(!i||a[z][i-1]!=lst);
		} else {
			if(lst==a[z][i]) {
				(ans *= dp[i-1][0])%=mod;
			} else {
				(ans *= (dp[i-1][1] + ((dp[i-1][0]*inv%mod)*(k-2+(i==1)))%mod)%mod)%=mod;
			}
			dp[i][0] = 0;
			dp[i][1] = 1;
			lst = a[z][i];
		}
//		cout << a[z][i] << " " << dp[i][0] << " " << dp[i][1] << "\n";
	}
//	cout << "\n";
	if(a[z].back()==-1) {
//		cout << a[z].size()-1 << " " << dp[a[z].size()-1][0] << " " << dp[a[z].size()-1][1] << "gg\n";
		(ans *= dp[a[z].size()-1][0] + dp[a[z].size()-1][1])%=mod;
	}
	}
	cout << ans << "\n";
}