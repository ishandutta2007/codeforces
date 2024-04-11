#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int mod = 998244353;
const int MAXN = 200005;

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


struct bit{
	int tree[MAXN];
	void add(int x, int v){
		for(int i = x; i < MAXN; i+=i&-i) tree[i] += v;
	}
	int query(int x){
		int ret = 0;
		for(int i = x; i; i-=i&-i) ret += tree[i];
		return ret;
	}
}bit;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> scnt(MAXN), tcnt(MAXN);
	vector<int> s(n), t(m);
	for(auto &i : s) cin >> i, scnt[i]++, bit.add(i, 1);
	for(auto &i : t) cin >> i, tcnt[i]++;
	mint ret = 0;
	mint totalPoss = 1;
	for(int i = 1; i <= n; i++) totalPoss *= mint(i);
	for(auto &i : scnt){
		for(int j = 2; j <= i; j++) totalPoss /= mint(j);
	}
	for(int i = 0; i <= sz(s); i++){
		// lcp is i, because
		if(i == sz(t)){
			// t ended (then can't small)
			break;
		}
		else if(i < sz(s)){
			// count all starts strictly smaller than ti
			mint newPoss = totalPoss / mint(sz(s) - i);
			ret += newPoss * mint(bit.query(t[i] - 1));
		}
		else if(i == sz(s)){
			ret += mint(1);
		}
		if(i < sz(s)){
			totalPoss /= mint(sz(s) - i);
			totalPoss *= mint(scnt[t[i]]);
			scnt[t[i]]--;
			tcnt[t[i]]--;
			bit.add(t[i], -1);
			if(scnt[t[i]] < 0) break;
		}
	}
	cout << ret << "\n";
}