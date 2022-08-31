#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d", &(x))
#define ll long long
#define pb push_back
#define F first
#define S second
#define pii pair<int, int>

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

#define ll long long
inline int add(int x, int y, int mod){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y, int mod){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y, int mod){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b, int mod){
	assert(b >= 0);
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a, mod);
		a = mul(a, a, mod);
		b >>= 1;
	}
	return x;
}

inline ll power(int a, ll b){
	int x = 1;
	while(b){
		if(b & 1) x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}

// inline int inv(int a){ return powr(a, mod - 2);}

map<int, int> store;
int phi(int m){
	if(store.find(m) != store.end()) return store[m];
	int ret = m;
	for(int p = 2; p * p <= m; p++){
		if(m % p == 0){
			ret /= p;
			ret *= p - 1;
			while(m % p == 0) m /= p;
		}
	}
	if(m != 1){
		ret /= m;
		ret *= m - 1;
	}
	return store[m] = ret;
}
const int M = 100005;
int w[M];

bool isBig(int l, int r, double x){
	if(x < 0) return 1;
	if(l == r) return w[l] >= x;
	if(w[l] == 1) return 1 >= x;
	return isBig(l + 1, r, log(x) / log(w[l]));
}

inline int getTotal(int l, int r){
	if(w[l] == 1) return 1;
	if(l == r) return w[l];
	return power(w[l], getTotal(l + 1, r));
}

int get(int l, int r, int m){
	// trace(l,r,m);
	if(m == 1) return 0;
	if(w[l] == 1) return 1 % m;
	if(l == r) return w[l] % m;
	if(isBig(l + 1, r, log(m) / log(2) + 1)){
		// cerr << "here"<<endl;
		int phim = phi(m);
		return powr(w[l], get(l + 1, r, phim) + phim, m);
	}
	return powr(w[l], getTotal(l + 1, r), m);
}

int main(){
	int n = 100000, m = 1000000000;
	sd(n); sd(m);
	for(int i = 1; i <= n; i++){
		// w[i] = rand() % 1000000000;
		sd(w[i]);
	}
	int q = 100000;
	sd(q);
	for(int i = 1;i <= q; i++){
		// trace(i);
		int l, r;
		sd(l);
		sd(r);
		printf("%d\n", get(l, r, m));
	}
	// cerr << clock() / (double) CLOCKS_PER_SEC << endl;
}