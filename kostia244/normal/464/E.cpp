#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int maxn = 1<<17, mod = 1e9 + 7;
int B = rng()%69 + 100;
int pw[maxn+200], pws[maxn+200];
struct node {
	node *l, *r;
	int hash, lazy;
	node(int val = 0) : hash(val), lazy(-1), l(0), r(0) {}
};
using pnode = node*;
deque<node> buffer;
pnode newnode() {
	buffer.emplace_back();
	return &buffer.back();
}
pnode broken = newnode();
pnode copy(pnode x) {
	pnode z = newnode();
	if(!x) return z;
	z->hash = x->hash, z->lazy = x->lazy;
	z->l = x->l, z->r = x->r;
	return z;
}
pnode apply(pnode v, int l, int r, int lazy) {
	pnode t = copy(v);
	t->lazy = lazy;
	t->hash = lazy*pws[r-l];
	return t;
}
void push(pnode x, int l, int r) {
	if(!x || x->lazy == -1 || l == r) return;
	int mid = (l+r)/2;
	x->l = apply(x->l, l, mid, x->lazy);
	x->r = apply(x->r, mid+1, r, x->lazy);
	x->lazy = -1;
}
pnode merge(pnode l, pnode r, int L, int R) {
	pnode v = newnode();
	int mid = (L+R)/2;
	v->l = l, v->r = r;
	v->hash = ((l?l->hash:0) + (r?r->hash:0)*1ll*pw[mid-L+1])%mod;
	return v;
}
pnode update(pnode v, int l, int r, int ql, int qr, int x) {
	push(v, l, r);
	if(qr < l || ql > r) return v;
	if(ql <= l && r <= qr)
		return apply(v, l, r, x);
	int mid = (l+r)/2;
	return merge(update(v?v->l:0, l, mid, ql, qr, x), update(v?v->r:0, mid+1, r, ql, qr, x), l, r);
}
int first_zero(pnode v, int l, int r, int ql) {
	push(v, l, r);
	if(r < ql) return -1;
	if(!v) return max(ql, l);
	if(v->hash == pws[r-l]) return -1;
	if(l == r) {assert(!v->hash); return l;}
	int mid = (l+r)/2;
	int t = first_zero(v->l, l, mid, ql);
	if(t == -1) t = first_zero(v->r, mid+1, r, ql);
	return t;
}
int cmp(pnode a, pnode b, int l, int r) {//-1 a is smaller, 0 euqal, 1 b is smaller
	push(a, l, r), push(b, l, r);
	if((a?a->hash:0) == (b?b->hash:0)) return 0;
	if(l == r) return (a?a->hash:0) < (b?b->hash:0) ? -1 : 1;
	int mid = (l+r)/2;
	int t = cmp(a?a->r:0, b?b->r:0, mid+1, r);
	if(!t) t = cmp(a?a->l:0, b?b->l:0, l, mid);
	return t;
}

int po2 = 1, ans = 0;
void getval(pnode v, int l, int r) {
	if(l == r) {
		ans = (ans + po2*(v&&v->hash))%mod;
		po2 = po2*2ll%mod;
		return;
	}
	int mid = (l+r)/2;
	getval(v?v->l:0, l, mid);
	getval(v?v->r:0, mid+1, r);
}
int getval(pnode v) {
	po2 = 1, ans = 0;
	getval(v, 0, maxn);
	return ans;
}

pnode add(pnode v, int x) {
	//cout << getval(v) << " " << x << " = ";
	int pos = first_zero(v, 0, maxn, x);
	if(pos == -1) exit(69);
	if(pos != x) {
		//cout << "(" << x << " " << pos << ")";
		v = update(v, 0, maxn, x, pos-1, 0);
	}
	v = update(v, 0, maxn, pos, pos, 1);
	//cout << getval(v) << '\n';
	return v;
}

struct fuckmylife {
	bool operator()(const pair<pnode, int> &a, const pair<pnode, int> &b) const {
		//cout << "Compare " << getval(a.first) << " " << getval(b.first) << '\n';
		int t = [&]() {
			if(a.first == broken && b.first == broken) return 0;
			if(a.first == broken || b.first == broken) return a.first == broken ? 1 : -1;
			return cmp(a.first, b.first, 0, maxn);
		}();
		//cout << "Result is " << t << endl;
		if(t != 0) return t == 1;
		return a.second > b.second;
	}
};
int n, m;
vector<array<int, 2>> g[maxn];
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	pws[0] = pw[0] = 1;
	for(int i = 1; i < maxn+200; i++) pw[i] = pw[i-1] * 1ll * B % mod;
	for(int i = 1; i < maxn+200; i++) pws[i] = (pws[i-1] + pw[i])%mod;
	cin >> n >> m;
	map<pair<int, int>, int> ew;
	for(int f, t, c, i = 0; i < m; i++) {
		cin >> f >> t >> c;
		ew[{f, t}] = ew[{t, f}] = c;
		g[f].push_back({t, c});
		g[t].push_back({f, c});
	}
	vector<pnode> dist(n+1, broken);
	vector<int> p(n+1, -1);
	priority_queue<pair<pnode, int>, vector<pair<pnode, int>>, fuckmylife> pq;
	auto relax = [&](int v, pnode D, int par) {
		if(dist[v] == broken || cmp(dist[v], D, 0, maxn) == 1) {
			dist[v] = D;
			p[v] = par;
			pq.push({dist[v], v});
		}
	};
	int s, t; cin >> s >> t;
	pnode zero = newnode();
	relax(s, zero, 0);
	vector<int> vis(n+1);
	while(!pq.empty()) {
		auto [cst, v] = pq.top();
		pq.pop();
		if(cst != dist[v]) continue;
		//cout << v << " --- " << getval(cst) << endl;
		assert(!vis[v]++);
		for(auto [dest, w] : g[v]) {
			//cout << v << " -> " << dest << " | " << w << " " << getval(dist[v]) << '\n';
			relax(dest, add(dist[v], w), v);
		}
	}
	if(dist[t] == broken) return cout << "-1\n", 0;
	vector<int> go;
	ll gay = 0;
	auto uwu = [](int a, int p) {
		int r = 1;
		while(p) {
			if(p&1) r= r*1ll*a%mod;
			a=a*1ll*a%mod,p>>=1;
		}
		return r;
	};
	while(t) {
		go.push_back(t);
		if(p[t])
		gay = (gay + uwu(2, ew[{p[t], t}]))%mod;
		t = p[t];
	}
	reverse(all(go));
	cout << gay << '\n';
	cout << go.size() << '\n';
	for(auto &i : go) cout << i << " "; cout << '\n';
}
//111110
//000001