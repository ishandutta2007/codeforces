#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int n, root;
int deg[MAXN], leaf[MAXN], par[MAXN], dub[MAXN], edge[MAXN];
vector < pair <int, int> > v[MAXN];
vector < pair < pair <int, int>, int> > sol;

void oper (int a, int b, int val) {
    sol.push_back(make_pair(make_pair(a, b), val));
    if (dub[a] < dub[b]) swap(a, b);
    while (dub[a] > dub[b]) {
        edge[a] -= val;
        a = par[a];
    }
    while (a != b) {
        edge[a] -= val;
        edge[b] -= val;
        a = par[a];
        b = par[b];
    }
}

void rjesi (int x, int y, int z, int val) {
    oper(leaf[x], leaf[y], val/2);
    oper(leaf[x], leaf[z], val/2);
    oper(leaf[y], leaf[z], -val/2);
}

void dfs (int x, int rod) {
    par[x] = rod;
    dub[x] = 1 + dub[rod];
    if (deg[x] == 1) leaf[x] = x;
    for (int i=0; i<v[x].size(); i++) {
        int sus = v[x][i].first;
        if (sus == rod) {
            edge[x] = v[x][i].second;
            continue;
        }
        dfs(sus, x);
        leaf[x] = leaf[sus];
    }
}

void rek (int x, int vani) {
    if (deg[x] == 1) return;
    int jen = -1, dva = -1, tri = -1;
    for (int i=0; i<v[x].size(); i++) {
        int sus = v[x][i].first;
        if (sus == par[x]) continue;
        if (jen == -1) {
            jen = sus;
        } else if (dva == -1) {
            dva = sus;
        } else if (tri == -1) {
            tri = sus;
        }
    }
    if (tri == -1) tri = vani;
    rjesi(jen, dva, tri, edge[jen]);
    rjesi(dva, jen, tri, edge[dva]);
    for (int i=0; i<v[x].size(); i++) {
        int sus = v[x][i].first;
        if (sus == par[x]) continue;
        if (sus == jen || sus == dva) continue;
        rjesi(sus, jen, dva, edge[sus]);
    }
    for (int i=0; i<v[x].size(); i++) {
        int sus = v[x][i].first;
        if (sus == par[x]) continue;
        if (sus == jen) {
            rek(jen, leaf[dva]);
        } else {
            rek(sus, leaf[jen]);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        deg[a]++; deg[b]++;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    root = -1;
    for (int i=1; i<=n; i++) {
        if (deg[i] >= 3) root = i;
        if (deg[i] == 2) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    if (root == -1) {
        cout << 1 << endl; // aaaaaaaaahhhhhhhhhhhh, u picku materinu
        cout << "1 2 " << v[1][0].second << endl;
        return 0;
    }
    dfs(root, 0);
    rek(root, 0);
    cout << sol.size() << endl;
    for (int i=0; i<sol.size(); i++) {
        int a = sol[i].first.first;
        int b = sol[i].first.second;
        int val = sol[i].second;
        cout << a << " " << b << " " << val << '\n';
    }
    return 0;
}