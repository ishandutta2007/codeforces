#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

class Bridges {
public:
    Bridges(vector<vector<int> > h) {
        g = h;
        int n = sz(g);
        used.assign(n, false);
        ret.resize(n);
        tin.resize(n);
        timer = 0;
        dfs(0, 0);
        int cc = 0;
        compId.assign(n, -1);

        for (int i = 0; i < n; ++i) {
            if (compId[i] != -1) {
                continue;
            }
            vector<int> vis;
            compId[i] = cc;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                vis.pb(v);
                for (int to : g[v]) {
                    if (bridges.count({v, to})) {
                        continue;
                    }
                    if (compId[to] != -1) {
                        continue;
                    }
                    compId[to] = cc;
                    q.push(to);
                }
            }
            comps.pb(vis);
            ++cc;
        }

        tree.resize(cc);
        for (auto it : bridges) {
            int u = it.first, v = it.second;
            u = compId[u], v = compId[v];
            if (u < v) {
                tree[u].pb(v);
                tree[v].pb(u);
            }            
        }
    }

    void get(vector<vector<int> >& a, vector<vector<int> >& b) {
        a = comps;
        b = tree;
    }
private:
    vector<vector<int> > g;
    vector<bool> used;
    vector<int> ret;
    vector<int> tin;
    int timer;
    set<pii> bridges;
    vector<vector<int> > comps;
    vector<int> compId;
    vector<vector<int> > tree;

    void dfs(int v, int p) {
        tin[v] = ret[v] = timer++;
        used[v] = true;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            if (used[to]) {
                ret[v] = min(ret[v], tin[to]);
            } else {
                dfs(to, v);
                ret[v] = min(ret[v], ret[to]);
                if (ret[to] > tin[v]) {
                    bridges.insert({to, v});
                    bridges.insert({v, to});
                }
            }
        }
    }
};

void add(vector<pii>& ans, const vector<int>& a, const vector<int>& b, const set<pii>& setik) {
    /*for (int x : a) {
        cout << "!" << x << " ";
    }
    cout << endl;
    for (int y : b) {
        cout << "!" << y << " " ;
    }
    cout << endl;*/
    for (int x : a) {
        for (int y : b) {
            if (!setik.count({x, y})) {
                ans.pb({x, y});
                return;
            }
        }
    }
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > g(n);
    set<pii> setik;
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        setik.insert({u, v});
        setik.insert({v, u});
        g[u].pb(v);
        g[v].pb(u);
    }

    if (n == 2) {
        cout << "-1\n";
        return 0;
    }

    Bridges B(g);
    vector<vector<int> > comps;
    B.get(comps, g);

    n = sz(comps);
    assert(n == sz(g));

    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    if (n == 2) {
        for (int x : comps[0]) {
            for (int y : comps[1]) {
                if (!setik.count({x, y})) {
                    cout << "1\n";
                    cout << x + 1 << " " << y + 1 << "\n";
                    return 0;
                }
            }
        }
    }

    int r;
    for (int i = 0; i < n; ++i) {
        if (sz(g[i]) > 1) {
            r = i;
        }
    }

    vector<bool> alive(n, true);
    vector<pii> ans;
    while (true) {
        vector<vector<int> > vct;
        vector<bool> used(n, false);
        used[r] = true;
        for (int son : g[r]) {
            if (!alive[son]) {
                continue;
            }
            vector<int> curr;
            used[son] = true;
            queue<int> q;
            q.push(son);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                if (alive[v] && sz(g[v]) == 1) {
                    curr.pb(v);
                }
                for (int to : g[v]) {
                    if (!used[to]) {
                        q.push(to);
                        used[to] = true;
                    }
                }
            }
            if (!curr.empty()) {
                curr.pb(son);
                vct.pb(curr);
            }
        }
        alive[r] = false;
        sort(all(vct), [&] (const vector<int>& x, const vector<int>& y) {
            return sz(x) > sz(y);
        });
        vector<int> par;
        for (int i = 0; i < sz(vct); ++i) {
            par.pb(vct[i].back());
            vct[i].pop_back();
        }
        int sum = 0;
        for (int i = 1; i < sz(vct); ++i) {
            sum += sz(vct[i]);
        }

        int arb = -1;
        int done = 0;
        int init = sum + sz(vct[0]);
        while (true) {
            int max1 = -1, max2 = -1;
            for (int i = 0; i < sz(vct); ++i) {
                if (vct[i].empty()) {
                    continue;
                }
                if (max1 == -1 || sz(vct[i]) > sz(vct[max1])) {
                    max2 = max1;
                    max1 = i;
                } else if (max2 == -1 || sz(vct[i]) > sz(vct[max2])) {
                    max2 = i;
                }
            }
            if (max1 == -1 || max2 == -1) {
                break;
            }
            arb = vct[max1].back();
            add(ans, comps[vct[max1].back()], comps[vct[max2].back()], setik);
            alive[vct[max1].back()] = false;
            vct[max1].pop_back();
            alive[vct[max2].back()] = false;
            vct[max2].pop_back();
            done += 2;
        }
        if (done == init) {
            break;
        }

        if (done == init - 1) {
            for (int i = 0; i < sz(vct); ++i) {
                if (vct[i].empty()) {
                    continue;
                }
                add(ans, comps[vct[i].back()], comps[arb], setik);
                alive[vct[i].back()] = false;
            }
            break;
        } else {
            r = par[0];
        }

    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }

}