#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

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


const int N = 4e6 + 10, mod = 998244353;
int fact[N], invfact[N], inverses[N];
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
	inverses[0] = 0;
	inverses[1] = 1;
	for(int i = 2; i < N; i++){
		inverses[i] = sub(0, mul(mod / i, inverses[mod % i]));
		// assert(mul(i, inverses[i]) == 1);
	}
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
	f[0] = 0;
	int n, m; cin >> n >> m;
	int A = 0, B = 0, C = 0;
	C = fact[m - 1];
	for(int k = 1; k <= n; k++){
		int L = mul(fact[m - 1 + k], invfact[k]);
		B = add(B, mul(k, L));
		C = add(C, L);
		int coeff = mul(m, mul(fact[k], invfact[m + k]));
		coeff = mul(coeff, mul(m + k, inverses[k]));
		int c2 = mul(m + n + 1, inverses[m + k + 1]);
		int sm = mul(c2, sub(mul(k + 1, C), B));
		sm = add(sm, A);
		f[k] = mul(coeff, sm);
		A = add(A, mul(L, f[k]));
	}
	cout << f[n] << endl;
}