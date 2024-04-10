#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))
const int N = 1e5 + 10, mod = 1e9 + 7;
int fact[N], invfact[N];
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (((ll) x) * y) % mod;}
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
void pre(){
	fact[0] = invfact[0] = 1;
	for(int i = 1;i < N; i++) fact[i] = mul(i, fact[i - 1]);
	invfact[N - 1] = inv(fact[N - 1]);
	for(int i = N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
	assert(invfact[1] == 1);
}
inline int C(int n, int k){
	if(n < k || k < 0) return 0;
	return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

int dp[N];
char s[N];
int main(){
	pre();
	int n, k;
	sd(n); sd(k);
	scanf("%s", s);
	dp[0] = C(n - 2, k - 1);
	int pwr = 1;

	for(int i = 1; i <= n; i++){
		pwr = mul(pwr, 10);
		int x = mul(C(n - 2 - i, k - 1), pwr);
		dp[i] = add(dp[i - 1], x);
	}
	int ans = 0;
	pwr = 1;
	for(int i = n; i >= 1; i--){
		int v = s[i - 1] - '0';
		if(i <= n - 1){
			ans = add(ans, mul(v, dp[n - 1 - i]));
		}
		ans = add(ans, mul(v, mul(C(i - 1, k), pwr)));
		pwr = mul(pwr, 10);
	}
	printf("%d\n", ans);
}