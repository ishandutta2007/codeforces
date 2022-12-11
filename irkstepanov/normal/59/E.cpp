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

struct datum {
	int type; // 1 -- vertex, 2 -- triplet
	int id;
};

const int inf = 1e9;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    vector<set<int> > gg(n);
    set<pii> edges;
    while (m--) {
    	int u, v;
    	cin >> u >> v;
    	--u, --v;
    	gg[u].insert(v);
    	gg[v].insert(u);
    	edges.insert({u, v});
    	edges.insert({v, u});
    }

    map<pii, set<int> > hard;
    for (int i = 0; i < k; ++i) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	--u, --v, --w;
    	if (!edges.count({u, v}) || !edges.count({v, w})) {
    		continue;
    	}
    	//cout << "!!" << u << " " << v << endl;
    	hard[{u, v}].insert(w);
    }

    map<pii, int> hard_id;
    vector<pii> hards;
    for (auto it : hard) {
    	hard_id[it.first] = sz(hards);
    	hards.pb(it.first);
    }

    vector<int> g(n, inf);
    g[0] = 0;
    vector<int> f(sz(hard), inf);

    queue<datum> q;
    q.push({1, 0});
    vector<datum> pr_g(n), pr_f(sz(hard));

    while (!q.empty()) {
    	datum d = q.front();
    	q.pop();
    	if (d.type == 1) {
    		int v = d.id;
    		for (int w : gg[v]) {
    			int val = g[v] + 1;
    			if (!hard.count({v, w})) {
    				if (g[w] > val) {
    					g[w] = val;
    					q.push({1, w});
    					pr_g[w] = d;
    				}
    			} else {
    				int id = hard_id[{v, w}];
    				if (f[id] > val) {
    					f[id] = val;
    					q.push({2, id});
    					pr_f[id] = d;
    				}
    			}
    		}

    		gg[v].clear();
    	} else {
    		int id = d.id;
    		int u = hards[id].first;
    		int v = hards[id].second;
    		//cout << u + 1 << " " << v + 1 << endl;
    		vector<int> todel;
    		for (int w : gg[v]) {
    			if (hard[{u, v}].count(w)) {
    				continue;
    			}
    			//cout <<"!" <<  v + 1 << " " << w + 1 << endl;
    			int val = f[id] + 1;
    			if (!hard.count({v, w})) {
    				//cout << "NOT " << v + 1 << " " << w + 1 << endl;
    				if (g[w] > val) {
    					g[w] = val;
    					q.push({1, w});
    					pr_g[w] = d;
    				}
    			} else {
					//cout << "IN " << v + 1 << " " << w + 1 << endl;
					int nx = hard_id[{v, w}];
					if (f[nx] > val) {
						f[nx] = val;
						q.push({2, nx});
						pr_f[nx] = d;
					}
				}
    		}

    		for (int w : todel) {
    			gg[v].erase(w);
    		}
    	}
    }

    int ans = g[n - 1];
    datum d = {1, n - 1};
    for (int i = 0; i < sz(f); ++i) {
    	if (hards[i].second == n - 1 && f[i] < ans) {
    		ans = f[i];
    		d = {2, i};
    	}
    }

    if (ans == inf) {
    	cout << "-1\n";
    	return 0;
    }
    cout << ans << "\n";
    vector<datum> order;
    while (ans--) {
    	order.pb(d);
    	if (d.type == 1) {
    		d = pr_g[d.id];
    	} else {
    		d = pr_f[d.id];
    	}
    }

    reverse(all(order));
    cout << "1 ";
    for (int i = 0; i < sz(order); ++i) {
    	d = order[i];
    	if (d.type == 1) {
    		cout << d.id + 1 << " ";
    	} else {
    		cout << hards[d.id].second + 1 << " ";
    	}
    }
    cout << "\n";

}