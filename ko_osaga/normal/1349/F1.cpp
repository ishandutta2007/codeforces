#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 5005;
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

int n;
mint dp[MAXN][MAXN];
mint fact[MAXN], invf[MAXN];

int main(){
	dp[1][1] = mint(1);
	for(int i=2; i<MAXN; i++){
		for(int j=1; j<=i; j++){
			dp[i][j] = dp[i-1][j] * mint(j) + dp[i-1][j-1] * mint(i-j+1);
		}
	}
	fact[0] = invf[0] = 1;
	for(int i=1; i<MAXN; i++){
		fact[i] = fact[i-1] * mint(i);
		invf[i] = mint(1) / fact[i];
	}
	cin >> n;
	for(int i=1; i<=n; i++){
		mint ret = 0;
		for(int j=i; j<=n; j++){
			ret += fact[n] * invf[j] * dp[j][i];
		}
		printf("%lld ", (lint)ret);
	}
}