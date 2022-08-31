#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 205;
const int mod = 1e9 + 7;

template<typename T>
T gcd(const T &a, const T &b) {
    return b == T(0) ? a : gcd(b, a % b);
}

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

int n;
int adj[205][205];
mint fact[405], invf[405];

mint bino(int x, int y){
	assert(x >= y && y >= 0);
	return fact[x] * invf[x-y] * invf[y];
}

mint ibino(int x, int y){
	return invf[x] * fact[x-y] * fact[y];
}

mint dp[205][205];

mint solve(int r){
	mint ret = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < i; j++){

			int depi = adj[r][i];
			int depj = adj[r][j];
			int lca_dep = adj[r][i] + adj[r][j] - adj[i][j];
			assert(lca_dep % 2 == 0);
			lca_dep /= 2;
			depi -= lca_dep;
			depj -= lca_dep;
			if(depj == 0){
				continue;
			}
			if(depi == 0){
				ret += mint(1);
				continue;
			}
			ret += dp[depi][depj];
		}
	}
	return ret;
}

int main(){
	scanf("%d",&n);
	fact[0] = invf[0] = 1;
	for(int i = 1; i <= 2*n; i++){
		fact[i] = fact[i-1] * mint(i);
		invf[i] = mint(1) / fact[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 0; k <= j - 1; k++){
				dp[i][j] += bino(i+j-1, k);
			}
			dp[i][j] /= ipow(mint(2), i+j-1);
		}
	}
	memset(adj, 0x3f, sizeof(adj));
	for(int i = 1; i <= n; i++){
		adj[i][i] = 0;
	}
	for(int i = 1; i < n; i++){
		int s, e; scanf("%d %d",&s,&e);
		adj[s][e] = adj[e][s] = 1;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
			}
		}
	}
	mint ret = 0;
	for(int i = 1; i <= n; i++){
	//	cout << solve(i) << endl;
		ret += solve(i);
	}
	ret /= mint(n);
	cout << ret << endl;
}