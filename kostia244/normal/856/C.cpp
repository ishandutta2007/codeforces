#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<11, maxa = 1e7 + 333, mod = 119<<23|1;
int dp[maxn][maxn][11], ep[maxn][maxn][11], fact[maxn];
int eval(int x) {
	int f = 0, s = 1;
	while(x) {
		f += (x%10)*s;
		s *= -1;
		x /= 10;
	}
	return (11 + f%11)%11;
}
inline void add(int &a, int b) {
	a = a+b >= mod ? a+b-mod : a+b;
}
void solve() {
	int n;
	cin >> n;
	vector<int> a[2];
	for(int t,  i = 0; i < n; i++) {
		cin >> t;
		a[to_string(t).size()&1].pb(eval(t));
	}
	auto f = a[1];
	for(int i = 0; i <= f.size(); i++)
		for(int j = 0; j <= f.size(); j++)
			for(int k = 0; k < 11; k++)
				dp[i][j][k] = 0;
	dp[0][0][0] = 1;
	for(int i = 0; i < f.size(); i++) {
		for(int j = 0; j < f.size(); j++) {
			for(int k = 0; k < 11; k++) {
				add(dp[i+1][j][(k+f[i])%11], dp[i][j][k]);
				add(dp[i+1][j+1][(k+11-f[i])%11], dp[i][j][k]);
			}
		}
	}
	vector<int> sola(11);
	for(int i = 0; i < 11; i++) {
		sola[i] = dp[f.size()][(f.size()+1)/2][i];
		//cout << f.size() << " " << (f.size()+1)/2 << " " << i << '\n';
		sola[i] = sola[i] * 1ll * fact[f.size()/2] % mod;
		sola[i] = sola[i] * 1ll * fact[(f.size()+1)/2] % mod;
	}
	//cout << sola[10] << '\n';
	f = a[0];
	for(int i = 0; i <= f.size(); i++)
		for(int j = 0; j <= f.size(); j++)
			for(int k = 0; k < 11; k++)
				ep[i][j][k] = 0;
	ep[0][0][0] = 1;
	for(int i = 0; i < f.size(); i++) {
		for(int j = 0; j < f.size(); j++) {
			for(int k = 0; k < 11; k++) {
				add(ep[i+1][j][(k+f[i])%11], ep[i][j][k]);
				add(ep[i+1][j+1][(k+11-f[i])%11], ep[i][j][k]);
			}
		}
	}
	vector<int> solb(11);
	for(int j = 0; j <= f.size(); j++) {
		int t = 1;
		for(int i = 1 + a[1].size()/2; i < 1+(a[1].size()/2)+j; i++) t = t*1ll*i%mod;
		for(int i = (a[1].size()+1)/2; i < ((a[1].size()+1)/2)+(f.size()-j); i++) t = t*1ll*i%mod;
		//cout << j << " " << t << '\n';
		for(int r = 0; r < 11; r++)
			add(solb[r], ep[f.size()][j][r]*1ll*t%mod);
	}
	//for(int i = 0; i < 11; i++) cout << solb[i] << ' '; cout << '\n';
	int ans = 0;
	for(int i = 0; i < 11; i++) add(ans, sola[i]*1ll*solb[(11-i)%11]%mod);
	cout << ans << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	fact[0] = 1;
	for(int i = 1; i < maxn; i++) fact[i] = fact[i-1] * 1ll * i % mod;
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}