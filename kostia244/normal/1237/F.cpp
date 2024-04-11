#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4.1,sse4.2,popcnt")
#include<bits/extc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 4020, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, C[maxn][maxn];
int dp[maxn][maxn], f[maxn];
vector<int> solve(vector<int> a) {
	int n = a.size();
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= n; j++) {
			(dp[i+1][j] += dp[i][j])%=mod;
			if(i+1<n && !a[i] && !a[i+1])
				(dp[i+2][j+1] += dp[i][j])%=mod;
		}
	vector<int> res;
	for(int i = 0; i <= n; i++) res.push_back(dp[n][i]);
	return res;
}
int nck(int n, int k) {
	if(n < k || n < 0) return 0;
	return C[n][k];
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j <= i; j++) 
			C[i][j] = (j ? (C[i-1][j-1] + C[i-1][j])%mod : 1);
	f[0] = 1;
	for(int i = 1; i < maxn; i++) f[i] = f[i-1]*1ll*i%mod;
	int t;
	cin >> n >> m >> t;
	vector<int> r(n), c(m);
	for(int a, b, x, y; t--;) {
		cin >> a >> b >> x >> y;a--,b--,x--,y--;
		r[a] = r[x] = 1;
		c[b] = c[y] = 1;
	}
	//for(auto i : c) cout << i << " "; cout << endl;
	int fr = count(all(r), 0);
	int fc = count(all(c), 0);
	r = solve(r);
	c = solve(c);
	//for(auto i : r) cout << i << " "; cout << endl;
	//for(int i = 0; i < 42; i++) cout << nck(n-i, i)<< ' ';cout<<endl;
	r.resize(max(n,m)+1, 0);
	c.resize(max(n,m)+1, 0);
	//cout << nck(fr, 0) << " " << nck(fc, 0) << endl;
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			int t = r[i]*1ll*c[j]%mod;
			t = t*1ll*nck(fc-2*j, i)%mod;
			t = t*1ll*nck(fr-2*i, j)%mod;
			t = t*1ll*f[i]%mod;
			t = t*1ll*f[j]%mod;
			ans =(ans +  t)%mod;
		}
	}
	cout << ans << '\n';
}