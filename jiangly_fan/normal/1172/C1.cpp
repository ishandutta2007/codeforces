//Author: Heltion
//Date: 2019-06-06
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
constexpr int maxn = 240000;
constexpr int maxm = 3200;
LL power(LL a, LL r){
	LL res = 1;
	for(; r; r >>= 1, a = a * a % mod)
		if(r & 1) res = res * a % mod;
	return res;
}
LL dp[maxm][maxm];
LL a[maxn], w[maxn];
void add(LL &x, LL y){
	x += y;
	if(x >= mod) x -= mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout<<fixed<<setprecision(12);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	for(int i = 1; i <= n; i += 1) cin >> w[i];
	LL sw[2] = {0, 0};
	for(int i = 1; i <= n; i += 1) sw[a[i]] += w[i];
	dp[0][0] = 1;
	for(int k = 0; k < m; k += 1)
		for(int i = 0; i <= k; i += 1){
			int j = k - i;
			if(not dp[i][j]) continue;
			LL inv = power(sw[0] + sw[1] + i - j, mod - 2);
			add(dp[i + 1][j], (sw[1] + i) * dp[i][j] % mod * inv % mod);
			add(dp[i][j + 1], (sw[0] - j) * dp[i][j] % mod * inv % mod);
		}
	LL ssw[2] = {0, 0};
	for(int i = 0; i <= m; i += 1){
		int j = m - i;
		if(dp[i][j] == 0) continue;
		add(ssw[1], dp[i][j] * i % mod);
		add(ssw[0], dp[i][j] * j % mod);
	}
	ssw[0] = ssw[0] * power(sw[0], mod - 2) % mod;
	ssw[1] = ssw[1] * power(sw[1], mod - 2) % mod;
	for(int i = 1; i <= n; i += 1)
		if(a[i] == 1) cout << (ssw[1] + 1) * w[i] % mod << "\n";
		else cout << (mod - ssw[0] + 1) * w[i] % mod << "\n";
	return 0;
}