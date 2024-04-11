// Problem: F. Runner's Problem
// Contest: Codeforces - Educational Codeforces Round 40 (Rated for Div. 2)
// URL: https://codeforces.com/contest/954/problem/F
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
using namespace math;
using mat = array<array<mint, 3>, 3>;
mat mul(mat a, mat b) {
	mat c;
	for(int i = 0; i < 3; i++) {
		c[i].fill(0);
		for(int k = 0; k < 3; k++)
			for(int j = 0; j < 3; j++)
				c[i][j] += a[i][k]*b[k][j];
	}
	return c;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	ll n, m;
	cin >> n >> m;
	mat res {1, 0, 0, 0, 1, 0, 0, 0, 1};
	map<ll, array<int, 3>> cnt;
	cnt[1][0] += 0;
	cnt[m][0] += 0;
	for(ll a, l, r, i = 0; i < n; i++) {
		cin >> a >> l >> r;a--;
		cnt[l-1][a]++;
		cnt[r][a]--;
	}
	array<int, 3> run {0, 0, 0};
	auto x = cnt.begin();
	auto y = x;y++;
	while(y != cnt.end()) {
		for(int i = 0; i < 3; i++)
			run[i] += x->second[i];
		mat c;
		ll len = y->first - x->first;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++)
				c[i][j] = run[j]==0 && abs(i-j)<2;
		}
		while(len) {
			if(len&1) res = mul(res, c);
			c = mul(c, c), len>>=1;
		}
		x++,y++;
	}
	cout << res[1][1]<< endl;
}