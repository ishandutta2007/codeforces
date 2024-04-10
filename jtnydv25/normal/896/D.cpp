#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int N = 2e5 + 10;
int mod = 1e9 + 7;
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

int mul_inv(int a, int b)
{
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

vector<int> primes;
void pre(){
	int MOD = mod;
	for(int i = 2; i * i <= MOD; i++){
		if(MOD % i == 0){
			primes.push_back(i);
			while(MOD % i == 0) MOD /= i;
		}
	}
	if(MOD != 1) primes.push_back(MOD);

	fact[0] = invfact[0] = 1;
	for(int i = 1;i < N; i++){
		int k = i;
		for(int p : primes) while(k % p == 0) k /= p;
		fact[i] = mul(k, fact[i - 1]);
	}
	for(int i = 0; i < N; i++){
		invfact[i] = mul_inv(fact[i], mod);
	}
}

int power(int n, int p){
	int ret = 0; n /= p;
	while(n){
		ret += n;
		n /= p;
	}
	return ret;
}

int power(int n, int k, int p){
	return power(n, p) - power(k, p) - power(n - k, p);
}

inline int C(int n, int k){
	if(n < k || k < 0) return 0;
	int ret = mul(fact[n], mul(invfact[k], invfact[n - k]));
	for(int p : primes){
		ret = mul(ret, powr(p, power(n, k, p)));
	}
	return ret;
}

main(){
	int n, l, r;
	cin >> n >> mod >> l >> r;
	pre();
	int ans = 0;
	int oddl = l / 2, oddr = (r == 0) ? -1 : (r - 1) / 2;
	int evenl = (l == 0) ? 0 : (l - 1) / 2 + 1;
	int evenr = r / 2; 
	for(int k = 0; k <= n; k++){
		int ans1 = 0;
		int t = k >> 1;
		if((k & 1) && oddl <= oddr){
			ans1 = sub(C(2 * t + 1, t + oddl + 1), C(2 * t + 1, t + oddr + 2));
		}
		else if(k % 2 == 0 && (evenl <= evenr)) ans1 = sub(C(2 * t, t + evenl), C(2 * t, t + evenr + 1));
		ans = add(ans, mul(ans1, C(n, k)));
	}
	cout << ans;
}