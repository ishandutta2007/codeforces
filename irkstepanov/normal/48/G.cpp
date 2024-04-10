#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

struct SolveCycle {
	SolveCycle(const vector<ll>& cost, const vector<ll>& subtree) : cost(cost), subtree(subtree), n(sz(cost)), cycleLen(0) {
		for (int i = 0; i < n; ++i) {
			cycleLen += cost[i];
		}
		pref.assign(n, 0);
		for (int i = 1; i < n; ++i) {
			pref[i] = pref[i - 1] + cost[i - 1];
		}
		int i0 = 0;
		for (int i = 1; i < n; ++i) {
			if (cw(0, i) <= ccw(0, i)) {
				i0 = i;
			}
		}
		ans.assign(n, 0);
		ll cwSum = 0, ccwSum = 0;
		ll cwSubtree = 0, ccwSubtree = 0;
		for (int i = 1; i < n; ++i) {
			if (i <= i0) {
				cwSum += cw(0, i) * subtree[i];
				cwSubtree += subtree[i];
			} else {
				ccwSum += ccw(0, i) * subtree[i];
				ccwSubtree += subtree[i];
			}
		}
		ans[0] = cwSum + ccwSum;
		for (int j = 1; j < n; ++j) {
			if (j - 1 != i0) {
				cwSum -= cost[j - 1] * cwSubtree;
				cwSubtree -= subtree[j];
				ccwSubtree += subtree[j - 1];
				ccwSum += cost[j - 1] * ccwSubtree;
			} else {
				assert(cwSum == 0 && cwSubtree == 0);
				cwSum -= ccw(j - 1, j) * subtree[j];
				ccwSubtree += subtree[j - 1];
				ccwSubtree -= subtree[j];
				ccwSum += cost[j - 1] * ccwSubtree;
				i0 = j;
			}
			//cout << "!" << j << " " << ccwSum << " " << ccwSubtree << endl;
			//cout << "!" << j << " " << i0 << endl;
			while (true) {
				int nx = i0 + 1;
				if (nx == n) {
					nx = 0;
				}
				if (nx == j) {
					break;
				}
				if (cw(j, nx) > ccw(j, nx)) {
					break;
				}
				cwSum += cw(j, nx) * subtree[nx];
				cwSubtree += subtree[nx];
				i0 = nx;
				ccwSum -= ccw(j, nx) * subtree[nx];
				ccwSubtree -= subtree[nx];
			}
			if (i0 == j - 1) {
				assert(ccwSubtree == 0);
			}
			//ccwSum += cost[j - 1] * ccwSubtree;
			ans[j] = cwSum + ccwSum;
		}
		/*vector<ll> correct(n, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				ll val = min(cw(i, j), ccw(i, j));
				correct[i] += val * subtree[j];
				correct[j] += val * subtree[i];
			}
		}
		for (int i = 0; i < n; ++i) {
			cout << cost[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < n; ++i) {
			cout << subtree[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < n; ++i) {
			cout << ans[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < n; ++i) {
			cout << correct[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < n; ++i) {
			assert(correct[i] == ans[i]);
		}*/
	}

	ll cw(int i, int j) {
		if (i == j) {
			return 0;
		}
		if (i < j) {
			return pref[j] - pref[i];
		} else {
			return cycleLen - cw(j, i);
		}
	}

	ll ccw(int i, int j) {
		if (i == j) {
			return 0;
		}
		return cycleLen - cw(i, j);
	}

	vector<ll> cost, subtree, pref;
	int n;
	ll cycleLen;
	vector<ll> ans;
};

mt19937 rr(1);

struct edge {
	int from, to;
	ll cost;
};

vector<int> parent;
vector<vector<edge> > g;
vector<ll> parentCost;
int lst = -1, fst;
ll lastEdgeCost;

void dfs(int v, int p) {
	parent[v] = p;
	for (edge& e : g[v]) {
		int to = e.to;
		if (to == p) {
			continue;
		}
		if (parent[to] == -1) {
			parentCost[to] = e.cost;
			dfs(to, v);
		} else if (lst == -1) {
			lst = v;
			fst = to;
			lastEdgeCost = e.cost;
		}
	}
}

vector<bool> onCycle;
vector<ll> depth;
vector<ll> subtree;

vector<ll> belowSum, aboveSum;
vector<int> rootNum;

void dfs2(int v, int p, int num) {
	subtree[v] += 1;
	rootNum[v] = num;
	for (edge& e : g[v]) {
		int to = e.to;
		if (to == p) {
			continue;
		}
		depth[to] = depth[v] + e.cost;
		dfs2(to, v, num);
		subtree[v] += subtree[to];
		belowSum[v] += belowSum[to] + e.cost * subtree[to];
	}
}

void dfs3(int v, int p, int root) {
	for (edge& e : g[v]) {
		int to = e.to;
		if (to == p) {
			continue;
		}
		aboveSum[to] = aboveSum[v] + (belowSum[v] - belowSum[to] - e.cost * subtree[to]) + (subtree[root] - subtree[to]) * e.cost;
		dfs3(to, v, root);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n; ++i) {
    	int u, v;
    	ll c;
    	cin >> u >> v >> c;
    	--u, --v;
    	g[u].pb({u, v, c});
    	g[v].pb({v, u, c});
    }

    parent.assign(n, -1);
    parentCost.resize(n);
    dfs(0, 0);

    onCycle.assign(n, false);
    vector<int> roots;
    vector<ll> costs;

    int curr = lst;
    while (curr != fst) {
    	onCycle[curr] = true;
    	roots.pb(curr);
    	costs.pb(parentCost[curr]);
    	curr = parent[curr];
    }
    onCycle[fst] = true;
    roots.pb(fst);
    costs.pb(lastEdgeCost);

    for (int i = 0; i < n; ++i) {
    	int j = 0;
    	while (j < sz(g[i])) {
    		int to = g[i][j].to;
    		if (onCycle[i] && onCycle[to]) {
    			swap(g[i][j], g[i].back());
    			g[i].pop_back();
    		} else {
    			++j;
    		}
    	}
    }

    depth.assign(n, 0);
    subtree.assign(n, 0);
    belowSum.assign(n, 0);
    aboveSum.assign(n, 0);
    rootNum.resize(n);

    for (int i = 0; i < sz(roots); ++i) {
    	int v = roots[i];
    	dfs2(v, v, i);
    }
    for (int v : roots) {
    	dfs3(v, v, v);
    }

    vector<ll> ss;
    ll x = 0;
    for (int v : roots) {
    	ss.pb(subtree[v]);
    	x += belowSum[v];
    }

    SolveCycle solver(costs, ss);
    //cout << solver.ans[0] << " " << solver.ans[1] << " " << solver.ans[2] << endl;

    //cout << rootNum[2] << " " << aboveSum[2] << endl;

    for (int i = 0; i < n; ++i) {
    	ll ans = belowSum[i] + aboveSum[i] + depth[i] * (n - subtree[roots[rootNum[i]]]) + solver.ans[rootNum[i]] + (x - belowSum[roots[rootNum[i]]]);
    	/*if (i == 2) {
    		cout << "!" << belowSum[i] + aboveSum[i] << " " << depth[i] << " " << rootNum[i] << " " << solver.ans[rootNum[i]] << endl;
    	}*/
    	/*if (i == 4) {
    		cout << "!" << belowSum[i] << " " << aboveSum[i] << " " << depth[i] << endl;
    	}*/
    	cout << ans << " ";
    }
    cout << "\n";

}