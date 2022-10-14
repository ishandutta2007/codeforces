#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int C = 400, N = 2e5 + 15 + C;
int n, q, tin[N], tout[N], timer = 0;
vector<int> g[N];

int en[N], bl[N];
ll _A[N], _B[N], a[N], b[N], add[N/C];
vector<int> ord[N/C];

struct Cht {
	deque<array<ll, 2>> lines;
	__int128 cross(array<ll, 2> a, array<ll, 2> b) {
		return a[0]*__int128(b[1])-__int128(a[1])*b[0];
	}
	ll dot(array<ll, 2> a, array<ll, 2> b) {
		return a[0]*b[0]+a[1]*b[1];
	}
	bool kill(array<ll, 2> v) {
		if(lines.size() < 2) return 0;
		array<ll, 2> A = {end(lines)[-2][0]-lines.back()[0],
			end(lines)[-2][1]-lines.back()[1]};
		array<ll, 2> B = {lines.back()[0]-v[0],
			lines.back()[1]-v[1]};
		return cross(A, B) >= 0;
	}
	void add_line(ll k, ll c) {
		array<ll, 2> pt = {k, c};
		while(kill(pt))
			lines.pop_back();
		lines.push_back(pt);
	}
	ll query(ll x) {
		array<ll, 2> pt = {x, 1};
		while(lines.size() > 1 && dot(pt, lines[0]) <= dot(pt, lines[1]))
			lines.pop_front();
		return dot(pt, lines[0]);
	}
};

Cht cht[N/C], mcht[N/C];

void dfs(int v) {
	tin[v] = timer++;
	for(auto i : g[v]) {
		_A[i] += _A[v];
		_B[i] += _B[v];
		dfs(i);
	}
	tout[v] = timer;
}
bool cmp(int x, int y) { return b[x]<b[y]; }
int here = 0;
void upd(int l, int r, int x) {
	int id = bl[l];
	if(r-l == C) {//whole block
		add[id] += x;
		return;
	}
	if(l != r) {
		for(int i = l; i < r; i++)
			a[i] += x;
	}
	for(int i = id*C; i < min(n, en[l]); i++) {
		a[i] += add[id];
	}
	add[id] = 0;
	cht[id].lines.clear();
	mcht[id].lines.clear();
	for(auto i : ord[id])
		cht[id].add_line(b[i], a[i]*b[i]);
	for(int I = ord[id].size(); I--;) {
		int i = ord[id][I];
		mcht[id].add_line(-b[i], -a[i]*b[i]);
	}
}
ll qry(int l, int r) {
	int id = bl[l];
	if(r-l == C) {//whole block
		return max(mcht[id].query(add[id]), cht[id].query(add[id]));
	}
	ll ans = -1;
	for(; l < r; l++) {
		ans = max(ans, abs(a[l]+add[id])*b[l]);
	}
	return ans;
}

void build() {
	for(int i = 0; i*C < n; i++) {
		int sz = min(C, n-i*C);
		ord[i].resize(sz);
		iota(all(ord[i]), i*C);
		sort(all(ord[i]), cmp);
		upd(i*C, i*C, 0);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	for(int i = 0; i*C+C <= N; i++)
		for(int j = 0; j < C; j++)
			en[i*C+j] = i*C+C, bl[i*C+j] = i;
	cin >> n >> q;
	for(int t, i = 2; i <= n; i++) {
		cin >> t;
		g[t].push_back(i);
	}
	for(int i = 1; i <= n; i++) cin >> _A[i];
	for(int i = 1; i <= n; i++) cin >> _B[i];
	dfs(1);
	for(int t, i = 1; i <= n; i++) {
		a[tin[i]] = _A[i];
		b[tin[i]] = abs(_B[i]);
	}
	build();
	for(int t, v, x; q--;) {
		cin >> t >> v;
		int l = tin[v], r = tout[v];
		if(t == 1) {
			cin >> x;
			while(l < r) {
				upd(l, min(r, en[l]), x);
				l = en[l];
			}
		} else {
			ll ans = -1;
			while(l < r) {
				ans = max(ans, qry(l, min(en[l], r)));
				l = en[l];
			}
			cout << ans << '\n';
		}
	}
}