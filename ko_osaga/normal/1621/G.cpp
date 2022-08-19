#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<lint, lint>;
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

struct node{
	lint sum, opt, pfx, sfx;
	node(){
		sum = opt = pfx = sfx = 0;
	}
	node(lint x){
		sum = x;
		opt = pfx = sfx = min(x, 0ll);
	}
	node operator+(const node &n)const{
		node ret;
		ret.sum = sum + n.sum;
		ret.pfx = min(pfx, sum + n.pfx);
		ret.sfx = min(n.sfx, n.sum + sfx);
		ret.opt = min({opt, n.opt, sfx + n.pfx});
		return ret;
	}
};

struct bit{
	vector<mint> tree;
	void init(int n){
		tree.clear();
		tree.resize(n);
	}
	void add(int x, mint v){
		for(int i = x; i < sz(tree); i += i & -i){
			tree[i] += v;
		}
	}
	mint query(int x){
		mint ret = 0;
		for(int i = x; i; i -= i & -i) ret += tree[i];
		return ret;
	}
}bit;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q; cin >> q;
	while(q--){
		int n; cin >> n;
		vector<int> a(n), v;
		for(int i = 0; i < n; i++) cin >> a[i];
		v = a;
		sort(all(v));
		v.resize(unique(all(v)) - v.begin());
		for(auto &i : a){
			i = lower_bound(all(v), i) - v.begin() + 1;
		}
		vector<mint> dp(n), rdp(n);
		mint tot = 0;
		bit.init(n + 5);
		for(int i = 0; i < n; i++){
			dp[i] = mint(1) + bit.query(a[i] - 1);
			bit.add(a[i], dp[i]);
		}
		bit.init(n + 5);
		for(int i = n - 1; i >= 0; i--){
			rdp[i] = mint(1) + bit.query(n + 3) - bit.query(a[i]);
			bit.add(a[i], rdp[i]);			
			tot += dp[i] * rdp[i];
		}
		bit.init(n + 5);
		vector<pi> pts;
		for(int i = n - 1; i >= 0; i--){
			pts.emplace_back(a[i], i);
		}
		sort(all(pts), [&](const pi &a, const pi &b){
			return pi(a.first, -a.second) < pi(b.first, -b.second);
		});
		for(int i = n - 1; i >= 0; ){
			int j = i;
			while(j >= 0 && pts[j].second <= pts[i].second) j--;
			vector<int> v;
			for(int k = j + 1; k <= i; k++){
				v.push_back(pts[k].second);
			}
			sort(all(v));
			vector<mint> rdp(sz(v));
			rdp[sz(v) - 1] = 1;
			for(int i = sz(v) - 1; i >= 0; i--){
				rdp[i] += bit.query(n + 3) - bit.query(a[v[i]]);
				bit.add(a[v[i]], rdp[i]);
				tot -= dp[v[i]] * rdp[i];
			}
			for(int i = 0; i < sz(v); i++) bit.add(a[v[i]], -rdp[i]);
			i = j;
		}
		cout << tot << "\n";
	}
}