#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
const int mod = 998244353;
int fact[1000], rfact[1000];

int bin_pow(int a, int b) {
	if(b == 0) return 1;
	int res = bin_pow(a, b >> 1);
	res = (ll)res * res % mod;
	if(b & 1) res = (ll)res * a % mod;
	return res;
}

int obr(int a) {return bin_pow(a, mod - 2);}

int c(int n, int k) {
	if(n < 0 || k < 0 || k > n) return 0;
	int res = (ll)fact[n] * rfact[k] % mod;
	res = (ll)res * rfact[n - k] % mod;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, k;
	cin >> n >> k;
	fact[0] = 1;
	for(int i = 1; i < 1000; i++) {
		fact[i] = (ll)fact[i - 1] * i % mod;
		rfact[i] = obr(fact[i]);
	}
	rfact[0] = rfact[1];
	vvi dp(n, vi(k + 1, 0));
	dp[0].assign(k + 1, 1);
	for(int i = 1; i < n; i++) {
		for(int j = 1; j <= k; j++) {
			for(int am = 0; am <= i; am++) {
				dp[i][j] = (dp[i][j] + (ll)c(n - 1 - i + am, am) * dp[i - am][j - 1] % mod * bin_pow(k - j + 1, am * (am - 1) / 2 + am * (i - am)) % mod) % mod;
			}
		}
	}
	//cout << dp[2][1] << endl;
	cout << dp[n - 1][k];
}