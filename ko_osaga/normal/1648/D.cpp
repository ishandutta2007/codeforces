#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int mod = 998244353;
const int MAXN = 500005;
const int MAXT = 1500005;

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

struct edg{
	int s, e, x;
	bool operator<(const edg &e)const{
		return s < e.s;
	}
};

struct seg{
	pi tree[MAXT];
	int lim;
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
		fill(tree, tree + MAXT, pi(-1e18, -1));
	}
	void upd(int x, pi v){
		x += lim;
		tree[x] = v;
		while(x > 1){
			x >>= 1;
			tree[x] = max(tree[2*x], tree[2*x+1]);
		}
	}
	pi query(int s, int e){
		s += lim;
		e += lim;
		pi ret(-1e18, -1);
		while(s < e){
			if(s%2 == 1) ret = max(ret, tree[s++]);
			if(e%2 == 0) ret = max(ret, tree[e--]);
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = max(ret, tree[s]);
		return ret;
	}
}seg;

struct node{
	lint lmin, rmin;
	lint comb;
	node operator+(const node &n)const{
		return (node){
			min(lmin, n.lmin),
			min(rmin, n.rmin),
			min({comb, n.comb, lmin + n.rmin})};
	}
};

node inf = (node){lint(1e18), lint(1e18), lint(1e18)};

struct seg2{
	node tree[MAXT];
	int lim;
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
		fill(tree, tree + MAXT, inf);
	}
	void upd(int x, node v){
		x += lim;
		tree[x] = v;
		while(x > 1){
			x >>= 1;
			tree[x] = tree[2*x] + tree[2*x+1];
		}
	}
	lint query(int s, int e){
		s += lim;
		e += lim;
		lint ret = 1e18;
		node L = inf, R = inf;
		while(s < e){
			if(s%2 == 1) L = L + tree[s++];
			if(e%2 == 0) R = tree[e--] + R;
			s >>= 1;
			e >>= 1;
		}
		if(s == e) L = L + tree[s];
		return (L + R).comb;
	}
}seg2;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m; cin >> n >> m;
	vector<lint> f(n+1), g(n+1), h(n+1);
	for(int i = 1; i <= n; i++){
		cin >> f[i]; f[i] *= -1;
		f[i] += f[i-1];
	}
	for(int i = 1; i <= n; i++){
		cin >> g[i]; g[i] *= -1;
		g[i] += g[i-1];
	}
	for(int i = 1; i <= n; i++){
		cin >> h[i];
		h[i] *= -1;
	}
	for(int i = n-1; i >=0; i--) h[i] += h[i + 1];
	vector<lint> dist(n + 1, 1e18);
	vector<vector<pi>> gph(n + 1);
	priority_queue<pi, vector<pi>, greater<pi> > pq;
	
	auto enq = [&](int x, lint v){
		if(dist[x] > v){
			dist[x] = v;
			pq.emplace(v, x);
		}
	};

	vector<edg> w;
	for(int i = 0; i < m; i++){
		int s, e, x; cin >> s >> e >> x;
		w.push_back({s - 1, e, x});
	}
	sort(all(w));
	seg.init(m);
	for(int i = 0; i < m; i++){
		seg.upd(i, pi(w[i].e, i));
	}
	for(int i = 1; i <= n; i++){
		enq(i - 1, f[i] - g[i - 1]);
	}
	lint ret = 1e18;
	while(sz(pq)){
		auto x = pq.top(); pq.pop();
		int v = x.second;
		if(dist[v] != x.first) continue;
		int idx = lower_bound(all(w), (edg){v + 1, -1, -1}) - w.begin();
		while(true){
			auto x = seg.query(0, idx - 1);
			if(x.first > v){
				int nidx = x.second;
				enq(w[nidx].e, w[nidx].x + dist[v]);
				seg.upd(nidx, pi(-1e18, -1));
			}
			else break;
		}
	}
	seg2.init(n);
	for(int i = 0; i <= n; i++){
		seg2.upd(i, (node){dist[i], g[i] + h[i], (lint)1e18});
	}
	for(auto &e : w){
		ret = min(ret, seg2.query(e.s, e.e) + e.x);
	}
	cout << -ret << "\n";
}