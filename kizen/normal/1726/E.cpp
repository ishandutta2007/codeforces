#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

const int mod = 998244353;

int pw(int x, int y, int mod){
    if(!y) return 1;
    if(y % 2) return pw(x, y - 1, mod) * x % mod;
    int val = pw(x, y / 2, mod);
    return val * val % mod;
}

const int NS = (int)1e6 + 4;
int fact[NS], inv[NS];
int ncr(int n, int r){
	if(n < r) return 0;

    if(!fact[0]){
        for(int i = 0; i < NS; ++i){
            if(!i) fact[i] = 1;
            else fact[i] = i * fact[i - 1] % mod;
        }
        inv[NS - 1] = pw(fact[NS - 1], mod - 2, mod);
        for(int i = NS - 2; i >= 0; --i){
            inv[i] = inv[i + 1] * (i + 1) % mod;
        }
    }
    return fact[n] * inv[r] % mod * inv[n - r] % mod;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;

	while(t--){
		int n; cin >> n;

		vector<int> dp(n + 4);
		dp[0] = dp[1] = 1;
		for(int i = 2; i < (int)dp.size(); ++i){
			dp[i] = (dp[i - 1] + (i - 1) * dp[i - 2]) % mod;
		}

		vector<int> ft(n * 2 + 4);
		ft[0] = ft[1] = 1;
		for(int i = 2; i < (int)ft.size(); ++i){
			ft[i] = ft[i - 2] * i % mod;
		}

		int ans = 0;

		for(int i = 0; 4 * i <= n; ++i){
			int now = ncr(n - 2 * i, 2 * i);

			if(i) now = (now * ft[2 * i - 1]) % mod;
			now = (now * pw(2, i, mod)) % mod;
			now = (now * dp[n - 4 * i]) % mod;

			ans = (ans + now) % mod;
		}

		cout << ans << '\n';
	}
	
	return 0;
}