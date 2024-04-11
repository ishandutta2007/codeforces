#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 400005;
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
int x[MAXN], y[MAXN], s[MAXN];
int nxt[MAXN], prv[MAXN];
mint dp[MAXN], go[MAXN];

int main(){
	scanf("%d",&n);
	vector<int> v;
	for(int i = 1; i <= n; i++){
		scanf("%d %d %d",&x[i],&y[i],&s[i]);
		v.push_back(x[i]);
		v.push_back(y[i]);
		s[i] ^= 1;
	}
	v.push_back(0);
	v.push_back(x[n] + 1);
	sort(all(v));
	for(int i = 1; i <= n; i++){
		int p = lower_bound(all(v), x[i]) - v.begin();
		int q = lower_bound(all(v), y[i]) - v.begin();
		nxt[p] = i;
		prv[q] = i;
	}
	mint ret = 0;
	for(int i = sz(v) - 2; i >= 0; i--){
		dp[i] = 1;
		if(nxt[i+1]){
			dp[i] = dp[i + 1] * mint(2) - mint(s[nxt[i+1]]);
			go[nxt[i+1]] = dp[i + 1] - mint(s[nxt[i+1]]);
		}
		else if(prv[i+1]){
			dp[i] = dp[i + 1] - go[prv[i+1]];
		}
		else{
			assert(i == sz(v) - 2);
		}
		ret += dp[i] * mint(v[i+1] - v[i]);
	}
	cout << ret << endl;
}