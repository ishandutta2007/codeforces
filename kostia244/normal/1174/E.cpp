#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const ll mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, dp[1000010][20][2];
ll f(int x, int y) {
	int t = 1<<x;
	if(y)t*=3;
	return (n/t);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	ll a = 0;
	while((1ll<<a)<=n)a++;
	a--;
	dp[0][a][0]=1;
	if(a&&3*(1<<(a-1))<=n)
		dp[0][a-1][1]=1;
	for(int i = 0; i < n; i++) {
		for(int l = 0; l < 20; l++) {
			for(int z = 0; z < 2; z++) {
				(dp[i+1][l][z] += (dp[i][l][z]*1ll*(f(l, z)-i-1))%mod)%=mod;
				if(l)
				(dp[i+1][l-1][z] += (dp[i][l][z]*1ll*(f(l-1, z)-f(l, z)))%mod)%=mod;
				if(z)
				(dp[i+1][l][z-1] += (dp[i][l][z]*1ll*(f(l, z-1)-f(l, z)))%mod)%=mod;
			}
		}
	}
	ll ans = 0;
	for(int l = 0; l < 20; l++) {
		for(int z = 0; z < 2; z++) {
			ans = (ans + dp[n-1][l][z]);
		}
	}
	cout << ans << "\n";
	return 0;
}