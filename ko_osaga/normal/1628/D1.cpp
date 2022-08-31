#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
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

const int MAXN = 2005;

mint dp[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i = 1; i <= 2000; i++){
		for(int j = 1; j < i; j++){
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			dp[i][j] *= mint((mod + 1) / 2);
		}
		dp[i][i] = dp[i-1][i-1] + mint(1);
	}
	int t; cin >> t;
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		cout << dp[n][m] * mint(k) << "\n";
	}
	/*
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		vector<int> pmex;
		set<int> s;
		int p = 0;
		for(auto &i : a){
			cin >> i;
			s.insert(i);
			while(s.count(p)) p++;
			pmex.push_back(p);
		}
		cout << sz(pmex) << endl; 
		reverse(all(pmex));

	}*/
}