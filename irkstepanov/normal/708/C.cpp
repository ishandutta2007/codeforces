#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

vector<vector<int> > g;
vector<int> subtree;

void dfs(int v, int p)
{
    subtree[v] = 1;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
            subtree[v] += subtree[to];
        }
    }
}

vector<int> tree;

void dfs(int v, int p, int color)
{
    tree[v] = color;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v, color);
        }
    }
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    cin >> n;

    g.resize(n);
    subtree.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0, 0);
    int root = 0;

    while (true) {
        int bad = -1;
        for (int to : g[root]) {
            if (2 * subtree[to] > n) {
                bad = to;
            }
        }
        if (bad == -1) {
            break;
        }
        subtree[root] -= subtree[bad];
        subtree[bad] += subtree[root];
        root = bad;
    }

    bool two = false;
    for (int to : g[root]) {
        if (2 * subtree[to] == n) {
            two = true;
        }
    }

    if (two) {
        for (int i = 0; i < n; ++i) {
            cout << "1 ";
        }
        cout << "\n";
        return 0;
    }

    vector<char> can_be(n, false);
    can_be[root] = true;

    int maxx = 0, max_i = -1;
    for (int son : g[root]) {
        if (subtree[son] > maxx) {
            maxx = subtree[son];
            max_i = son;
        }
    }

    tree.resize(n);
    for (int son : g[root]) {
        dfs(son, root, son);
    }

    for (int i = 0; i < n; ++i) {
        if (i == root) {
            continue;
        }
        if (tree[i] == max_i) {
            continue;
        }
        if (2 * (n - subtree[i] - maxx) <= n) {
            can_be[i] = true;
        }
    }

    maxx = 0;
    int new_max_i = -1;
    for (int son : g[root]) {
        if (son == max_i) {
            continue;
        }
        if (subtree[son] > maxx) {
            maxx = subtree[son];
            new_max_i = son;
        }
    }

    if (new_max_i != -1) {
        for (int i = 0; i < n; ++i) {
            if (i == root) {
                continue;
            }
            if (tree[i] != max_i) {
                continue;
            }
            if (2 * (n - subtree[i] - maxx) <= n) {
                can_be[i] = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << (can_be[i] ? "1 " : "0 ");
    }
    cout << "\n";

}