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

#define MAXN 100'010

vector<int> adj[MAXN];
vector<int> children[MAXN];
int par[MAXN];
int depth[MAXN];
map<pii, int> out;

void dfs(int curr, int prevedge) {
	int iter = 0;
	for (int nxt : adj[curr]) {
		iter++;
		if (par[nxt] == -1) {
			par[nxt] = curr;
			children[nxt].pb(curr);
			depth[nxt] = depth[curr]+1;
			int edgelabel = -1;
			if (curr == 0) {
				if (iter == 1) edgelabel = 2;
				else edgelabel  = 3;
			} else {
				if (prevedge == 2) edgelabel = 3;
				else edgelabel = 2;
			}
			out[mp(curr, nxt)] = edgelabel;
			dfs(nxt, edgelabel);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		out.clear();
		rep(i, 0, n) {
			adj[i].clear();
			children[i].clear();
			par[i] = -1;
		}

		pii edges[n-1];

		rep(i, 0, n-1) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			adj[u].pb(v);
			adj[v].pb(u);
			edges[i] = mp(u, v);
		}

		bool poss = true;

		rep(i, 0, n) {
			if (sz(adj[i]) > 2) poss = false;
		}

		if (!poss) {
			cout << -1 << endl;
			continue;
		}


		par[0] = -2;
		depth[0] = 0;
		dfs(0, 0);

		rep(i, 0, n-1) {
			int u = edges[i].first;
			int v = edges[i].second;
			if (depth[u] > depth[v]) swap(u, v);
			cout << out[mp(u, v)] << ' ';
		}
		cout << endl;

		
	}
}