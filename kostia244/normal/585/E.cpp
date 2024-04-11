// Problem: E.    
// Contest: Codeforces - Codeforces Round #325 (Div. 1)
// URL: https://codeforces.com/contest/585/problem/E?locale=ru
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
const int C = 1e7+10;
mint a[C], c[C], p2[C];
int lp[C], sq[C];
vector<int> pr;
void dfs(int x, int y, int d = -1) {
	if(x == 1) {
		// cout << y << " " << d << endl;
		c[y] += d*(y>1);
		return;
	}
	dfs(x/lp[x], y, d);
	dfs(x/lp[x], y*lp[x], -d);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	sq[1] = 1;
	for(int i = 2; i < C; i++) {
		if(!lp[i]) {
			lp[i] = i;
			pr.push_back(i);
		}
		int t = i/lp[i];
		if(lp[t] == lp[i])
			sq[i] = sq[t];
		else
			sq[i] = sq[t]*lp[i];
		for(int j = 0; j < pr.size() && pr[j]*i < C && pr[j] <= lp[i]; j++)
			lp[pr[j]*i] = pr[j];
	}
	int n, t;
	cin >> n;
	p2[0] = 1;
	for(int i = 1; i <= n; i++)
		p2[i] = p2[i-1]*2;
	for(int i = 0; i < n; i++) {
		cin >> t;
		a[t] += 1;
		dfs(sq[t], 1);
	}
	for(auto i : pr)
		for(int j = 1; j*i < C; j++)
			c[j*i] += c[j];
	for(auto i : pr)
		for(int j = (C-1)/i; j; j--)
			a[j] += a[j*i];
	for(int i = 0; i < C; i++)
		a[i] = p2[a[i].v]-1;
	for(auto i : pr)
		for(int j = 1; j*i < C; j++)
			a[j] -= a[j*i];
	mint ans = 0;
	for(int i = 2; i < C; i++) {
		ans += a[i]*(n-c[sq[i]]);
	}
	cout << ans << '\n';
}