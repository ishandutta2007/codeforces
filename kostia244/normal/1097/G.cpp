// Problem: G. Vladislav and a Great Legend
// Contest: Codeforces - Hello 2019
// URL: https://codeforces.com/contest/1097/problem/G
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<iostream>
#include<vector>
#include<array>

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

const int N = 1e5 + 15, K = 215;
int n, k, sz[N];
vector<int> g[N];
array<mint, K> def, sum;
mint S[K][K];
mint i2 = mint(2).pow(mod-2);
array<mint, K> dp[N], chi[N];
array<mint, K> dfs(int v, int p) {
	#define dp dp[v]
	#define chi chi[v]
	#define wchi wchi[v]
	dp = def, chi = def;
	dp[0] = 1;
	sz[v] = 1;
	mint si = mint(2).pow(n)-1;
	for(auto u : g[v]) if(u != p) {
		auto c = dfs(u, v), ndp = def;
		mint coef = mint(2).pow(mod-1-sz[u]);
		for(int i = 1; i <= k; i++)
			chi[i] += c[i]*coef;
		coef = mint(2).pow(n-sz[u])-1;
		for(int i = 1; i <= k; i++)
			sum[i+1] += c[i]*coef;
		for(int i = 0; i <= sz[v]; i++)
			for(int j = 0; j <= sz[u] && i+j <= k; j++) {
				ndp[i+j] += dp[i]*c[j];
			}
		dp = ndp;
		sz[v] += sz[u];
		si -= mint(2).pow(sz[u])-1;
	}
	mint over;
	over = mint(2).pow(sz[v]-1);
	for(auto &i : chi) i *= over;
	//don't take v
	over = mint(2).pow(n-sz[v]+1);
	for(int i = 1; i <= k; i++) {
		sum[i] += (dp[i]-chi[i])*over;
	}
	//take v
	over = mint(2).pow(n-sz[v]+1);
	for(int i = 1; i < k; i++) {
		sum[i+1] += (dp[i]-chi[i])*over;
	}
	sum[1] += si - mint(2).pow(n-sz[v]) + 1;
	for(int i = k; i >= 0; i--)
		dp[i] = 2*(dp[i] + (i<2?0:dp[i-1]));
	dp[1] += dp[0]-1;
	return dp;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	calc_combi();
	for(int i = 0; i < K; i++) {
		for(int j = 0; j <= i; j++) {
			if(!i) S[i][j] = 1;
			else if(!j) S[i][j] = 0;
			else S[i][j] = S[i-1][j]*j + S[i-1][j-1];
		}	
	}
	for(int i = 0; i < K; i++)
		for(int j = 0; j <= i; j++)
			S[i][j] *= fact[j];
	def.fill(0);
	sum = def;
	cin >> n >> k;
	sum[0] = mint(2).pow(n)-1;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	dfs(1, 0);
	mint ans = 0;
	// for(int x = 0; x <= k; x++) cout << sum[x] << " "; cout << endl; 
	// sum[2] = nv(5);
	// sum[3] = nvv(5);
	// cout << sum[3] << " " << nvv(5) << endl;
	for(int x = 0; x <= k; x++) {
		mint coef = 0;
		for(int i = 0; i <= x; i++) {
			coef += S[x][i]*sum[i];
			// cout << S[x][i] << "*" << sum[i] << " ";
		}
		//cout << x << " " << coef << endl;
		// cout << endl;
		//cout << x << " " << coef << " " << nck(k, x)*mint((k-x)&1?-1:1)<< endl;
		ans += nck(k, x)*mint((k-x)&1?-1:1)*coef;
	}
	cout << ans << '\n';
}