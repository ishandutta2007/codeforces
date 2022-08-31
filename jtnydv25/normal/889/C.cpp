#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e6 + 10, mod = 1e9 + 7;
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

int f[N], pf[N], g[N];
int main(){
	pre();
	int n, k;
	cin >> n >> k;
	for(int i = 0; i <= n; i++){
		if(i <= k) f[i] = fact[i];
		else{
			f[i] = mul(fact[i - 1], sub(pf[i - 1], pf[i - k - 1]));
		}
		if(i == 0) pf[i] = 1;
		else pf[i] = add(pf[i - 1], mul(f[i], invfact[i]));
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		int ways = C(n - 1, i - 1);
		ans = add(ans, mul(ways, mul(f[i - 1], fact[n - i])));
	}
	printf("%d\n", sub(fact[n], ans));
}