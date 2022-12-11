#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define N 601000
template <typename T> inline void read(T &x) {
	x = 0; char c = getchar(); bool flag = false;
	while (!isdigit(c)) { if (c == '-')	flag = true; c = getchar(); }
	while (isdigit(c)) { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar(); }
	if (flag)	x = -x;
}
using namespace std;
const int inf = 987654321;
int n, q, K;
int X[N], Y[N], ti[N];
bool vis[N];
namespace LCT{
	int son[N][2], fa[N], siz[N], Siz[N], tag[N], sz[N], val[N], mxid[N];
	inline void init() {
//		memset(son, 0, sizeof(son));
//		memset(fa, 0, sizeof(fa));
//		memset(siz, 0, sizeof(siz));
//		memset(Siz, 0, sizeof(Siz));
//		memset(tag, 0, sizeof(tag));
//		memset(sz, 0, sizeof(sz));
//		memset(val, 0, sizeof(val));
//		memset(mxid, 0, sizeof(mxid));
		for (int i = 1; i <= n; ++i) {
			sz[i] = 1; Siz[i] = 1; val[i] = inf; mxid[i] = i;
		}
	}
	inline int Mx(int x, int y) {
		if (!x || !y)	return x ^ y;
		if (val[x] < val[y])	return x;
		return y;
	}
	inline bool notroot(int cur) {
		return son[fa[cur]][0] == cur || son[fa[cur]][1] == cur;
	}
	inline bool get_which(int cur) {
		return son[fa[cur]][1] == cur;
	}
	inline void pushup(int cur) {
		Siz[cur] = siz[cur] + Siz[son[cur][0]] + Siz[son[cur][1]] + sz[cur];
		mxid[cur] = Mx(cur, Mx(mxid[son[cur][0]], mxid[son[cur][1]]));
	}
	inline void pushr(int cur) {
		if (!cur)	return ;
		swap(son[cur][0], son[cur][1]);
		tag[cur] ^= 1;
	}
	inline void pushdown(int cur) {
		if (tag[cur])
			pushr(son[cur][0]), pushr(son[cur][1]), tag[cur] = 0;
	}
	inline void rotate(int cur) {
		int faa = fa[cur], fafa = fa[faa];
		bool flag = get_which(cur);
		fa[cur] = fafa; if (notroot(faa))	son[fafa][get_which(faa)] = cur;
		son[faa][flag] = son[cur][flag ^ 1];
		if (son[cur][flag ^ 1])	fa[son[cur][flag ^ 1]] = faa;
		son[cur][flag ^ 1] = faa; fa[faa] = cur;
		pushup(faa);
	}
	int stk[N], stop;
	inline void splay(int cur) {
		int p = cur;
		while (notroot(p))	stk[++stop] = p, p = fa[p];
		stk[++stop] = p;
		while (stop)	pushdown(stk[stop--]);
		
		for (register int faa = fa[cur]; notroot(cur); rotate(cur), faa = fa[cur])
			if (notroot(faa))	rotate(get_which(faa) == get_which(cur) ? faa : cur);
		pushup(cur);
	}
	inline void Access(int cur) {
		for (register int p = cur, lst = 0; p; lst = p, p = fa[p])
			splay(p), siz[p] += Siz[son[p][1]], 
			son[p][1] = lst, siz[p] -= Siz[lst], pushup(p);
	}
	inline void make_root(int cur) {
		Access(cur), splay(cur), pushr(cur);
	}
	inline void Split(int x, int y) {
		make_root(x), Access(y), splay(y);
	}
	inline void Link(int x, int y) {
		make_root(x); make_root(y);
		fa[x] = y; siz[y] += Siz[x]; pushup(y);
	}
	inline void Cut(int x, int y) {
		make_root(x), Access(y), splay(y);
		splay(x); fa[y] = son[x][1] = 0;
	}
	inline int find_root(int cur) {
		Access(cur); splay(cur);
		int p = cur;
		while (son[p][0])	p = son[p][0];
		splay(p);
		return p;
	}
	inline void Try(int x, int y, int t) {
		int xx = find_root(x), yy = find_root(y);
		mxid[t + n] = t + n; val[t + n] = ti[t];
		if (xx != yy) {
			Link(x, t + n);
			Link(y, t + n);
			return ;
		}
		int Id = t + n;
		Split(x, y);
		int md = mxid[y];
		vis[md] = true;
//		if (val[Id] >= val[md])	return ;
		Cut(md, X[md - n]); Cut(md, Y[md - n]);
		Link(x, Id); Link(y, Id);
	}
	inline void Try_Cut(int x, int y, int t) {
		if (vis[t + n])	return ;
//		puts("P0");
		Cut(x, t + n), Cut(t + n, y);
	}
	inline int query_siz(int cur) {
		cur = find_root(cur);
		return Siz[cur];
	}
}

int que[N], front, rear;
int main() {
	read(n), read(q), read(K);
	LCT::init();
	int tm = 0;
	for (int i = 1; i <= q; ++i) {
		int t; read(t);
		if (t == 1) {
			read(X[i]), read(Y[i]); ti[i] = tm;
			LCT::Try(X[i], Y[i], i);
			que[++rear] = i;
		} else if (t == 2) {
			int cur; read(cur);
			int ans = LCT::query_siz(cur);
			printf("%d\n", ans);
		} else {
			++tm;
			while (front < rear && ti[que[front + 1]] == tm - K)
				LCT::Try_Cut(X[que[front + 1]], Y[que[front + 1]], que[front + 1]), ++front;
		}
	}
	return 0;
}


/*
5 12 1
1 1 2
1 1 3
1 3 4
2 4
2 5
3
2 1
1 1 2
1 3 2
2 1
3
2 1
//4 1 1 3 1
*/