#include <bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T>
void write(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp--] | '0');
	putchar(ed);
}

#define MP make_pair
#define fi first
#define se second
const int N = 300005;
int m, n; ll x, a[N], sum;
int f[N];
priority_queue<pair<ll, int> > q;
set<pair<int, int> > s[N];
inline int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
int main() {
	read(n), read(m), read(x);
	for (int i = 1;i <= n; ++i) read(a[i]), sum += a[i], q.push(MP(a[i], i));
	if (sum < x * (n - 1)) return puts("NO"), 0;
	for (int i = 1;i <= n; ++i) f[i] = i;
	for (int i = 1, a, b;i <= m; ++i)
		read(a), read(b), s[a].emplace(b, i), s[b].emplace(a, i);
	int tmp = n - 1;
	puts("YES");
	while (tmp) {
		auto t = q.top(); q.pop();
		//printf ("%lld %d\n", a[t.se], t.se);
		if (find(t.se) != t.se) continue;
		int x = t.se;
		while (s[x].size()) {
			auto k = *s[x].begin(); s[x].erase(k);
			int y = find(k.fi);
			if (y == find(x)) continue;
			write(k.se);
			if (s[x].size() < s[y].size()) swap(s[x], s[y]);
			for (auto kk : s[y]) s[x].insert(kk);
			a[x] = a[x] + a[find(y)] - ::x, f[f[y]] = x;
			q.push(MP(a[x], x));
			break;
		}
		--tmp;
	}
	return 0;
}