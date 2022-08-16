#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e3 + 10, mod = 1e9 + 7;
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
int n, k;
int C2[N + 10], A[N], E[N];
inline int getC2(int i){
	if(i > k) return 0;
	return C2[i];	
}
int F[N][N];
int main(){
	pre();
	cin >> n >> k;
	F[0][0] = 1;
	for(int i = 1; i <= n; i++){
		F[i][0] = 1;
		cin >> A[i];
		for(int j = 1; j <= i; j++){
			F[i][j] = add(F[i - 1][j], mul(A[i], F[i - 1][j - 1]));
		}
	}
	C2[0] = 1;
	for(int i = 1; i <= n + 10; i++) C2[i] = mul(C2[i - 1], mul(k - i + 1, inv(i)));
	int invn = inv(n);
	int _div = 1;
	for(int i = 0; i <= n - 1; i++){
		E[i] = mul(getC2(i + 1), _div);
		_div = mul(_div, invn);
		E[i] = mul(E[i], fact[i]);
	}
	int ans = 0;
	for(int i = 0; i <= n - 1; i++){
		ans = add(ans, mul(F[n][i], mul(n - i, mul(powr(mod - 1, n - 1 - i), E[n - 1 - i]))));
	}
	ans = mul(ans, invn);
	cout << ans;
}