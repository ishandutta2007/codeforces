#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 500100;
const long long INF = 1e18;
long long n, x, l[N], r[N], d[N], lazy[4 * N], st[4 * N], p, w, q, ans[N];

pair<long long, long long> leaf[N];
vector <pair<long long, long long> > v[N];
vector <long long> que[N];

void push(long long node, long long l, long long r) {
	if(lazy[node]) {
		st[node] += lazy[node];
		lazy[2 * node] += lazy[node];
		lazy[2 * node + 1] += lazy[node];
		lazy[node] = 0;
	}
}

inline long long value(long long node) {
	return st[node] + lazy[node];
}

void upd(long long node, long long l, long long r, long long x, long long y, long long val) {
	// dbg(node,l , r, x, y);
	push(node, l, r);

	if(x <= l && r <= y) return void(lazy[node] = val);

	long long mid = (l + r) / 2;
	if(x <= mid) upd(2 * node, l, mid, x, y, val);
	if(mid < y) upd(2 * node + 1, mid + 1, r, x, y, val);

	st[node] = min(value(2 * node), value(2 * node + 1));
}

long long query(long long node, long long l, long long r, long long x, long long y) {
	push(node, l, r);

	if(x <= l && r <= y) return st[node];
	long long mid = (l + r) / 2, ret = INF;
	if(x <= mid) ret = query(2 * node, l, mid, x, y);
	if(mid < y) ret = min(ret, query(2 * node  +1, mid + 1, r, x, y));
	return ret;
}


void dfs(long long node, long long dpt = 0) {
	d[node] = dpt;
	// if(v[node].size() == 0) 
		leaf[node] = {node, node};
	// leaf[node] = {}
	for(auto i : v[node]) {
		dfs(i.st, dpt + i.nd);
		leaf[node].st = min(leaf[node].st, leaf[i.st].st);
		leaf[node].nd = max(leaf[node].nd, leaf[i.st].nd);
	}
}

void dfs2(long long node) {

	// dbg(node);
	for(auto i : que[node])
		ans[i] = query(1, 1, n, l[i], r[i]);

	for(auto i : v[node]) {
		upd(1, 1, n, 1, leaf[i.st].st - 1, i.nd);
		upd(1, 1, n, leaf[i.st].st, leaf[i.st].nd, -i.nd);
		upd(1, 1, n, leaf[i.st].nd + 1, n, i.nd);
		dfs2(i.st);
		upd(1, 1, n, 1, leaf[i.st].st - 1, -i.nd);
		upd(1, 1, n, leaf[i.st].st, leaf[i.st].nd, +i.nd);
		upd(1, 1, n, leaf[i.st].nd + 1, n, -i.nd);
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	// n = 10;
	// upd(1, 1, n, 2, 5, 5);
	// upd(1, 1, n, 1, 2, -2);
	// upd(1, 1, n, 5, 6, 1);
	// dbg(query(1, 1, n, 4, 5));
	// upd(1, 1, n, 2, 5, 5);
	// upd(1, 1, n, 2, 5, 5);
	// return 0;	

	cin >> n >> q;
	for(long long i = 2; i <= n; i++) {
		cin >> p >> w;
		v[p].push_back({i, w});
	}

	for(long long i = 1; i <= q; i++) {
		cin >> x >> l[i] >> r[i];
		que[x].push_back(i);
	}

	dfs(1);
	// dbg_v(d, n + 1);

	for(long long i = 1; i <= n; i++)
		if(v[i].size() == 0)
			upd(1, 1, n, i, i, d[i]);
		else 
			upd(1, 1, n, i, i, INF);
	dbg_ok;

	dfs2(1);
	for(long long i = 1; i <= q; i++)
		cout << ans[i] << '\n';
}