#pragma GCC optimize("trapv")
#pragma GCC target("avx,avx2,ssse3,sse2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pair<int, int>>;
using namespace __gnu_pbds;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		if(empty()) return 0;
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
ll n;
vector<vi> g;
vi comp, sz, maxch, a;
bitset<150100> centr;
void sizes(int v, int p) {
    sz[v] = 1;
    maxch[v] = 0;
    comp.pb(v);
    for(auto i : g[v]) {
        if(i==p||centr[i]) continue;
        sizes(i, v);
        sz[v] += sz[i];
        maxch[v] = max(maxch[v], sz[i]);
    }
}
int find_centr(int v) {
    comp.clear();
    sizes(v, v);
    int c = comp[0];
    for(auto i : comp) {
        maxch[i] = max(maxch[i], (ll)comp.size()-sz[i]);
        if(maxch[c]>maxch[i]) c = i;
    }
    return c;
}
ll ans = 0;
LineContainer lc;

struct ctx {
	ll sum = 0, cur = 0, len = 0;
	void add(ll x) {
		sum += x;
		cur += sum;
		len++;
	}
	void rev(ll x) {
		sum += x;
		cur += x*(++len);
	}
	void insert() {
		lc.add(sum, cur);
	}
	ll find() {
		return lc.query(len) + cur;
	}
};

void add(int v, int p, ctx c) {
	//cout << v << " : " << c.sum << " " << c.cur << "\n";
	c.insert();
	ans = max(ans, c.cur);
	for(auto i : g[v]) {
        if(i==p||centr[i]) continue;
		ctx t = c;
		t.rev(a[i]);
		add(i, v, t);
	}
}
void check(int v, int p, ctx c) {
	ans = max(ans, c.find());
	ans = max(ans, c.cur);
	//cout << v << " " << c.cur << " => " << c.find() << "\n";
	for(auto i : g[v]) {
        if(i==p||centr[i]) continue;
		ctx t = c;
		t.add(a[i]);
		check(i, v, t);
	}
}

void decompose(int v = 1, int p = -1, int d = 0) {
    int c = find_centr(v);
    centr[c]=1;
    for(int i = 0; i < 2; i++) {
		lc.clear();
		ctx chk, ad;
		ad.add(a[c]);
		//cout << "CENTER" << c << "\n";
		for(auto i : g[c]) {
			if(centr[i]) continue;
			ctx t = chk;
			t.add(a[i]);
			check(i, c, t);
			t = ad;
			t.rev(a[i]);
			add(i, c, t);
		}
		//cout << "DONE\n";
		reverse(all(g[c]));
    }
    for(auto i : g[c]) {
        if(centr[i]) continue;
//        cout << c << " -> " << i << "\n";
        decompose(i, c, d+1);
    }
}

void decomposition() {
	comp.resize(n+1);
	sz.resize(n+1);
	maxch.resize(n+1);
	decompose(1, -1);
}

void read() {
	cin >> n;
	g.resize(n+1);
	a.resize(n+1);
	for(ll f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	for(int i = 1; i <= n; i++) cin >> a[i], ans = max(ans, a[i]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	decomposition();
	cout << ans;
	//cout << "DONE";
	return 0;
}