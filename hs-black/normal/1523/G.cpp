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

struct node {
	int a, b, c;
	node(){} 
	node(int x, int y, int z) { a = x, b = y, c = z; }
	bool operator < (const node &i) const {
		if (a != i.a) return a < i.a;
		if (b != i.b) return b < i.b;
		return c < i.c;
	}
};

const int N = 50005;
set<node> s[N];
int lim, m, n;
void addin(int x, int r, int tim) {
	for (int t = x; t; t ^= t & -t) {
		auto it = s[t].upper_bound(node(r, tim, x));
		if (it != s[t].begin()) {
			--it; 
			if (it->b < tim) continue;
			++it;
		}
		while (it != s[t].end() && it->b > tim) s[t].erase(it++);
		s[t].emplace(r, tim, x);
	}
}

int solve(int l, int r) {
	if (r - l + 1 < lim) return 0;
	int L, R, t = 114514;
	for (int x = l;x <= n; x += x & -x) {
		auto it = s[x].lower_bound(node(r + 1, 0, 0));
		if (it == s[x].begin()) continue;
		--it;
		if (it->b < t) t = it->b, L = it->c, R = it->a;
	}
	if (t == 114514) return 0;
	return solve(l, L - 1) + solve(R + 1, r) + R - L + 1;
}

vector<node> vec[N];
int ans[N];
int main() {
	read(n), read(m);
	for (int i = 1, l, r;i <= m; ++i) 
		read(l), read(r), vec[r - l + 1].emplace_back(l, r, i);
	for (int i = n;i >= 1; --i) {
		for (auto t: vec[i]) addin(t.a, t.b, t.c);
		lim = i, ans[i] = solve(1, n);
	}
	for (int i = 1;i <= n; ++i) write(ans[i]);
	return 0;
}