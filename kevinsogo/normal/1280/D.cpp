#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Group {
    int win; ll adv;
    Group(int win = -1, ll adv = 0): win(win), adv(adv) {}
    Group operator+(const Group& o) const {
        return Group(win + o.win, adv + o.adv);
    }
    Group operator+() const {
        return Group(win + (adv > 0));
    }
    bool operator<(const Group& o) const {
        return win < o.win || win == o.win && adv < o.adv;
    }
};

vector<Group> convolve(const vector<Group>& fa, const vector<Group>& fb) {
    vector<Group> fi(fa.size() + fb.size());
    for (int a = 0; a < fa.size(); a++) {
        for (int b = 0; b < fb.size(); b++) {
            fi[a + b    ] = max(fi[a + b    ], fa[a] +  fb[b]);
            fi[a + b + 1] = max(fi[a + b + 1], fa[a] + +fb[b]);
        }
    }
    return fi;
}

vector<vector<Group>> f;
vector<vector<int>> adj;
void convolve_tree(int i, int p = -1) {
    for (int j : adj[i]) {
        if (j == p) continue;
        convolve_tree(j, i);
        f[i] = convolve(f[i], f[j]);
    }
}

int solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    f = vector<vector<Group>>(n, vector<Group>(1, Group(0)));
    for (int i = 0, b; i < n; i++) {
        scanf("%d", &b);
        f[i][0].adv -= b;
    }
    for (int i = 0, w; i < n; i++) {
        scanf("%d", &w);
        f[i][0].adv += w;
    }
    adj = vector<vector<int>>(n);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    convolve_tree(0);
    return (+f[0][m - 1]).win;
}

int main() {
    int z;
    for (scanf("%d", &z); z--; printf("%d\n", solve()));
}