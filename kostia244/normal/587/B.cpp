#pragma GCC optimize("trapv")
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
const int maxn = 1e6 + 33, mod = 1e9 + 7;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
ll n, k, l, dp[maxn], sm;
vpi a;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l >> k;
	a.resize(n);
	int p = 0;
	for(auto &i : a) cin >> i.first, i.second = ++p;
	sort(all(a));
	memset(dp, 0, sizeof dp);
	ll ans = 0;
	for(int i = 1; i <= k; i++) {
		sm = 0;
		int k = 0;
//		cout << i << ":\n";
		for(int j = 1;j <= n; j++) {
			while(k < n && a[k].first <= a[j-1].first) {
				sm += dp[k+1];
				if(sm>=mod) sm-=mod;
				k++;
			}
			if((i-1)*n + a[j-1].second > l) continue;
			dp[j] = sm;
			if(i==1) dp[j] = 1;
//			cout << n-k+1 << " " << dp[j] << "\n";
			ll t = 1 + (l - ((i-1)*n + a[j-1].second))/n;
			t%=mod;
			ans += (dp[j]*t)%mod;
			if(ans>=mod) ans-=mod;
		}
	}
	cout << ans;
}