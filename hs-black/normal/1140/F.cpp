#pragma GCC optimize(3)
#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
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

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

#define Pa pair<int, int>
map<Pa, int> mp;
const int N = 300050;
int f[N<<1], X[N<<1], Y[N<<1], n;
ll c[N<<1][2], cnt;

#define ls p << 1
#define rs p << 1 | 1

vector<Pa> v[N<<2];
void change(int l, int r, int p, int L, int R, Pa x) {
	if (L <= l && r <= R) return v[p].push_back(x), void();
	int mid = (l + r) >> 1;
	if (mid >= L) change(l, mid, ls, L, R, x);
	if (mid < R) change(mid + 1, r, rs, L, R, x);
}

const int lim = 300000;

int find(int x) {
	while (x != f[x]) x = f[x]; return x;
}

void solve(int l, int r, int p, ll ans) {
	
	int t = cnt;
	for (auto t: v[p]) {
		int x = find(t.fi), y = find(t.se + lim);  if (x == y) continue;
		if (c[x][0] + c[x][1] < c[y][0] + c[y][1]) swap(x, y);
		X[++cnt] = x, Y[cnt] = y;
		ans -= c[x][0] * c[x][1] + c[y][0] * c[y][1];
		f[y] = x, c[x][0] += c[y][0], c[x][1] += c[y][1];
		ans += c[x][0] * c[x][1];
	}
	
	if (l == r) printf ("%lld ", ans);
	else {
		int mid = (l + r) >> 1;
		solve(l, mid, ls, ans), solve(mid + 1, r, rs, ans);
	}
	
	while (cnt > t) {
		int x = X[cnt], y = Y[cnt];
		c[x][0] -= c[y][0], c[x][1] -= c[y][1];
		f[y] = y, cnt--;
	}
}

int main() {
	read(n);
	for (int i = 1;i <= n; i++) {
		int x, y; read(x), read(y);
		if (mp[MP(x, y)]) change(1, n, 1, mp[MP(x, y)], i-1, MP(x, y)), mp[MP(x, y)] = 0;
		else mp[MP(x, y)] = i;
	}
	for (auto j: mp) {
		Pa px = j.fi; int st = j.se;
		if (!st) continue; 
		change(1, n, 1, st, n, px);
	}
	
	for (int i = 1;i <= 600000; i++)
		f[i] = i, c[i][i > lim] = 1;
	solve(1, n, 1, 0);
	
	return 0;
}