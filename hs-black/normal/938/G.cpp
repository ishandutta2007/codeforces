/*
    ___                         ______      __                  __
   /   |____  __  ___________ _/ ____/___ _/ /___  ____  ______/ /____
  / /| /_  / / / / / ___/ __ `/ /   / __ `/ __/ / / / / / / __  / ___/
 / ___ |/ /_/ /_/ (__  ) /_/ / /___/ /_/ / /_/ /_/ / /_/ / /_/ (__  )
/_/  |_/___/\__,_/____/\__,_/\____/\__,_/\__/\__, /\__, /\__,_/____/
                                            /____//____/

 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)


*/

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
inline void write(F x, char ed = '\n') {
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

#include <map>
const int N = 205000;
int qx[N], qy[N], n, m, q;
map<pair<int, int>, pair<int, int> > mp;

int d[N], f[N], stx[N], sty[N], siz[N], tp;

struct Bit {
	int bit[33];
	void insert(int x) {
		for (int i = 30;i >= 0; --i) if (x >> i & 1) {
			if (!bit[i]) return bit[i] = x, void();
			x ^= bit[i];
		}
	}
	int query(int x) {
		for (int i = 30;i >= 0; --i)
			Mn(x, x ^ bit[i]);
		return x;
	}
}I;

void Back(void) {
	
}

#define ls p << 1
#define rs ls | 1

struct node { int x, y, z; };
vector<node> vec[N<<2];
void change(int p, int l, int r, int L, int R, node x) {
	if (L <= l && r <= R) return vec[p].push_back(x);
	int mid = (l + r) >> 1;
	if (L <= mid) change(ls, l, mid, L, R, x);
	if (R > mid) change(rs, mid + 1, r, L, R, x);
}

void del(void) {
	f[sty[tp]] = sty[tp], d[sty[tp]] = 0, siz[stx[tp]] -= siz[sty[tp]];
}

typedef pair<int, int> Pa;
Pa find(int x) { int ans = 0; while (x != f[x]) ans ^= d[x], x = f[x]; return MP(x, ans); }
void solve(int p, int l, int r, Bit BB) {
	int nw = tp;
	for (auto t: vec[p]) {
		int x = t.x, y = t.y, z = t.z;
		Pa A = find(x), B = find(y);
		if (A.fi == B.fi) BB.insert(A.se ^ B.se ^ z);
		else {
			if (siz[A.fi] < siz[B.fi]) swap(A.fi, B.fi);
			stx[++tp] = A.fi, sty[tp] = B.fi, siz[A.fi] += siz[B.fi];
			f[B.fi] = A.fi, d[B.fi] = A.se ^ B.se ^ z;
		}
	}
	if (l == r) {
		if (qx[l]) write(BB.query(find(qx[l]).se ^ find(qy[l]).se));
	} else {
		int mid = (l + r) >> 1;
		solve(ls, l, mid, BB), solve(rs, mid + 1, r, BB);
	}
	while (tp > nw) del(), --tp;
}

int main() {
	read(n), read(m);
	for (int i = 1;i <= n; ++i) siz[f[i] = i] = 1;
	for (int i = 1, x, y, z;i <= m; ++i) {
		read(x), read(y), read(z); if (x > y) swap(x, y);
		mp[MP(x, y)] = MP(z, 1);
	}
	read(q), ++q;
	for (int i = 2, op, x, y, z;i <= q; ++i) {
		read(op), read(x), read(y); if (x > y) swap(x, y);
		if (op == 1) read(z), mp[MP(x, y)] = MP(z, i);
		else if (op == 2) { change(1, 1, q, mp[MP(x, y)].se, i, (node){x, y, mp[MP(x, y)].fi}); mp.erase(MP(x, y)); }
		else qx[i] = x, qy[i] = y;
	}
	for (auto t: mp) change(1, 1, q, t.se.se, q, (node){t.fi.fi, t.fi.se, t.se.fi});
	solve(1, 1, q, I);
	return 0;
}

/*

5 5
1 2 3
2 3 4
3 4 5
4 5 6
1 5 1
1
3 1 5

*/