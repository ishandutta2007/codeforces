#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> edge;

vector<edge> edges;
int n;
vector<vector<int> > g;
vector<char> used;
vector<int> comp;

void dfscomp(int v, int number)
{
    used[v] = true;
    comp[v] = number;
    for (int id : g[v]) {
        edge& e = edges[id];
        if (!used[e.second]) {
            dfscomp(e.second, number);
        }
    }
}

vector<char> deleted;

void dfs(int v)
{
    used[v] = true;
    for (int id : g[v]) {
        if (deleted[id]) {
            continue;
        }
        edge& e = edges[id];
        if (!used[e.second]) {
            dfs(e.second);
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("division.in");
    //ofstream cout("division.out");

    cin >> n;
    g.resize(n);
    edges.resize(2 * n - 2);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[2 * i] = mp(u, v);
        edges[2 * i + 1] = mp(v, u);
        g[u].pb(2 * i);
        g[v].pb(2 * i + 1);
    }

    used.assign(n, false);
    comp.resize(n);
    int cnt = 0;
    vector<int> start;

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfscomp(i, cnt);
            ++cnt;
            start.pb(i);
        }
    }

    cout << sz(start) - 1 << "\n";
    deleted.assign(2 * n - 2, false);
    for (int step = 0; step < sz(start) - 1; ++step) {
        int u, v;
        for (int i = 0; i < 2 * n - 2; i += 2) {
            if (deleted[i]) {
                continue;
            }
            deleted[i] = deleted[i + 1] = true;
            used.assign(n, false);
            dfs(edges[i].first);
            if (used[edges[i].second]) {
                u = edges[i].first;
                v = edges[i].second;
                break;
            }
            deleted[i] = deleted[i + 1] = false;
        }
        cout << u + 1 << " " << v + 1 << " " << start[step] + 1 << " " << start[step + 1] + 1 << "\n";
    }

}