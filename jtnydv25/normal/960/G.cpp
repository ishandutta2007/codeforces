#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";

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

const int MX = 21;
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
int MAX = 100005;
vi store[35];

void mul(vi & a, vi b){
	int sz = a.size() + b.size() - 1;
	int k = 0;
	while((1 << k) < sz) k++;
	a.resize(1 << k); b.resize(1 << k);
	fft(a, 0); fft(b, 0);
	for(int i = 0; i < (1 << k); i++)
		a[i] = mul(a[i], b[i]);
	fft(a, 1);
	a.resize(sz);
	if(a.size() >= MAX) a.resize(MAX);
}

void sqr(vi & a){
	int sz = a.size() + a.size() - 1;
	int k = 0;
	while((1 << k) < sz) k++;
	a.resize(1 << k);
	fft(a, 0);
	for(int i = 0; i < (1 << k); i++)
		a[i] = mul(a[i], a[i]);
	fft(a, 1);
	a.resize(sz);
	if(a.size() >= MAX) a.resize(MAX);
}

const int N = 200005;
int fact[N], invfact[N];
void pre(){
	fact[0] = invfact[0] = 1;
	for(int i = 1;i < N; i++) fact[i] = mul(i, fact[i - 1]);
	invfact[N - 1] = inv(fact[N - 1]);
	for(int i = N - 2; i >= 1; i--) invfact[i] = mul(i+1, invfact[i+1]);
	assert(invfact[1] == 1);
}
inline int C(int n, int k){
	if(n < k || k < 0) return 0;
	return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

vi power(int m){
	vi ret = {1};
	for(int i = 0; i < 30; i++) if(m >> i & 1) mul(ret, store[i]);
	return ret;
}

int n, A, B;

void precompute(){
	vi v = {0};
	int curr = 1;
	for(int i = 1; i < MAX; i++){
		v.push_back(mul(curr, inv(i)));
		curr = mul(curr, mod - 1);
	}
	store[0] = v;
	for(int i = 1; (1 << i) < MAX; i++) store[i] = store[i - 1], sqr(store[i]);
}

vi get(int k){
	
	vi v = power(k);
	for(int i = 0; i < v.size(); i++){
		v[i] = mul(v[i], invfact[k]);
		if((100000000+i-k) & 1) v[i] = mul(v[i], mod - 1);
	}
	return v;
}

int getv(vi & v, int k){
	return (k < 0 || k >= v.size()) ? 0 : v[k];
}

int main(){
	precompute_powers();
	pre();
	precompute();
	n = 100000, A = 1000000, B = 100000;
	cin >> n >> A >> B;
	if(n < A + B - 100){
		cout << 0;
		return 0;
	}
	MAX = n + 4;
	if(A == 0 || B == 0){
		cout << 0; return 0;
	}

	A--;
	B--;
	n--;
	vi vA = get(A + B);
	cout <<mul(mul(C(A+B,A), fact[n]), getv(vA, n))	 << endl;
}