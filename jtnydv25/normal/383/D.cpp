#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
const int N = 1005, mod = 1e9 + 7;

#define ll long long
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
const int M = 21000;
int OFFSET = N * 10 + 5;
int dp[N][M], a[N];
int main(){
	int n;
	cin >> n;
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		for(int j = 0; j < M; j++){
			if(dp[i - 1][j]){
				if(j + a[i] < M)
					dp[i][j + a[i]] = add(dp[i - 1][j], dp[i][j + a[i]]);
				if(j - a[i] >= 0) dp[i][j - a[i]] = add(dp[i][j - a[i]], dp[i - 1][j]);
			}
		}
		dp[i][a[i] + OFFSET] = add(dp[i][a[i] + OFFSET], 1);
		dp[i][OFFSET - a[i]] = add(dp[i][OFFSET - a[i]], 1);
		ans += dp[i][OFFSET];
		ans %= mod;	
	}
	printf("%lld\n", ans);
}