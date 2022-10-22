#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef long long i64;

struct Node {
	int id;
	i64 L, R;
	Node *ls, *rs;
};

Node *insert(i64 l, i64 r, Node *x, i64 a, i64 b) {
	// eprintf("insert [%lld, %lld] [%lld, %lld]\n", l, r, a, b);
	if (!x) x = new Node{-1, a, b, nullptr, nullptr};
	if (l <= a && b <= r) return x;
	if (r < a || b < l) return x;
	i64 m = (a + b) >> 1;
	x->ls = insert(l, r, x->ls, a, m);
	x->rs = insert(l, r, x->rs, m + 1, b);
	return x;
}

Node *rt = nullptr;

int n, Q;
struct Query {
	bool tp;
	i64 u, v;
} qr[50005];

const int mxn = 2 * 50 * 50000 + 5;

Node *vec[mxn];
int vsz;
std::vector <int> adj[mxn];

void traverse(Node *x) {
	if (!x) return ;
	if (!x->ls && !x->rs) vec[vsz ++] = x;
	else {
		traverse(x->ls);
		traverse(x->rs);
	}
}

void add_edge(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

std::vector <int> build_edges(Node *x, i64 a, i64 b) {
	if (!x) return {};
	if (x->id != -1) return {x->id};
	i64 m = (a + b) >> 1;
	i64 half = m - a + 1;
	std::vector <int> L = build_edges(x->ls, a, m);
	std::vector <int> R = build_edges(x->rs, m + 1, b);
	for (int i = 0, j = 0; i < (int) L.size() && j < (int) R.size(); ) {
		if (std::max(vec[L[i]]->L, vec[R[j]]->L - half) <=
			std::min(vec[L[i]]->R, vec[R[j]]->R - half))
			add_edge(L[i], R[j]);
		if (vec[L[i]]->R == vec[R[j]]->R - half) ++ i, ++ j;
		else if (vec[L[i]]->R < vec[R[j]]->R - half) ++ i;
		else if (vec[L[i]]->R > vec[R[j]]->R - half) ++ j;
	}
	std::vector <int> full;
	full.reserve(L.size() + R.size());
	rep(i, L.size()) full.push_back(L[i]);
	rep(i, R.size()) full.push_back(R[i]);
	return full;
}

std::vector <int> fa;

inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

inline void merge(int x, int y) {
	fa[find(x)] = find(y);
}

bool ans[50005];

int main() {
	scanf("%d %d", &n, &Q);
	const i64 max = (i64(1) << n) - 1;
	rep(i, Q) {
		char tp[15];
		i64 u, v;
		scanf("%s %lld %lld", tp, &u, &v);
		qr[i] = Query{tp[0] == 'a', u, v};
		if (qr[i].tp == 0) rt = insert(u, v, rt, 0, max);
	}
	traverse(rt);
	rep(i, vsz) vec[i]->id = i;
	// eprintf("%d\n", vsz);
	// rep(i, vsz) eprintf("%d: [%lld, %lld]\n", i, vec[i]->L, vec[i]->R);
	rep(i, vsz) adj[i].reserve(n + 5);
	build_edges(rt, 0, max);
	fa.resize(vsz);
	iota(fa.begin(), fa.end(), 0);
	std::vector <i64> ranges;
	rep(i, vsz) ranges.push_back(vec[i]->L);
	std::vector <bool> ovo(vsz, true);
	rep(i, Q) if (qr[i].tp == 0) {
		int L = std::lower_bound(ranges.begin(), ranges.end(), qr[i].u) - ranges.begin();
		int R = std::upper_bound(ranges.begin(), ranges.end(), qr[i].v) - ranges.begin();
		for (int x = L; x < R; ++ x) ovo[x] = false;
	}
	rep(x, vsz) if (ovo[x]) {
		for (int y : adj[x]) {
			if (ovo[y]) merge(x, y);
		}
	}
	for (int i = Q - 1; ~i; -- i) {
		if (qr[i].tp == 0) {
			int L = std::lower_bound(ranges.begin(), ranges.end(), qr[i].u) - ranges.begin();
			int R = std::upper_bound(ranges.begin(), ranges.end(), qr[i].v) - ranges.begin();
			for (int x = L; x < R; ++ x) ovo[x] = true;
			for (int x = L; x < R; ++ x) {
				for (int y : adj[x]) {
					if (ovo[y]) merge(x, y);
				}
			}
		} else {
			int p1 = std::upper_bound(ranges.begin(), ranges.end(), qr[i].u) - ranges.begin() - 1;
			int p2 = std::upper_bound(ranges.begin(), ranges.end(), qr[i].v) - ranges.begin() - 1;
			ans[i] = find(p1) == find(p2);
		}
	}
	rep(i, Q) if (qr[i].tp == 1) printf("%d\n", ans[i]);
	return 0;
}