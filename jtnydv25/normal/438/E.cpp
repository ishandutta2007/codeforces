// TESTED for degree 2 * 10 ^ 5 in SPOJ : ADAPANEL
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double
#define vi vector<ll>
#define vll vector<ll >
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define endl "\n"

struct base{
    ld x,y;
    base(){x=y=0;}
    base(ld _x, ld _y){x = _x,y = _y;}
    base(ld _x){x = _x, y = 0;}
    void operator = (ld _x){x = _x,y = 0;}
    ld real(){return x;}
    ld imag(){return y;}
    base operator + (const base& b){return base(x+b.x,y+b.y);}
    void operator += (const base& b){x+=b.x,y+=b.y;}
    base operator * (const base& b){return base(x*b.x - y*b.y,x*b.y+y*b.x);}
    void operator *= (const base& b){ld p = x*b.x - y*b.y, q = x*b.y+y*b.x; x = p, y = q;}
    void operator /= (ld k){x/=k,y/=k;}
    base operator - (const base& b){return base(x - b.x,y - b.y);}
    void operator -= (const base& b){x -= b.x, y -= b.y;}
    base conj(){ return base(x, -y);}
    base operator / (ld k) { return base(x / k, y / k);}
    void Print(){ cerr << x <<  " + " << y << "i\n";}
};
double PI = 2.0*acos(0.0);
const int MAXN = 19;
const int maxn = (1<<MAXN);
base W[maxn],invW[maxn], P1[maxn], Q1[maxn];
void precompute_powers(){
    for(int i = 0;i<maxn/2;i++){
        double ang = (2*PI*i)/maxn; 
        ld _cos = cos(ang), _sin = sin(ang);
        W[i] = base(_cos,_sin);
        invW[i] = base(_cos,-_sin);
    }
}
void fft (vector<base> & a, bool invert) {
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
            int ind = 0,add = maxn/len;
            for (int j=0; j<len/2; ++j) {
                base u = a[i+j],  v = (a[i+j+len/2] * (invert?invW[ind]:W[ind]));
                a[i+j] = (u + v);
                a[i+j+len/2] = (u - v);
                ind += add;
            }
        }
    }
    if (invert) for (int i=0; i<n; ++i) a[i] /= n;
}

// 4 FFTs in total for a precise convolution
void mul_big_mod(vll &a, vll & b, ll mod){
    int n1 = a.size(),n2 = b.size();
    int final_size = a.size() + b.size() - 1;
    int n = 1;
    while(n < final_size) n <<= 1;
    vector<base> P(n), Q(n);
    int SQRTMOD = (int)sqrt(mod) + 10;
    for(int i = 0;i < n1;i++) P[i] = base(a[i] % SQRTMOD, a[i] / SQRTMOD);
    for(int i = 0;i < n2;i++) Q[i] = base(b[i] % SQRTMOD, b[i] / SQRTMOD);
    fft(P, 0);
    fft(Q, 0);
    base A1, A2, B1, B2, X, Y;
    for(int i = 0; i < n; i++){
        X = P[i];
        Y = P[(n - i) % n].conj();
        A1 = (X + Y) * base(0.5, 0);
        A2 = (X - Y) * base(0, -0.5);
        X = Q[i];
        Y = Q[(n - i) % n].conj();
        B1 = (X + Y) * base(0.5, 0);
        B2 = (X - Y) * base(0, -0.5);
        P1[i] = A1 * B1 + A2 * B2 * base(0, 1);
        Q1[i] = A1 * B2 + A2 * B1;
    }
    for(int i = 0; i < n; i++) P[i] = P1[i], Q[i] = Q1[i];
    fft(P, 1);
    fft(Q, 1);
    a.resize(final_size);
    for(int i = 0; i < final_size; i++){
        ll x = (ll)(P[i].real() + 0.5);
        ll y = (ll)(P[i].imag() + 0.5) % mod;
        ll z = (ll)(Q[i].real() + 0.5);
        a[i] = (x + ((y * SQRTMOD + z) % mod) * SQRTMOD) % mod;
    }
}
const int mod = 998244353, N = 2e5 + 10;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
const int MOD = mod;
void madd(ll& a, ll b) {
    if ((a += b) >= MOD) a -= MOD;
}

void msub(ll & a, ll b){
	a -= b;
	if(a < 0) a += mod;
}
int mpow(int a, int b){
  if (!b) return 1;
  if (b & 1) return (mpow(a, b-1) * 1LL * a) % MOD;
  int temp = mpow(a, b/2);
  return (temp * 1LL * temp) % MOD;
}

int minv(int a){
	return mpow(a, mod -2);
}
#define sz(x) int((x).size())

vll inverse(vll a){
  assert(a[0] != 0);
  vll x(1, mpow(a[0], mod - 2));
  while (sz(x) < sz(a)) {
    vll temp(a.begin(), a.begin() + min(sz(a), 2 * sz(x)));
    vll nx = x; mul_big_mod(nx, x, mod); mul_big_mod(nx, temp, mod);
    x.resize(2*sz(x));
    for (int i = 0; i < sz(x); i++) 
      madd(x[i], x[i]), madd(x[i], MOD - nx[i]);
  }
  return x;
}

vll mul(vll a, vll b){
	mul_big_mod(a, b, mod);
	return a;
}

vll add(vll a, vll b){
	if(a.size() < b.size()) a.resize(b.size());
	else if(b.size() < a.size()) b.resize(a.size());
	for(int i = 0; i < a.size(); i++) madd(a[i], b[i]);
	return a;
}

vll sub(vll a, vll b){
	if(a.size() < b.size()) a.resize(b.size());
	else if(b.size() < a.size()) b.resize(a.size());
	for(int i = 0; i < a.size(); i++) msub(a[i], b[i]);
	return a;
}

vll div(vll a, vll b){
	return mul(a, inverse(b));
}

void append(vll & a, vll & b){
	b.resize(a.size());
	for(int i = 0; i < b.size(); i++) a.push_back(b[i]);
}

ll inv2;
vll SQRT(vll F, int n){
	vll G = {F[0]};
	while(G.size() < n + 1){
		vll f(F.begin(), F.begin()  + min(2 * (int)G.size(), (int)F.size()));
		vll res = add(G, div(f, G));
		for(int i = 0; i < res.size(); i++) res[i] = (inv2 * res[i]) % mod;
		G.resize(2 * G.size());
		for(int i = 0; i < G.size(); i++) G[i] = res[i];
	}
	G.resize(n + 1);
	return G;
}

vector<ll> C, C2;
void insert(int x){
	if(C.size() <= x){
		C.resize(x + 1);
		C2.resize(x + 1);
	}
	C[x] = mod - 4;
}

int main(){
	precompute_powers();
	inv2 = minv(2);
	C = {1};
	int n, m; cin >> n >> m;
	m *= 2;
	m += 10;
	int c;
	for(int i = 1; i <= n; i++){
		cin >> c;
		insert(c);
	}
	C.resize(m);
	C = SQRT(C, m);
	C2 = mul(C, C);
	C[0] += 1;
	vll v2 = {2};

	C = inverse(C);
	for(int i = 1;i <= (m - 10) / 2; i++) printf("%lld\n", 2 * 1ll *C[i] % mod);
}