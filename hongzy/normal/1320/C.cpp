#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <ctime>
#include <map>
#include <set>
using namespace std;

#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 1e6 + 10, MX = 1e6 + 2;
const int mod = 1e9 + 7;
const ll INF = 2e18 + 5;
struct node {
	int x, c;
	bool operator < (const node &b) const {
		return x > b.x;
	}
} a[N], b[N];
int n, m, p;
struct node2 {
	int x, y, z;
} c[N];
bool cmp2(node2 a, node2 b) {
	return a.x < b.x;
}
ll tag[N << 2], mx[N << 2], pos[N];
void build(int u, int l, int r) {
	if(l == r) {
		mx[u] = - pos[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	mx[u] = max(mx[u << 1], mx[u << 1 | 1]);
}
void up(ll &u, const ll &v) {
	if(u == INF || u == -INF) return ;
	u += v;
}
void pd(int u) {
	if(tag[u]) {
		up(mx[u << 1], tag[u]);
		up(mx[u << 1 | 1], tag[u]);
		tag[u << 1] += tag[u];
		tag[u << 1 | 1] += tag[u];
		tag[u] = 0;
	}
}
void modify(int u, int l, int r, int ql, int qr, ll cc) {
	if(l == ql && r == qr) {
		tag[u] += cc; up(mx[u], cc);
		return ;
	}
	int mid = (l + r) >> 1; pd(u);
	if(qr <= mid) modify(u << 1, l, mid, ql, qr, cc);
	else if(ql > mid) modify(u << 1 | 1, mid + 1, r, ql, qr, cc);
	else {
		modify(u << 1, l, mid, ql, mid, cc);
		modify(u << 1 | 1, mid + 1, r, mid + 1, qr, cc);
	}
	mx[u] = max(mx[u << 1], mx[u << 1 | 1]);
}
int main() {
	scanf("%d%d%d", &n, &m, &p);
	for(int i = 1; i <= n; i ++) scanf("%d%d", &a[i].x, &a[i].c);
	for(int i = 1; i <= m; i ++) scanf("%d%d", &b[i].x, &b[i].c);
	for(int i = 1; i <= p; i ++) scanf("%d%d%d", &c[i].x, &c[i].y, &c[i].z);
	sort(a + 1, a + n + 1); sort(b + 1, b + m + 1);
	for(int i = 2; i <= n; i ++) a[i].c = min(a[i].c, a[i - 1].c);
	for(int i = 2; i <= m; i ++) b[i].c = min(b[i].c, b[i - 1].c);
	sort(c + 1, c + p + 1, cmp2);
	
	for(int i = 1; i <= MX; i ++) pos[i] = INF;
	for(int i = 1; i <= m; i ++) pos[b[i].x] = min(pos[b[i].x], (ll) b[i].c);
	ll ans = -2e18; int pos = 1; build(1, 1, MX);
	for(int i = n; i >= 1; i --) {
		while(pos <= p && c[pos].x < a[i].x) {
			modify(1, 1, MX, c[pos].y + 1, MX, c[pos].z);
			pos ++;
		}
		ans = max(ans, mx[1] - a[i].c);
	}
	printf("%lld\n", ans);
	return 0;
}