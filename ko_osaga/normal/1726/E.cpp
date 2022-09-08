#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXN = 300005;
const int mod = 998244353; //1e9 + 7;//998244353;

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

mint dp[MAXN];
mint dfac[MAXN];
mint pwr[MAXN], fact[MAXN], invf[MAXN];

mint bino(int x, int y){
	return fact[x] * invf[y] * invf[x - y];
}
int main(){	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	dp[0] = dfac[0] = pwr[0] = 1;
	fact[0] = invf[0] = 1;
	for(int i = 1; i < MAXN; i++){
		dp[i] = dp[i - 1];
		if(i > 1){
			dp[i] += dp[i - 2] * mint(i - 1);
		}
		dfac[i] = dfac[i - 1] * mint(2 * i - 1);
		pwr[i] = pwr[i - 1] * mint(2);
		fact[i] = fact[i-1] * mint(i);
		invf[i] = mint(1) / fact[i];
	}
	while(t--){
		int n; cin >> n;
		mint ret = 0;
		for(int d = 0; d * 4 <= n; d++){
			ret += pwr[d] * bino(n - 2 * d, 2 * d) * dfac[d] * dp[n - 4 * d];
		}
		cout << ret << "\n";
	}
}