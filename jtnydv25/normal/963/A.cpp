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

const int N = 100006;
const int mod = 1e9 + 9;
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
char s[100005];

int gp(int a, int n){
	if(a == 1) return n;
	return mul(sub(powr(a, n), 1), inv(sub(a, 1)));
}

int main(){
	int n, a, b, k;
	sd(n);sd(a); sd(b); sd(k);
	int f =powr(a, n);
	scanf("%s", s);
	int ab = mul(b, inv(a));
	int sm = 0;
	int coeff = 1;
	for(int i = 0; i < k; i++){
		if(s[i] == '+')
			sm = add(sm, coeff);
		else sm = sub(sm, coeff);
		coeff = mul(coeff, ab);
	}

	int terms = n / k; int ans = mul(gp(powr(ab, k), terms), sm);
	coeff = powr(ab, k * terms);
	for(int i = k * terms; i <= n; i++){
		if(s[i % k] == '+') ans = add(ans, coeff);
		else ans = sub(ans, coeff);
		coeff = mul(coeff, ab);
	}
	printf("%d\n", mul(f, ans));
}