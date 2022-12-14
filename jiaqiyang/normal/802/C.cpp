#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--) 
#define Rep(i,a) for(int i = 0; i < a; i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ab(x) ((x) < 0 ? -(x) : (x))
using namespace std;
typedef long long LL;
typedef map<int, int>::iterator mit;
typedef set<int>::iterator sit;
typedef pair<int, int> pii;
#define x first
#define y second
const int N = 180;
int n, k, a[N], c[N], t[N];

struct edge{ int to, pre, w, c; } e[int(1e5) + 10]; int u[N], l = 1; //l = 1!
void ins(int a, int b, int w, int c) { e[++l] = (edge){b, u[a], w, c}, u[a] = l; }
void insert(int a, int b, int w, int c) { ins(a, b, w, c), ins(b, a, 0, -c); }
#define v e[i].to
#define ew e[i].w
#define ec e[i].c
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)
const int inf = 8e7 + 10;
int S, T;
LL ans = 0, h[N];
int from[N]; bool inq[N];
bool bfs() {
	rep(i,S,T) h[i] = inf;
	static int q[N]; int l = 0, r = 1; q[h[S] = 0] = S;
	while (l != r) {
		int x = q[l++]; l %= N; inq[x] = false;
		reg(i,x) if (ew && h[x] + ec < h[v]) 
		{ h[v] = h[x] + ec, from[v] = i; if (!inq[v]) q[r++] = v, r %= N, inq[v] = true; }
	}
	return h[T] < 0;
}

void mcf() {
	int f = inf; LL c = 0;
	for(int i = from[T]; i; i = from[e[i^1].to]) f = min(f, ew), c += ec;
	ans += c * f;
	for(int i = from[T]; i; i = from[e[i^1].to]) ew -= f, e[i ^ 1].w += f;
}

void work() {
	S = 0, T = n * 2;
	rep(i,1,n) {
		insert((i - 1) * 2, i * 2 - 1, k, 0);
		insert(i * 2 - 1, i * 2, k - 1, 0);
		insert(i * 2 - 1, i * 2, 1, -inf);
		int x = a[i];
		if (t[x]) insert(t[x] * 2, i * 2 - 1, 1, -c[x]);
		t[x] = i, ans += c[x];
	}
	ans += 1LL * inf * n;
	while (bfs()) mcf();
}

int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%d", a + i);
	rep(i,1,n) scanf("%d", c + i);
	work();
	printf("%lld\n",ans);
	return 0;
}