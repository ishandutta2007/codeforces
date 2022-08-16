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

const int MX = 13;
int W[1 << MX], invW[1 << MX]; // max polynomial input/output -> (1 << MX)
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

vi calc_b;
vi Y(4096);

void mul2(vi & a){
	a.resize(4096);
	fft(a, 0);
	for(int i = 0; i < 4096; i++) a[i] = mul(a[i], Y[i]);
	fft(a, 1);
}

const int N = 1 << 12;
int f[N][N], fact[N], invfact[N];

inline int C(int n, int k){
	if(n < k || k < 0) return 0;
	return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

void pre(){
	fact[0] = invfact[0] = 1;
	for(int i = 1;i < N; i++) fact[i] = mul(i, fact[i - 1]);
	invfact[N - 1] = inv(fact[N - 1]);
	for(int i = N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
	assert(invfact[1] == 1);
	
	for(int i = 0; i < N; i++) Y[i] = fact[i];
	fft(Y, 0);

	vi X(N);
	for(int a = 0; a < N; a++){
		for(int i = 0; i <= a; i++){
			X[i] = C(a, i);
			if(i & 1) X[i] = sub(0, X[i]);
		}
		for(int i = a + 1; i < 4096; i++) X[i] = 0;
		mul2(X);
		for(int j = 0; j < N; j++) f[a][j] = X[j];
	}
}

int bit[N], bit2[N];

void push(int x, int d){
	for(; x < N; x += (x & (-x))) bit[x] += d;
}

int get(int x){
	int ret = 0;
	for(; x; x -= (x & (-x))) ret += bit[x];
	return ret;
}

void push2(int x, int d){
	for(; x < N; x += (x & (-x))) bit2[x] += d;
}

int get2(int x){
	int ret = 0;
	for(; x; x -= (x & (-x))) ret += bit2[x];
	return ret;
}

int a[N][N];
int st[N];
bool there[N];

int main(){
	precompute_powers();
	pre();
	int n; sd(n);
	int H = f[n][n];
	st[0] = 1;
	for(int i = 1; i < N; i++) st[i] = mul(H, st[i - 1]);
	int ans = 0;
	for(int i = 1; i <= n; i++){

		// for(int j = 0; j < N; j++){
		// 	if(bit[j] != 0){
		// 		assert(0);
		// 		trace(1, j); return 0;
		// 	}
		// }

		// for(int j = 0; j < N; j++){
		// 	if(bit2[j] != 0){
		// 		assert(0);
		// 		trace(1, j); return 0;
		// 	}
		// }

		for(int j = 1; j <= n; j++) push(j, 1);

		memset(bit2, 0, sizeof bit2);
		for(int j = 1; j <= n; j++){
			int x;
			sd(x);
			a[i][j] = x;
			int options = get(x - 1);
			if(i == 1){
				ans = add(ans, mul(mul(options, fact[n - j]), st[n - i]));
				push(x, -1);
				continue;
			}

			int y = a[i - 1][j];

			int getx = options;
			bool y_in_common = get(y) != get(y - 1);

			// bool y_in_uncommon = !y_in_common;

			int curr_common = get(N - 1);
			int common = curr_common;
			// take from common
			if(y_in_common && y < x) options --;
			if(y_in_common) common--;
			if(options) ans = add(ans, mul(options, mul(f[common - 1][n - j], st[n - i])));

			// take from uncommon
			options = get2(x - 1);
			
			if(options) ans = add(ans, mul(options, mul(f[common][n - j], st[n - i])));

			bool x_in_common = get(x) != getx;

			if(y_in_common){
				push(y, -1);
				push2(y, 1);
			}


			if(x_in_common){
				push(x, -1);
			} else push2(x, -1);
		}
	}
	printf("%d\n", ans);
}