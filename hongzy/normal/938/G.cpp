#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#define fs first
#define sc second
using namespace std;
typedef pair<int, int> pa;
const int N = 2e5 + 10;
struct tu {
	int x, y, z;
	tu(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c) {}
};
int n, m, q, eu[N * 2], ev[N * 2], ew[N * 2], ti[N * 2], ans[N];
int qu[N * 2], qv[N * 2];
bool vis[N * 2];
map< pa, int > Map;
vector<tu> vec[N << 2];
struct lib {

int b[30];
void insert(int x) {
	for(int i = 29; i >= 0; i --) if(x >> i & 1) {
		if(b[i]) x ^= b[i];
		else { b[i] = x; break ; }
	}
}
int query(int x) {
	for(int i = 29; i >= 0; i --) if(b[i] && (x >> i & 1)) {
		x ^= b[i];
	}
	return x;
}

} null;
void addedge(int u, int l, int r, int ql, int qr, tu e) {
	if(l == ql && r == qr) { vec[u].push_back(e); return ; }
	int mid = (l + r) >> 1;
	if(qr <= mid) addedge(u << 1, l, mid, ql, qr, e);
	else if(ql > mid) addedge(u << 1 | 1, mid + 1, r, ql, qr, e);
	else {
		addedge(u << 1, l, mid, ql, mid, e);
		addedge(u << 1 | 1, mid + 1, r, mid + 1, qr, e);
	}
}
int sz[N], f[N], fw[N], top;
tu st[N];
int find(int u) {
	while(u ^ f[u]) u = f[u];
	return u;
}
int fdis(int u) {
	int w = 0;
	while(u ^ f[u]) w ^= fw[u], u = f[u];
	return w;
}
void merge(tu e, lib &li) {
	int u = e.x, du = 0, v = e.y, dv = 0;
	while(u ^ f[u]) du ^= fw[u], u = f[u];
	while(v ^ f[v]) dv ^= fw[v], v = f[v];
	e.z ^= du ^ dv;
	if(u == v) {
		li.insert(e.z);
	} else {
		if(sz[u] < sz[v]) swap(u, v);
		f[v] = u; fw[v] = e.z; sz[u] += sz[v];
		st[++ top] = tu(u, v, e.z);
	}
}
void pop() {
	int u = st[top].x, v = st[top].y;
	f[v] = v; fw[v] = 0; sz[u] -= sz[v]; top --;
}
void solve(int rt, int l, int r, lib li) {
	int pt = top;
	for(int i = 0; i < (int) vec[rt].size(); i ++) {
		merge(vec[rt][i], li);
	}
	if(l == r) {
		if(~ ans[l]) ans[l] = li.query(fdis(qu[l]) ^ fdis(qv[l]));
	} else {
		int mid = (l + r) >> 1;
		solve(rt << 1, l, mid, li);
		solve(rt << 1 | 1, mid + 1, r, li);
	}
	while(top > pt) pop();
}
int main() {
	// freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i ++) {
		scanf("%d%d%d", eu + i, ev + i, ew + i); ti[i] = 1;
		if(eu[i] > ev[i]) swap(eu[i], ev[i]);
		Map[pa(eu[i], ev[i])] = i;
	}
	scanf("%d", &q);
	for(int op, x, y, i = 1; i <= q; i ++) {
		scanf("%d%d%d", &op, &x, &y);
		if(x > y) swap(x, y);
		if(op == 1) {
			int w; scanf("%d", &w);
			m ++; eu[m] = x; ev[m] = y; ew[m] = w; ti[m] = i;
			Map[pa(x, y)] = m;
		}
		if(op == 2) {
			int tmp = Map[pa(x, y)]; vis[tmp] = 1;
			addedge(1, 1, q, ti[tmp], i, tu(x, y, ew[tmp]));
		}
		if(op == 3) {
			qu[i] = x; qv[i] = y;
		} else ans[i] = -1;
	}
	for(int i = 1; i <= m; i ++) if(!vis[i]) {
		addedge(1, 1, q, ti[i], q, tu(eu[i], ev[i], ew[i]));
	}
	for(int i = 1; i <= n; i ++) {
		f[i] = i; sz[i] = 1;
	} 
	solve(1, 1, q, null);
	for(int i = 1; i <= q; i ++)
		if(~ ans[i]) printf("%d\n", ans[i]);
	return 0;
}