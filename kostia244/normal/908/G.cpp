#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using ld = long double;
const int maxn = 2e5 + 55, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll dp[800][800][2];
ll D = 0;
string n;
ll f(ll i, ll j, ll c) {
	if(i==n.size()) return j==0;
	if(dp[i][j][c]!=-1) return dp[i][j][c];
	ll &ans = dp[i][j][c];
	ans = 0;
	for(ll d = 0; d <= 9; d++) {
		if(!c&&d>(n[i]-'0')) continue;
		ans = (ans + f(i+1, max(0ll, j-(d>=D)), c|(d<(n[i]-'0'))))%mod;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n;
	ll res = 0;
	for(int i = 1; i <= 10; i++) {
		ll pw = 1;
		D = i;
		memset(dp, -1, sizeof dp);
		for(int p = 0; p < n.size(); p++) {
			res = (res + pw*f(0, p+1, 0))%mod;
			pw = (pw*10ll)%mod;
		}
	}
	cout << res;
}