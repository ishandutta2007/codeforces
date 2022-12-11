#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define MP make_pair
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

const int N = 2005;
vector<pair<int, int> > vec[N];
vector<int> ed[N];
int f[N], c[N], a[N], rt, n;
void dfs(int x) {
	if (!ed[x].size()) { if (c[x]) { puts("NO"); exit(0); } vec[x].emplace_back(1, x); return ; }
	int sum = 0;
	for (auto y: ed[x]) {
		dfs(y);
		if (vec[x].size() < vec[y].size()) vec[x].swap(vec[y]);
		sum = vec[x].size();
		for (auto id: vec[y]) vec[x].emplace_back(id.fi + sum, id.se);
	}
	if (c[x] > vec[x].size()) { puts("NO"); exit(0); }
	vec[x].insert(vec[x].begin() + c[x], MP(c[x], x));
	for (int i = c[x];i < vec[x].size(); ++i) vec[x][i].fi++;
}

int main() {
	read(n);
	for (int i = 1;i <= n; ++i) {
		read(f[i]), read(c[i]);
		f[i] ? ed[f[i]].push_back(i),0 : rt = i;
	}
	dfs(rt);
	for (auto t: vec[rt]) a[t.se] = t.fi;
	puts("YES");
	for (int i = 1;i <= n; ++i) write(a[i], ' ');
	return 0;
}