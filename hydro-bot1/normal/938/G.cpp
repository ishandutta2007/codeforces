// Hydro submission #6214b65c021863789ed2566e@1645524573035
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

using namespace std;

const int maxn = 2e5 + 10;

struct xorBase {
	#define dig 30
	int p[dig + 1];
	bool zero;
	xorBase() { memset(p, 0, sizeof(p)); zero = false; }
	void insert(int x) {
		for(int i = dig; ~i; -- i)
			if(x & (1 << i)) {
				if(p[i]) x ^= p[i];
				else { p[i] = x; return ; }
			}
		zero = true;
	}
	int totmin(int ans = 0) {
		for(int i = dig; ~i; -- i)
			if((ans & (1 << i)) && p[i]) ans ^= p[i];
		return ans;
	}
} xb;

inline void copy(xorBase &lhs, xorBase &rhs) {
	lhs.zero = rhs.zero;
	memcpy(lhs.p, rhs.p, sizeof(lhs));
}

struct DSU {
	vector<int> fa, dis, rank;
	vector< pair<int, bool> > hist;
	void init(int n) {
		fa.resize(n + 1, 0); rep(i,1,n) fa[i] = i;
		dis.resize(n + 1, 0); rep(i,1,n) dis[i] = 0;
		rank.resize(n + 1, 0); rep(i,1,n) rank[i] = 1;
	}
	int find(int x, int &disCnt) {
		if(x == fa[x]) return x;
		int ret = find(fa[x], disCnt);
		disCnt ^= dis[x];
		return ret;
	}
	bool link(int x, int y, int w) {
		int dx = 0, dy = 0;
		x = find(x, dx);
		y = find(y, dy);
		if(x == y) return false;
		if(rank[x] < rank[y]) swap(x, y), swap(dx, dy);
		pair<int, bool> h = {y, 0};
		if(rank[x] == rank[y]) ++ rank[x], h.second = true;
		fa[y] = x, dis[y] = w ^ dx ^ dy;
		hist.push_back(h);
		return true;
	}
	void undo() {
		auto &it = hist.back();
		if(it.second) -- rank[fa[it.first]];
		fa[it.first] = it.first;
		dis[it.first] = 0;
		hist.pop_back();
	}
} dsu;

struct edge {
	int x, y;
	bool operator < (const edge &o) const {
		return x < o.x || x == o.x && y < o.y;
	}
};

struct ed {
	int x, y, w;
};

struct segTdiv {
	vector<ed> opr[maxn << 2];
	vector< pair<int, int> > qry[maxn];
	vector<int> ans;

	void insert(int p, int lp, int rp, int l, int r, ed e) {
		if(l <= lp && rp <= r) {
			opr[p].push_back(e);
			return ;
		}
		register int mid = (lp + rp) >> 1, ls = p << 1, rs = ls | 1;
		if(l <= mid) insert(ls, lp, mid, l, r, e);
		if(r > mid) insert(rs, mid + 1, rp, l, r, e);
	}

	void dfs(int p, int lp, int rp) {
		for(ed &e : opr[p]) {
			int w = e.w;
			if(dsu.link(e.x, e.y, w) == false) {
				dsu.find(e.x, w); dsu.find(e.y, w);
				xb.insert(w);
			}
		}
		if(lp == rp) {
			for(auto it : qry[lp]) {
				int dis = 0;
				dsu.find(it.first, dis);
				dsu.find(it.second, dis);
				ans.push_back(xb.totmin(dis));
			}
			return ;
		}
		register int mid = (lp + rp) >> 1;
		int sz = dsu.hist.size();
		xorBase tmp; copy(tmp, xb);
		dfs(p << 1, lp, mid);
		while(dsu.hist.size() > sz) dsu.undo();
		copy(xb, tmp);
		dfs(p << 1 | 1, mid + 1, rp);
	}
} tree;

map< edge, pair<int, pair<int, int> > > mp;

int main() {
	int n, m; 
	scanf("%d %d", &n, &m);
	dsu.init(n);
	int opt, x, y, w;
	int timer = 1;
	rep(i,1,m) {
		scanf("%d %d %d", &x, &y, &w);
		if(x > y) swap(x, y);
		mp[{x, y}] = {w, {1, 0}};
	}
	int q;
	scanf("%d", &q);
	rep(qr,1,q) {
		scanf("%d", &opt);
		if(opt != 3) ++ timer;
		if(opt == 1) {
			scanf("%d %d %d", &x, &y, &w);
			if(x > y) swap(x, y);
			mp[{x, y}] = {w, {timer, 0}};
		} else if(opt == 2) {
			scanf("%d %d", &x, &y);
			if(x > y) swap(x, y);
			mp[{x, y}].second.second = timer - 1;
		} else {
			scanf("%d %d", &x, &y);
			if(x > y) swap(x, y);
			tree.qry[timer].push_back({x, y});
		}
	}
	for(auto &it : mp) {
		if(it.second.second.second == 0) it.second.second.second = timer;
		tree.insert(1, 1, timer, it.second.second.first, it.second.second.second, {it.first.x, it.first.y, it.second.first});
	}
	tree.dfs(1, 1, timer);
	for(int a : tree.ans) printf("%d\n", a);
	return 0;
}