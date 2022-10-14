// Problem: D1.    ( )
// Contest: Codeforces - Codeforces Round #767 (Div. 1)
// URL: https://codeforces.com/contest/1628/problem/D1
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
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n, m, k;
		cin >> n >> m >> k;
		m = n-m;
		//wlog k = 1
		auto f = [](int n, int m) ->mint {
			mint x = 0, ans = 0;
			for(int i = 1; i <= n; i++) {
				mint nx = (mint(2).pow(i-1)+x)*2;
				ans += (nx-x)*nck(n-i, m);
				// cout << i << " " << (nx-x) << " " << nck(n-i+m, m) << endl;
				x = nx;
				// cout << x/2 <<endl;
			}
			return ans;
		};
		// cout << f(2, 1) << endl;
		// return;
		// using T = mint;
		// vector<vector<T>> dp(n+1, vector<T>(n+1));
		// for(int i = 1; i <= n; i++) {
			// for(int j = 0; j <= i; j++) {
				// if(j==i)
					// dp[i][j] = 0;
				// else if(j) {
					// T x = (dp[i-1][j]+dp[i-1][j-1]);
					// dp[i][j] = x;
				// } else
					// dp[i][j] = (dp[i-1][j] + mint(2).pow(i-1))*2;
			// }
			// cout << i << " : ";for(int j = 0; j <= i; j++) cout << dp[i][j]/2 << " "; cout << endl;
			// cout << i << " : ";for(int j = 0; j <= i; j++) cout << f(i,j)/2 << " "; cout << endl;
			// cout << endl;
		// }
		// mint x = 0;
		cout << f(n,m)*k/mint(2).pow(n) << '\n';
	});
	
}