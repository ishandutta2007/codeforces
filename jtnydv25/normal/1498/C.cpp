#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#endif

const int mod = 1e9 + 7;

inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
const int N = 1 << 10;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int k, n;
		cin >> n >> k;
		vector<vector<int>> dp(k + 1, vector<int>(n + 2));
		for(int i = 0; i <= n; i++) dp[1][i] = 1;
		for(int i = 2; i <= k; i++){
			dp[i][n] = 1;
			for(int j = n - 1; j >= 0; j--){
				dp[i][j] = add(dp[i][j + 1], dp[i - 1][n - j]);
			}
		}
		cout << dp[k][0] << endl;
	}
}