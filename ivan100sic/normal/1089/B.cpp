#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

namespace blossom {
	// https://codeforces.com/blog/entry/49402

	// Input:
	// 	V - number of vertices
	// 	E - number of edges
	// pair of vertices as edges (vertices are 1..V)

	// Output:
	// 	output of edmonds() is the maximum matching
	// 	match[i] is matched pair of i (-1 if there isn't a matched pair)

	const int MAXN = 500;

	struct struct_edge {
		int v;
		struct_edge* n;
	};

	typedef struct_edge* edge;
	
	struct_edge pool[MAXN*MAXN*2];
	edge top = pool, adj[MAXN];

	int V, E, match[MAXN], qh, qt, q[MAXN], father[MAXN], base[MAXN];
	bool inq[MAXN], inb[MAXN], ed[MAXN][MAXN];

	void clear() {
		V = E = qh = qt = 0;
		top = pool;
		memset(pool, 0, sizeof(pool));
		memset(adj, 0, sizeof(adj));
		memset(match, 0, sizeof(match));
		memset(q, 0, sizeof(q));
		memset(father, 0, sizeof(father));
		memset(base, 0, sizeof(base));
		memset(inq, 0, sizeof(inq));
		memset(inb, 0, sizeof(inb));
		memset(ed, 0, sizeof(ed));
	}

	void add_edge(int u,int v) {
		top->v = v;
		top->n = adj[u];
		adj[u] = top++;

		top->v = u;
		top->n = adj[v];
		adj[v]=top++;
	}

	int LCA(int root, int u, int v) {
		static bool inp[MAXN];
		memset(inp, 0, sizeof(inp));

		while (1) {
			inp[u = base[u]] = true;
			if (u == root)
				break;
			u = father[match[u]];
		}

		while (1) {
			if (inp[v = base[v]])
				return v;
			else
				v = father[match[v]];
		}
	}

	void mark_blossom(int lca, int u) {
		while (base[u] != lca) {
			int v = match[u];
			inb[base[u]] = inb[base[v]] = true;
			u = father[v];
			if (base[u] != lca)
				father[u] = v;
		}
	}

	void blossom_contraction(int s, int u, int v) {
		int lca = LCA(s, u, v);
		memset(inb, 0, sizeof(inb));
		mark_blossom(lca, u);
		mark_blossom(lca, v);
		if (base[u] != lca)
			father[u] = v;
		if (base[v] != lca)
			father[v] = u;
		for (int u=0; u<V; u++) {
			if (inb[base[u]]) {
				base[u] = lca;
				if (!inq[u])
					inq[q[++qt] = u] = true;
			}
		}
	}

	int find_augmenting_path(int s) {
		memset(inq, 0, sizeof(inq));
		memset(father, -1, sizeof(father));
		for (int i=0; i<V; i++)
			base[i] = i;
		inq[q[qh = qt = 0] = s] = true;
		while (qh <= qt) {
			int u = q[qh++];
			for (edge e = adj[u]; e; e = e->n) {
				int v = e->v;
				if (base[u] != base[v] && match[u] != v) {
					if ((v == s) || (match[v] != -1 && father[match[v]] != -1))
						blossom_contraction(s, u, v);
					else if (father[v] == -1) {
						father[v] = u;
						if (match[v] == -1)
							return v;
						else if (!inq[match[v]])
							inq[q[++qt] = match[v]] = true;
					}
				}
			}
		}
		return -1;
	}

	int augment_path(int s, int t) {
		int u = t, v, w;
		while (u != -1) {
			v = father[u];
			w = match[v];
			match[v] = u;
			match[u] = v;
			u = w;
		}
		return t != -1;
	}

	int edmonds() {
		int matchc = 0;
		memset(match, -1, sizeof(match));
		for (int u=0; u<V; u++)
			if (match[u] == -1)
				matchc += augment_path(u, find_augmenting_path(u));
		return matchc;
	}

	vector<pair<int, int>> run(int n, vector<pair<int, int>> e) {
		clear();

		V = n;
		for (auto p : e) {
			if (!ed[p.first][p.second]) {
				add_edge(p.first, p.second);
				ed[p.first][p.second] = true;
				ed[p.second][p.first] = true;
			}
		}

		edmonds();

		vector<pair<int, int>> f;

		for (int i=0; i<V; i++)
			if (i < match[i])
				f.push_back({i, match[i]});

		return f;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<pair<int, int>> e;

		for (int i=0; i<n; i++) {
			string s;
			cin >> s;
			for (int j=0; j<m; j++)
				if (s[j] == '1') {
					e.push_back({i, 2*n+j});
					e.push_back({n+i, 2*n+j});
				}
			e.push_back({i, n+i});
		}

		cout << (int)blossom::run(2*n+m, e).size() - n<< '\n';
	}
}