#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 2020, mod = 1e9 + 7;
int n, C[maxn][maxn];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j <= i; j++)
			if(!j) C[i][j] = 1;
			else (C[i][j] = C[i-1][j-1] + C[i-1][j])%=mod;
	cin >> n;
	int t, c = 0, ans = 1;
	while(n--) {
		cin >> t;
		ans = ans * 1ll * C[c + t - 1][t - 1] % mod;
		c += t;
	}
	cout << ans << endl;
}