#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000000007;
int fact[1000], rfact[1000];

int bin_pow(int a, int b) {
	if(b == 0) {
		return 1;
	}
	int res = bin_pow(a, b >> 1);
	res = ((ll)res * res) % mod;
	if(b & 1) {
		res = ((ll)res * a) % mod;
	}
	return res;
}

int obr(int a) {
	return bin_pow(a, mod - 2);
}

int c1(int n, int k) {
	if(n < 0 || k < 0 || k > n) {
		return 0;
	}
	int res = ((ll)fact[n] * rfact[k]) % mod;
	res = ((ll)res * rfact[n - k]) % mod;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    fact[0] = 1;
    for(int i = 1; i < 1000; i++) {
    	fact[i] = ((ll)fact[i - 1] * i) % mod;
    	rfact[i] = obr(fact[i]);
    }
    rfact[0] = rfact[1];
    int n, k;
    cin >> n >> k;
    vvi dp(n + 1, vi(n + 1));
    for(int r = 0; r <= n; r++) {
    	for(int c = 0; c <= n; c++) {
    		if(r == 0) {
    			continue;
    		}
    		if(c == 0) {
    			dp[r][c] = bin_pow(((bin_pow(k, n) - bin_pow(k - 1, n) + mod) % mod), r);
    			continue;
    		}
    		if(r == 1) {
    			dp[r][c] = bin_pow(k, n - c);
    			continue;
    		}
    		int here = ((ll)bin_pow(k - 1, c) * ((bin_pow(k, n - c) - bin_pow(k - 1, n - c) + mod) % mod)) % mod;
    		here = ((ll)here * dp[r - 1][c]) % mod;
    		for(int i = 1; i <= c; i++) {
    			int here1 = ((ll)c1(c, i) * bin_pow(k - 1, c - i)) % mod;
    			here1 = ((ll)here1 * dp[r - 1][c - i]) % mod;
    			here = (here + (ll)here1 * bin_pow(k, n - c)) % mod;
    		}
    		dp[r][c] = here;
    	}
    }
    cout << dp[n][n];


}