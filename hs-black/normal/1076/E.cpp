#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x)
{
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar('\n');
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 400500;
int h[N], ne[N<<1], to[N<<1], tot, m, n;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

ll d[N], ans[N];
vector<pair<int, int> > v[N];

inline void Add(int x, int k) {
	for (; x <= n; x += x & -x) d[x] += k;
}
inline ll sum(int x) {
	ll res = 0;
	for (; x; x -= x & -x) res += d[x];
	return res;
}

void dfs(int x, int fa, int dep) {
	for (auto g: v[x]) Add(dep, g.se), Add(dep + g.fi + 1, -g.se);
	ans[x] = sum(dep);
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		dfs(y, x, dep + 1);
	}
	for (auto g: v[x]) Add(dep, -g.se), Add(dep + g.fi + 1, g.se);
}

int main() {
	read(n);
	for (int i = 1, x, y;i < n; i++)
		read(x), read(y), add(x, y), add(y, x);
	read(m);
	for (int i = 1, p, d, x;i <= m; i++)
		read(p), read(d), read(x), v[p].push_back(MP(d, x));
	dfs(1, 0, 1);
	for (int i = 1;i <= n; i++) printf ("%lld ", ans[i]);
	return 0;
}