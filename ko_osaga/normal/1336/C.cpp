#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 3005;
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

int n, m;
char s[MAXN], t[MAXN];
int dp[MAXN][MAXN];

bool mism(int p, int q){
	if(p >= m) return 0;
	return t[p] != s[q];
}

mint f(int x, int y){
	if(~dp[x][y]) return dp[x][y];
	int ptr = y - x;
	mint ret = 0;
	if(y >= m && x == 0) ret = 1;
	if(x > 0 && !mism(x - 1, y - x)) ret += f(x - 1, y);
	if(y < n && !mism(y, y - x)) ret += f(x, y + 1);
	return dp[x][y] = ret;
}

int main(){
	cin >> s >> t;
	n = strlen(s);
	m = strlen(t);
	memset(dp, -1, sizeof(dp));
	mint ret = 0;
	for(int i=0; i<=n; i++){
		ret += f(i, i);
	}
	cout << ret << endl;
}