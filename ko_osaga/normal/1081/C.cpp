#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 2005;
const int mod = 998244353;

int dp[MAXN][MAXN];
int n, m, k;

int f(int n, int k){
	if(k < 0) return 0;
	if(n == 1) return k == 0;
	if(~dp[n][k]) return dp[n][k];
	lint ret = 1ll * f(n - 1, k - 1) * (m - 1) + f(n - 1, k);
	return dp[n][k] = ret % mod;
}

int main(){
	cin >> n >> m >> k;
	memset(dp, -1, sizeof(dp));
	cout << 1ll * f(n, k) * m % mod << endl;
}