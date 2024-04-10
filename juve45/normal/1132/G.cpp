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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 1001000;
int n, a[N], nxt[N], k, pos[N];
stack<int> s;
vector <int> euler;

const int INF = 1e9;
int lazy[4 * N], st[4 * N];
 
pair<int, int> leaf[N];
vector <int> v[N];
 
void push(int node, int l, int r) {
	if(lazy[node]) {
		st[node] += lazy[node];
		if(l != r) {
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
 
inline int value(int node) {
	return st[node] + lazy[node];
}
 
void upd(int node, int l, int r, int x, int y, int val) {
	push(node, l, r);
	if(x <= l && r <= y) return void(lazy[node] = val);
 
	int mid = (l + r) / 2;
	if(x <= mid) upd(2 * node, l, mid, x, y, val);
	if(mid < y) upd(2 * node + 1, mid + 1, r, x, y, val);
 
	st[node] = max(value(2 * node), value(2 * node + 1));
}
 
int query(int node, int l, int r, int x, int y) {
	push(node, l, r);
	if(x <= l && r <= y) return st[node];
 
	int mid = (l + r) / 2, ret = 0;
	if(x <= mid) ret = query(2 * node, l, mid, x, y);
	if(mid < y) ret = max(ret, query(2 * node  +1, mid + 1, r, x, y));
	return ret;
}
 
 
void dfs(int node) {
	// dbg(node);
	// dbg(v[node])
	euler.push_back(node);
	pos[node] = euler.size();

	leaf[node] = {pos[node], pos[node]};
	// if(v[node].size())
	// 	leaf[node] = {n, 1};
	// if(v[node].size() == 0) upd(1, 1, n + 1, pos[node], pos[node], -INF);

	for(auto i : v[node]) {
		dfs(i);
		leaf[node].st = min(leaf[node].st, leaf[i].st);
		leaf[node].nd = max(leaf[node].nd, leaf[i].nd);
	}
}
 
void mark(int node, int val) {
	// dbg(node);
	// dbg(leaf[node], val);
	upd(1, 1, n + 1, leaf[node].st, leaf[node].nd, val);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(int i =1; i <= n; i++)
		cin >> a[i];

	s.push(n + 1);
	a[n + 1] = n + 100;

	for(int i = n; i > 0; i--) {
		while(a[s.top()] <= a[i]) s.pop();
		nxt[i] = s.top();
		s.push(i);
		v[nxt[i]].push_back(i);
	}

	dfs(n + 1);

	// dbg_v(nxt, n + 1);
	for(int i = 1; i <= k; i++)
		mark(i, 1);

	cout << query(1, 1, n + 1, 1, n + 1) << ' ';

	for(int i = k + 1; i <= n; i++) {
		mark(i, 1);
		mark(i - k, -1);
		cout << query(1, 1, n + 1, 1, n + 1) << ' ';
	}
}