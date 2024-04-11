#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int MAXN = 3000050;
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
};

mint fact[MAXN], invf[MAXN];
mint dp[MAXN];

mint bino(int x, int y){
	return fact[x] * invf[y] * invf[x-y];
}

int main(){
	int n, q;
	scanf("%d %d",&n,&q);
	fact[0] = invf[0] = mint(1);
	for(int i = 1; i <= 3*n + 5; i++){
		fact[i] = fact[i-1] * mint(i);
	}
	invf[3*n+5] = mint(1) / fact[3*n+5];
	for(int i = 3*n+4; i>0; i--){
		invf[i] = invf[i+1] * mint(i+1);
	}
	dp[0] = mint(n + 1);
	for(int j = 0; j <= 3*n; j+=3) dp[1] += mint(j);
	for(int j = 2; j <= 3*n; j++){
		dp[j] = bino(3*n+3, j+1) - dp[j-2] - mint(3)*dp[j-1];
		dp[j] *= mint((mod + 1) / 3);
	}
	for(int i = 0; i < q; i++){
		int x; scanf("%d",&x);
		printf("%lld\n", dp[x]);
	}
}