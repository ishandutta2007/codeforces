#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
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

int n, m;
mint fact[MAXN], invf[MAXN];

struct bit{
	int tree[MAXN];
	void add(int x, int v){
		for(int i = x; i < MAXN; i+= i&-i) tree[i] += v;
	}
	int kth(int x){
		int pos = 0;
		for(int i = 18; i >= 0; i--){
			if(pos + (1<<i) < MAXN && tree[pos + (1<<i)] < x){
				pos += (1<<i);
				x -= tree[pos];
			}
		}
		return pos + 1;
	}
}bit;

int main(){
	int t; scanf("%d",&t);
	fact[0] = invf[0] = 1;
	for(int i = 1; i < MAXN; i++){
		fact[i] = fact[i-1] * mint(i);
		invf[i] = mint(1) / fact[i];
		bit.add(i, 1);
	}
	while(t--){
		scanf("%d %d",&n,&m);
		vector<pi> v, w;
		for(int i = 0; i < m; i++){
			int x, y;
			scanf("%d %d",&x,&y);
			v.emplace_back(x, y);
		}
		sort(all(v));
		for(int i = sz(v) - 1; i >= 0; i--){
			int qq = bit.kth(v[i].second);
			bit.add(qq, -1);
			w.emplace_back(qq, v[i].first);
		}
		int bars = m;
		sort(all(w));
		for(int i = 1; i < sz(w); i++){
			if(w[i-1].first + 1 == w[i].first && w[i-1].second < w[i].second) bars--;
		}
		bars = n - 1 - bars;
		mint ret = fact[bars+n] * invf[n] * invf[bars];
		printf("%lld\n", (lint)ret);
		for(auto &i : w) bit.add(i.first, +1);
	}
}