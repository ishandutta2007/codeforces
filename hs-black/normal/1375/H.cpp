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

#define ls p << 1
#define rs ls | 1
const int N = (1 << 14) + 5;
map<pair<int, int>, int> mp[N];
vector<int> vec[N];
int a[N], rev[N], X[(N << 8) + 5], Y[(N << 8) + 5], cnt, n, q;
void build(int p, int l, int r) {
	if (l == r) return mp[p][make_pair(0, 0)] = rev[l], vec[p].push_back(rev[l]);
	int mid = (l + r) >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	vec[p].insert(vec[p].end(), vec[ls].begin(), vec[ls].end());
	vec[p].insert(vec[p].end(), vec[rs].begin(), vec[rs].end());
	sort(vec[p].begin(), vec[p].end());
}

int query(int p, int l, int r, int L, int R) {
	int tl = lower_bound(vec[p].begin(), vec[p].end(), L) - vec[p].begin();
	int tr = upper_bound(vec[p].begin(), vec[p].end(), R) - vec[p].begin() - 1;
	if (tr < tl) return 0;
	pair<int, int> tmp(tl, tr);
	if (mp[p].count(tmp)) return mp[p][tmp];
	int mid = (l + r) >> 1;
	int a = query(ls, l, mid, L, R);
	int b = query(rs, mid + 1, r, L, R);
	if (!a || !b) return mp[p][tmp] = a | b;
	++cnt, X[cnt] = a, Y[cnt] = b;
	return mp[p][tmp] = cnt;
}

int ans[N << 2];
int main() {
	read(n), read(q), cnt = n;
	for (int i = 1;i <= n; ++i) read(a[i]), rev[a[i]] = i;
	build(1, 1, n);
	for (int i = 1, l, r;i <= q; ++i) 
		read(l), read(r), ans[i] = query(1, 1, n, l, r);
	write(cnt);
	for (int i = n + 1; i <= cnt; ++i)
		write(X[i], ' '), write(Y[i]);
	for (int i = 1;i <= q; ++i) write(ans[i], ' ');
	return 0;
}