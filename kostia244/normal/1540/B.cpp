// Problem: B. Tree Array
// Contest: Codeforces - Codeforces Round #728 (Div. 1)
// URL: https://codeforces.com/contest/1540/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
};
using namespace math;
const int N = 303;
vector<int> g[N];
int d[N][N], s;
mint dp[N][N];
void dfs(int v, int p) {
	for(auto i : g[v]) if(i != p) {
		d[s][i] = d[s][v]+1;
		dfs(i, v);
	}
}
int cc[N];
void uh(int v, int p, int r, int y) {
	if(v == y) return;
	cc[r]++;
	for(auto i : g[v]) if(i != p) {
		uh(i, v, d[v][y] > d[i][y] ? r+1 : r, y);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;f--,t--;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	for(int i = 0; i < n; i++)
		s = i, dfs(i, -1);
	mint i2 = 1/mint(2);
	dp[0][0] = 1;
	for(int x = 0; x+2 < N; x++) {
		for(int y = 0; y+2 < N; y++) {
			if(x) {
				dp[x][y] += dp[x-1][y]*i2;
				if(y>1)
					dp[x][y] += dp[x][y-1]*i2;
			} else {
				if(y)
					dp[x][y] += dp[x][y-1];	
			}
		}
	}
	mint ans = 0;
	for(int x = 0; x < n; x++) {
		for(int y = 0; y < x; y++) {
			memset(cc, 0, sizeof cc);
			uh(x, -1, 0, y);
			for(int i = 0; i < n; i++) {
				ans += dp[i][d[x][y]-i]*cc[i];
			}
		}
	}
	cout << ans/mint(n) << '\n';
}