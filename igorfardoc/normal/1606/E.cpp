#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 998244353;
int fact[1000];
int rfact[1000];

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

int c(int n, int k) {
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
    int n, x;
    cin >> n >> x;
    vvi dp(n + 1, vi(x + 1, 0));
    for(int i = 0; i <= n; i++) {
    	for(int j = 0; j <= x; j++) {
    		if(j == 0) {
    			continue;
    		}
    		if(i == 0) {
    			dp[i][j] = 1;
    			continue;
    		}
    		if(i == 1) {
    			dp[i][j] = 0;
    			continue;
    		}
    		if(i > j) {
    			dp[i][j] = bin_pow(j, i);
    			continue;
    		}
    		for(int k = 0; k <= i; k++) {
    			if(k == i - 1) {
    				continue;
    			}
    			dp[i][j] = ((ll)bin_pow(i - 1, k) * dp[i - k][j - (i - 1)] % mod * c(i, k) + dp[i][j]) % mod;
    		}
    	}
    }
    //cout << dp[3][1] << endl;
    cout << dp[n][x];
}