#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define vi vector<int>
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


const int g = 3, mod = 998244353, p = 998244353;
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

const int MX = 19;
int W[1 << MX], invW[1 << MX];
int maxn;
void precompute_powers(){
	int p2 = p - 1, MAXN = 0;
	while(p2 % 2 == 0){
		p2 >>= 1;
		MAXN ++;
	}
	MAXN = min(MAXN, MX);
	int g1 = powr(g, (p - 1) >> MAXN);
	maxn = 1 << MAXN;
	int st = 1;
	for(int i = 0; i < maxn; i++){
		W[i] = st;
		st = mul(st, g1);
	}
	for(int i = 0; i < maxn; i++){
		invW[i] = (i == 0) ? 1 : W[maxn - i];
	}
}

void fft (vector<int> & a, bool invert) {
    int n = (int) a.size();

    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }

    for (int len=2; len<=n; len<<=1) {
        for (int i=0; i<n; i+=len) {
            int ind = 0,ADD = maxn/len;
            for (int j=0; j<len/2; ++j) {
                int u = a[i+j],  v = mul(a[i+j+len/2], (invert?invW[ind]:W[ind]));
                a[i+j] = add(u, v);
                a[i+j+len/2] = sub(u, v);
                ind += ADD;
            }
        }
    }
    if (invert){
    	int invn = inv(n);
    	for (int i=0; i<n; ++i) a[i] = mul(a[i], invn);
    }
}

vi mul(vi a, vi b){
	int sz = a.size() + b.size() - 1;
	int k = 0;
	while((1 << k) < sz) k++;
	a.resize(1 << k); b.resize(1 << k);
	fft(a, 0); fft(b, 0);
	for(int i = 0; i < (1 << k); i++)
		a[i] = mul(a[i], b[i]);
	fft(a, 1);
	a.resize(sz);
	return a;
}

const int N = 2e5 + 10;
int fact[N], invfact[N];
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

// given set of sizes, find ..
vi getprod(vi & v){
	if(v.empty()) return {1};
	if(v.size() == 1) return {1, v[0]};
	int mid = (v.size() + 1) >> 1;
	vi lft(v.begin(), v.begin() + mid);
	vi rgt(v.begin() + mid, v.end());
	return mul(getprod(lft), getprod(rgt));
}

int sz[N], F[N], G[N], sumF[N], sumF2[N];
vector<int> con[N];
void add_edge(int a, int b){
	con[a].push_back(b);
	con[b].push_back(a);
}

int n, k;

int get(vi & v, int pos){ return pos >= v.size() ? 0 : v[pos];}
const int inv2 = (mod + 1) >> 1;
int ans = 0;
int F2 = 0;
int totalF = 0;

struct poly_fraction{
	vi num,  den;
	poly_fraction(){
		num.resize(1);
		den.resize(1);
		den[0] = 1;
	}
	poly_fraction(vi a, vi b){
		num = a, den = b;
	}
	poly_fraction operator + (const poly_fraction & f) const{
		vi num1 = mul(num, f.den);
		vi num2 = mul(f.num, den);
		vi den2 = mul(f.den, den);
		poly_fraction ret;
		ret.num.resize(max(num1.size(), num2.size()));
		for(int i = 0; i < ret.num.size(); i++) ret.num[i] = add(get(num1, i), get(num2, i));
		ret.den = den2;
		return ret;
	}
};

poly_fraction getfrac(vector<pii> & v){
	if(v.empty()) return poly_fraction();
	if(v.size() == 1){
		return poly_fraction({v[0].F}, {1, v[0].S});
	}
	int mid = (v.size() + 1) >> 1;
	vector<pii> lft(v.begin(), v.begin() + mid);
	vector<pii> rgt(v.begin() + mid, v.end());
	return getfrac(lft) + getfrac(rgt);
}

void dfs(int s = 1, int p = 0){
	sz[s] = 1;
	sumF[s] = 0;
	vector<int> vec;
	vector<pii> vec2;
	int cntchld = 0;
	for(int v : con[s]){
		if(v != p){
			dfs(v, s);
			sz[s] += sz[v];
			vec.push_back(sz[v]);
			sumF[s] = add(sumF[s], sumF[v]);
			vec2.push_back({sumF[v], sz[v]});
			cntchld++;
		}		
	}
	vec = getprod(vec);
	for(int j = 0; j <= k && j < vec.size(); j++){
		F[s] = add(F[s], mul(fact[k], mul(invfact[k - j], get(vec, j))));
	}

	ans = sub(ans, mul(F[s], sumF[s]));
	sumF[s] = add(sumF[s], F[s]);
	totalF = add(totalF, F[s]);
	F2 = add(F2, mul(F[s], F[s]));
	// trace(s, F[s]);
	if(cntchld){
		int sz_up = n - sz[s];
		vi poly = getfrac(vec2).num;
		poly = mul(poly, {1, sz_up});
		for(int j = 0; j <= k && j < poly.size(); j++){
			ans = add(ans, mul(fact[k], mul(invfact[k - j], get(poly, j))));
		}
	}
}

int main(){
	precompute_powers();
	pre();
	// n = 30000, k = 100000;
	sd(n); sd(k);
	if(k == 1){
		printf("%d\n", C(n, 2));
		return 0;
	}
	for(int i = 1; i  < n; i++){
		int u = i + 1, v = rand() % i + 1;
		sd(u); sd(v);
		add_edge(u, v);
	}
	dfs();
	ans = add(ans, mul(inv2, sub(mul(totalF, totalF), F2)));
	printf("%d\n", ans);
}