#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
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
int pw3[N];
void pre(){
	fact[0] = invfact[0] = pw3[0] = 1;
	for(int i = 1;i < N; i++) fact[i] = mul(i, fact[i - 1]), pw3[i] = mul(3, pw3[i - 1]);
	invfact[N - 1] = inv(fact[N - 1]);
	for(int i = N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
	assert(invfact[1] == 1);
}
inline int C(int n, int k){
	if(n < k || k < 0) return 0;
	return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

int main(){
	pre();
	int n;
	scanf("%d", &n);
	int val = 0;

	for(int i = 1; i <= n; i++){
		int t = mul(C(n, i), sub(powr(sub(pw3[n - i], 1), n), powr(pw3[n - i], n)));;
		t = mul(3, t);
		if(i & 1) val = add(val, t);
		else val = sub(val, t);
	}
	for(int i = 1; i <= n; i++){
		int expr = mul(2, mul(C(n, i), mul(pw3[i], powr(pw3[n - i], n))));
		if(i & 1) val = add(val, expr);
		else val = sub(val, expr);
	}
	printf("%d\n", val);

}