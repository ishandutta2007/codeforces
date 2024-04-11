// Problem: F.  
// Contest: Codeforces - Codeforces Global Round 18
// URL: https://codeforces.com/contest/1615/problem/F
// Memory Limit: 512 MB
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
}
using namespace math;
const int N = 2020;
mint dp[N][2*N], cnt[N][2*N];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		string s, t;
		int n = s.size();
		cin >> n >> s >> t;
		for(int i = 0; i <= n; i++)
			for(int j = -n; j <= n; j++)
				dp[i][N+j] = cnt[i][N+j] = 0;
		cnt[0][N] = 1;
		auto low = [&](string &x, int i) {
			return x[i] == '?' ? 0 : x[i]-'0';
		};
		auto high = [&](string &x, int i) {
			return x[i] == '?' ? 1 : x[i]-'0';
		};
		for(int i = 0; i <= n; i++) {
			for(int bal = -n; bal <= n; bal++) {
				// if(cnt[i][N+bal].v) {
					// cout << i << " " << bal << " " << cnt[i][N+bal] << " " << dp[i][N+bal] << endl;
				// }
				if(i==n) continue;
				for(int S = low(s, i); S <= high(s, i); S++)
					for(int T = low(t, i); T <= high(t, i); T++) {
						int nbal = 0;
						if(bal>0) {
							nbal = bal;
							nbal -= S;
							nbal += T;
							nbal *= -1;
						} else if(bal<0) {
							nbal = abs(bal);
							nbal -= !S;
							nbal += !T;
						} else {
							if(S != T)
								nbal = S ? 1 : -1;
						}
						// if(i == 1 && bal == -1) {
							// cout << S << " " << T << " " << nbal << " " << bal << " + " << -(!S) << " " << (!T) << ".." << endl;
						// }
						cnt[i+1][N+nbal] += cnt[i][N+bal];
						dp[i+1][N+nbal] += dp[i][N+bal] + cnt[i][N+bal]*abs(nbal);
					}
			}
		}
		cout << dp[n][N] << '\n';
	});
	
}