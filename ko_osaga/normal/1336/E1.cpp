#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 3005;
const int mod = 998244353;

struct mint {
	int val;
	mint() { val = 0; }
	mint(const lint& v) {
		val = (-mod <= v && v < mod) ? v : v % mod;
		if (val < 0) val += mod;
	}

	friend ostream& operator<<(ostream& os, const mint& a) { return os << a.val; }
	friend bool operator==(const mint& a, const mint& b) { return a.val == b.val; }
	friend bool operator!=(const mint& a, const mint& b) { return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { return a.val < b.val; }

	mint operator-() const { return mint(-val); }
	mint& operator+=(const mint& m) { if ((val += m.val) >= mod) val -= mod; return *this; }
	mint& operator-=(const mint& m) { if ((val -= m.val) < 0) val += mod; return *this; }
	mint& operator*=(const mint& m) { val = (lint)val*m.val%mod; return *this; }
	friend mint ipow(mint a, lint p) {
		mint ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mint inv(const mint& a) { assert(a.val); return ipow(a, mod - 2); }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }

	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
	operator int64_t() const {return val; }
};
	template<typename T>

	void ntt(vector<T> &a, bool inv){
		const int prr = 3; // primitive root
		int n = a.size(), j = 0;
		vector<T> roots(n/2);
		for(int i=1; i<n; i++){
			int bit = (n >> 1);
			while(j >= bit){
				j -= bit;
				bit >>= 1;
			}
			j += bit;
			if(i < j) swap(a[i], a[j]);
		}
		for(int i=2; i<=n; i<<=1){
			int step = n / i;
			for(int j=0; j<n; j+=i){
				for(int k=0; k<i/2; k++){
					T u = a[j+k], v = a[j+k+i/2];
					a[j+k] = u+v;
					a[j+k+i/2] = u-v;
				}
			}
		}
		if(inv){
			T rev = T(1) / T(n);
			for(int i=0; i<n; i++) a[i] *= rev;
		}
	}
	template<typename T>
	vector<T> multiply_ntt(vector<T> &v, const vector<T> &w){
		vector<T> fv(all(v)), fw(all(w));
		int n = 2;
		while(n < sz(v) + sz(w)) n <<= 1;
		fv.resize(n); fw.resize(n);
		ntt(fv, 0); ntt(fw, 0);
		for(int i=0; i<n; i++) fv[i] *= fw[i];
		ntt(fv, 1);
		vector<T> ret(n);
		for(int i=0; i<n; i++) ret[i] = fv[i];
		return ret;
	}

int n, m;

lint basis[40];
int cnt1[20][1 << 17], cnt2[1 << 17];
mint ret[1 << 17];

void convo(int *a, int *b, mint *c){
	vector<mint> v1(a, a + (1<<(m/2)));
	vector<mint> v2(b, b + (1<<(m/2)));
	auto dap = multiply_ntt(v1, v2);
	for(int i=0; i<(1<<(m/2)); i++) c[i] = dap[i];
}

void bktk1(int cp, lint msk){
	if(cp == m / 2){
		cnt2[msk]++;
		return;
	}
	bktk1(cp + 1, msk);
	if(basis[cp]) bktk1(cp + 1, msk ^ basis[cp]);
}

void bktk2(int cp, lint msk){
	if(cp == m / 2){
		int pos = __builtin_popcountll(msk >> (m / 2));
		int kk = (1 << (m / 2));
		cnt1[pos][msk & (kk - 1)]++;
		return;
	}
	bktk2(cp - 1, msk);
	if(basis[cp - 1]) bktk2(cp - 1, msk ^ basis[cp - 1]);
}

mint dap[55];

int main(){
	scanf("%d %d",&n,&m);
	mint pwr = 1;
	for(int i=0; i<n; i++){
		lint x;
		scanf("%lld",&x);
		for(int j=m-1; j>=0; j--){
			if((x >> j) & 1){
				if(!basis[j]){
					basis[j] = x;
					break;
				}
				else x ^= basis[j];
			}
		}
		if(x == 0) pwr = pwr + pwr;
	}
	bktk1(0, 0);
	bktk2(m, 0);
	for(int i=0; i<=m/2+2; i++){
		convo(cnt1[i], cnt2, ret);
		for(int j=0; j<(1<<(m/2)); j++){
			dap[i + __builtin_popcount(j)] += mint(ret[j]);
		}
	}
	for(int i=0; i<=m; i++) dap[i] *= pwr;
	for(int i=0; i<=m; i++) printf("%lld ", (lint)dap[i]);
}