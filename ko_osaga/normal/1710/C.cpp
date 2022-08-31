#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int MAXN = 200005;

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


string s;
int dp[MAXN][2][2][2][2][2];

int f(int pos, int ie, int je, int ke, int putx, int puty){
	if(pos == sz(s)) return putx && puty ? 6 : 3;
	if(~dp[pos][ie][je][ke][putx][puty]) return dp[pos][ie][je][ke][putx][puty];
	int ret = 0;
	for(int x = 0; x < 2; x++){
		for(int y = 0; y < 2; y++){
			if(x && y) continue;
			for(int z = 0; z < 2; z++){
				if(ie && (x^z) && s[pos] == '0') continue;
				if(je && (y^z) && s[pos] == '0') continue;
				if(ke && z && s[pos] == '0') continue;
				ret += f(pos + 1, 
				ie & ((x^z) == s[pos] - '0'),
				je & ((y^z) == s[pos] - '0'),
				ke & ((z) == s[pos] - '0'),
				putx | x,
				puty | y);
				if(ret >= mod) ret -= mod;
			}
		}
	}
	return dp[pos][ie][je][ke][putx][puty] = ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	mint N = 0;
	for(auto &x : s){
		N *= mint(2);
		if(x == '1') N+= mint(1);
	}
	mint dap = (N + mint(1)) * (N + mint(1)) * (N + mint(1)) - (N + mint(1));
	dap *= mint(2);
	memset(dp, -1, sizeof(dp));
	dap -= mint(f(0, 1, 1, 1, 0, 0));
	dap += mint(3) * (N + mint(1));
	dap /= mint(2);
	cout << dap << "\n";
}