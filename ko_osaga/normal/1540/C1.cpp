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

int n, c[105], b[105];
int L[105];
mint dp[105][10005];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n - 1; i++){
		cin >> b[i];
		b[i] += b[i-1];
	}
	int q; cin >> q;
	for(int i = 0; i < q; i++){
		int x; cin >> x;
		int cursum = 0;
		for(int j = 1; j <= n; j++){
			L[j] = x * j + cursum;
			L[j] = max(L[j], 0);
			cursum += b[j];
		}
		dp[0][0] = 1;
		int sum = 0;
		mint ret = 0;
		for(int i = 1; i <= n; i++){
			sum += c[i];
			for(int j = L[i]; j <= sum; j++){
				for(int k = 0; k <= j && k <= c[i]; k++){
					dp[i][j] += dp[i-1][j-k];
				}
				if(i == n) ret += dp[i][j];
			}
		}
		cout << ret << endl;
		for(int j = 0; j < 105; j++){
			for(int k = 0; k < 10005; k++){
				dp[j][k] = 0;
			}
		}
	}
}