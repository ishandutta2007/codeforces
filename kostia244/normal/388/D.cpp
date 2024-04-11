#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int mod = 1e9 + 7;
namespace math {
const int A = 1<<20;

#define INLINE inline __attribute__ (( always_inline ))
struct mint {
	uint32_t v;
	template<class T = int>
	mint(T x = 0) {
		x %= mod;
		if(x < 0) x += mod;
		v = x;
	}
	mint operator-() const {
		return mint(v ? mod-v : 0);
	}
	mint &operator*=(const mint &r) {
		v = v*1ll*r.v%mod;
		return *this;
	}
	mint &operator+=(const mint &r) {
		v = v+r.v>=mod ? (v+r.v-mod) : (v+r.v);
		return *this;
	}
	mint &operator-=(const mint &r) { 
		return *this += -r;
	}
	mint &operator/=(const mint &r) {
		return *this *= r.inv();
	}
	friend mint operator+(mint a, const mint &b) {
		return a += b;
	}
	friend mint operator-(mint a, const mint &b) {
		return a -= b;
	}
	friend mint operator*(mint a, const mint &b) {
		return a *= b;
	}
	friend mint operator/(mint a, const mint &b) {
		return a /= b;
	}
	
	template<class T = int>
	mint pow(T p) const {
		mint res = 1, cur = *this;
		while(p) {
			if(p&1) res = res*cur;
			cur = cur*cur, p>>=1;
		}
		return res;
	}
	mint inv() const {
		return mint(*this).pow(mod-2);
	}
	
	friend bool operator==(const mint &a, const mint &b) {
		return a.v == b.v;
	}
	friend bool operator!=(const mint &a, const mint &b) {
		return !(a == b);
	}
	
	friend istream& operator>>(istream &is, mint &m) {
		ll v;
		is >> v;
		m = mint(v);
		return is;
	}
	friend ostream& operator<<(ostream &os, const mint &m) {
		os << m.v; 
		return os;
	}
};

mint fact[A], inum[A], ifact[A];
void calc_inum() {
	inum[1] = 1;
	for(int i = 2; i < A; i++) inum[i] = -inum[mod%i]*(mod/i);
}
void calc_combi() {
	if(0 == inum[1]) calc_inum();
	fact[0] = ifact[0] = 1;
	for(int i = 1; i < A; i++) fact[i] = fact[i-1]*i;
	for(int i = 1; i < A; i++) ifact[i] = ifact[i-1]*inum[i];
}

mint nck(int n, int k) {
	if(0 == fact[0]) calc_combi();
	if(k > n || k < 0) return 0;
	return fact[n]*ifact[k]*ifact[n-k];
}
}
using math::mint;
const int N = 33;
mint cnt[N][N][2], scnt[N][N][2];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int k;
	cin >> k;
	if(k==0) return cout<<"1", 0;
	cnt[0][0][0] = 1;
	scnt[0][0][0] = 1;
	auto get = [&](int msk, int b) { return (msk >> b) & 1; };
	for(int b = 0; (1<<b) <= k; b++) {
		for(int hv = 0; hv <= b; hv++) {
			for(int le = 0; le < 2; le++) {
				cnt[b + 1][hv][get(k, b) == 0 ? le : 0] += cnt[b][hv][le];
				scnt[b + 1][hv][get(k, b) == 0 ? le : 0] += scnt[b][hv][le];
				scnt[b + 1][hv][get(k, b) == 1 ? le : 1] += scnt[b][hv][le];
				
				mint p2 = mint(2).pow(b - hv);
				cnt[b + 1][hv + 1][get(k, b) == 1 ? le : 1] += cnt[b][hv][le] * p2;
				scnt[b + 1][hv + 1][get(k, b) == 1 ? le : 1] += scnt[b][hv][le] * p2;
			}
		}
	}
	mint ans = 0;
	int b = 0;
	while((k>>b) > 1) b++;
	for(int hv = 0; hv <= b; hv++) {
		//no msb
		ans += cnt[b][hv][0] + cnt[b][hv][1] + scnt[b][hv][0];
	}
	cout << ans << '\n';
}