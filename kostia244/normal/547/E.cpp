#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using ld = long double;
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
//using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1<<18, mod = (119<<23)+1, lg = 18;
struct node {
	int sum = 0;
	node *l, *r;
	node(int x) {sum = x, l = r = 0;}
};
using pnode = node*;
deque<node> buffer;
pnode newnode(int x) {
	buffer.emplace_back(x);
	return &buffer.back();
}
pnode merge(pnode a, pnode b) {
	pnode t = newnode(a->sum + b->sum);
	t->l = a, t->r = b;
	return t;
}
pnode build(int l, int r) {
	if(l == r) return newnode(0);
	int mid = (l+r)>>1;
	return merge(build(l, mid), build(mid+1, r));
}
pnode upd(int l, int r, int i, int x, pnode rt) {
	if(i < l || r < i) return rt;
	if(l == r) return newnode(rt->sum + x);
	int mid = (l+r)>>1;
	return merge(upd(l, mid, i, x, rt->l), upd(mid+1, r, i, x, rt->r));
}
int get(int l, int r, int ql, int qr, pnode rt) {
	if(ql > r || qr < l) return 0;
	if(ql <= l && r <= qr) return rt->sum;
	int mid = (l+r)>>1;
	return get(l, mid, ql, qr, rt->l) + get(mid+1, r, ql, qr, rt->r);
}

vi g[maxn];
int tin[maxn], tout[maxn], timer = 0;
void dfs(int v) {
	tin[v] = timer++;
	for(auto i : g[v]) {
		dfs(i);
	}
	tout[v] = timer-1;
}
struct aho {
	int to[maxn][26], link[maxn], sz;
	void init() {
		sz = 1;
		memset(to, 0, sizeof to);
		memset(link, 0, sizeof link);
	}
	int add(string &s) {
		int cur = 0;
		for(auto i : s) {
			i -= 'a';
			if(!to[cur][i]) {to[cur][i] = sz++;}
			cur = to[cur][i];
		}
		return cur;
	}
	void push_links() {
		int q[maxn], st = 0, fi = 1;
		q[0] = 0;
		while(st < fi) {
			int u = q[st++];
			int v = link[u];
			for(int i = 0; i < 26; i++) {
				if(to[u][i]) {
					q[fi++] = to[u][i];
					link[to[u][i]] = u ? to[v][i] : 0;
				} else {
					to[u][i] = to[v][i];
				}
			}
		}
		for(int i = 1; i < sz; i++)
			g[link[i]].pb(i);
		dfs(0);
	}
};
int n, m, term[maxn];
aho a;
string s[maxn];
string bigs;
pnode rt[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	a.init();
	for(int i = 1; i <= n; i++) cin >> s[i], term[i] = a.add(s[i]);
	rt[0] = build(1, a.sz);
	a.push_links();
	for(int i = 1; i <= n; i++) {
		rt[i] = rt[i-1];
		int cur = 0;
		for(auto c : s[i]) {
			c -= 'a';
			cur = a.to[cur][c];
			rt[i] = upd(1, a.sz, tin[cur], 1, rt[i]);
		}
	}
	int l, r, x;
	while(m--) {
		cin >> l >> r >> x;
		cout << get(1, a.sz, tin[term[x]], tout[term[x]], rt[r]) - get(1, a.sz, tin[term[x]], tout[term[x]], rt[l-1]) << '\n';
	}
}