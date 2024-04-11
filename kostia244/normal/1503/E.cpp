// Problem: E. 2-Coloring
// Contest: Codeforces - Codeforces Round #712 (Div. 1)
// URL: https://codeforces.com/contest/1503/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
const int mod = 998244353;
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
		is >> m.v;
		m = mint(m.v);
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
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n, m;
	cin >> n >> m;
	auto f = [&](int n, int m, int tp) {
		mint ans = 0;
		auto F = [&](int x, int y, int split) {
			return nck(x-1+split-1, split-1)*nck(m-y+split-1, split-1);
		};
		auto G = [&](int s) {
			vector<mint> a(m+1);
			mint t = 0;
			for(int y = 1; y <= m; y++) {
				a[y] += a[y-1];
				for(int x = y; x <= y; x++)
					t += nck(x-1+s-1, s-1);
				a[y] += t*nck(m-y+s-1, s-1);
			}
			return a;
		};
		auto H = [&](int s) {
			vector<mint> a(m+2);
			mint t = 0;
			for(int x = m; x; x--) {
				for(int y = x; y <= x; y++)
						t += nck(m-y+s-1, s-1);
				a[x] = t*nck(x-1+s-1, s-1);
			}
			return a;
		};
		for(int split = 1; split < n; split++) {
			vector<mint> x = G(split), y = H(n-split);
			for(int i = 1; i < m; i++)
				ans += x[i]*y[i+1+tp];
			// for(int x = 1; x <= m; x++)
				// for(int y = x; y <= m; y++)
					// for(int z = y+1+tp; z <= m; z++)
						// for(int t = z; t <= m; t++) {
							// ans += F(x,y,split)*F(z,t,n-split);
						// }
		}
		return ans*2;
	};
	mint ans = f(n, m, 0)+f(m, n, 1);
	cout << ans << '\n';
}