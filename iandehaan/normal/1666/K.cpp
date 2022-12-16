#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a, b;
    cin >> a >> b;
    a--; b--;

    int s = 2*n;
    int t = 2*n+1;

    ll inf = ((ll) 1) << ((ll) 60);

    Dinic flow(2*n+2);


    // enforce a is A
    flow.addEdge(s, a, inf);
    flow.addEdge(a+n, t, inf);

    // enforce b is B
    flow.addEdge(s, b+n, inf);
    flow.addEdge(b, t, inf);

    rep(i, 0, m) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        u--; v--;

        flow.addEdge(u, v+n, c);
        flow.addEdge(v+n, u, c);
        flow.addEdge(v, u+n, c);
        flow.addEdge(u+n, v, c);
    }

    cout << flow.calc(s, t) << endl;
    rep(i, 0, n) {
        int x = flow.leftOfMinCut(i);
        int y = flow.leftOfMinCut(i+n);
        if (x == y) cout << 'C';
        else if (x == 0) cout << 'B';
        else cout << 'A';
    }
    cout << endl;
}