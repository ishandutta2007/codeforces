#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6 + 10, mod = 998244353;
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
int f[N];
int main(){
	pre();
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		f[i] = mul(C(n, i), fact[n - i]);
	}
	int ans = 1;
	for(int k = 1; k < n; k++){
		ans = add(ans, mul(n - k, sub(f[k], f[k + 1])));
		int t = sub(f[k], f[k + 1]);
	}
	printf("%d\n", ans);
}