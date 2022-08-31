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

const int N = 200005;
int dp[N][10];
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	for(int i = 0; i < 10; i++) dp[0][i] = 1;
	for(int i = 1; i < N; i++){
		for(int j = 0; j < 9; j++) dp[i][j] = dp[i - 1][j + 1];
		dp[i][9] = add(dp[i - 1][0], dp[i - 1][1]);
	}
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		int ans = 0;
		while(n){
			int d = n % 10;
			ans = add(ans, dp[m][d]);
			n /= 10;
		}
		cout << ans << "\n";
	}
}