#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define sd(x) scanf("%d", &(x))

const int N = 1e5 + 10, mod = 998244353;
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

const int MX = 21;
int W[1 << MX], invW[1 << MX], maxn;
const int g = 3, p = mod;
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
vi P, Q, R;
int main(){
	pre();
	precompute_powers();
	int n;
	long long m;
	scanf("%d %lld", &n, &m);
	int offset = n + 1;
	P.resize(offset);
	for(int i = 0; i <= n; i++) sd(P[i]), P[i] = mul(fact[i], P[i]);
	Q.resize(offset + 1);
	for(int i = 0; i <= n; i++) Q[offset - i] = invfact[i];
	P = mul(P, Q);
	for(int i = 0; i <= n; i++) P[i] = mul(invfact[i], P[offset + i]);
	P.resize(offset);
	for(int i = 0; i <= n; i++) P[i] = mul(P[i], powr(inv(i + 1), m));
	for(int i = 0; i <= n; i++) P[i] = (i & 1) ? sub(0, mul(fact[i], P[i])) : mul(fact[i], P[i]);
	P = mul(P, Q);
	for(int i = 0; i <= n; i++){
		int ans = mul(invfact[i], P[offset + i]);
		if(i & 1) ans = sub(0, ans);
		printf("%d ", ans);
	}
}