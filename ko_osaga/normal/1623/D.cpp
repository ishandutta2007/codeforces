#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;

const int mod = 1e9 + 7;

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
int norm(int x, int d){
	x %= (2 * d - 2);
	if(x >= d) return 2 * d - 2 - x;
	return x;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int q; cin >> q;
	while(q--){
		int n, m, rx, cx, ry, cy;
		cin >> n >> m >> rx >> cx >> ry >> cy;
		rx--; cx--; ry--; cy--;
		int period = (2 * n - 2) * (2 * m - 2) / gcd(2 * n - 2, 2 * m - 2); 
		vector<int> vect;
		for(int i = 0; i < period; i++){
			if(norm(rx, n) == ry % n || norm(cx, m) == cy % m){
				vect.push_back(i);
			}
			rx++;
			cx++;
		}
		int p; cin >> p;
		mint prob = mint(100 - p) / mint(100);
		mint ret = 0;
		for(int i = 0; i < sz(vect); i++){
			mint W = mint(1) / (mint(1) - ipow(prob, sz(vect)));
			ret += mint(vect[i]) * (mint(1) - prob) * ipow(prob, i) * W;
			ret += mint(period) * (mint(1) - prob) * ipow(prob, i + sz(vect)) * W * W;
		}
		cout << ret << "\n";
	}
}