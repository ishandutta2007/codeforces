#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

bool oki[N];
int par[N], hgt[N];

struct node {
    int x, y, z;
    node(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

vector<int> edg[N];
vector<node> sol;

void dfs(int x, int f, int &nd) {
    par[x] = f;
    hgt[x] = hgt[f] + 1;
    if (hgt[x] > hgt[nd]) {
        nd = x;
    }
    for (int y : edg[x]) {
        if (y != f) {
            dfs(y, x, nd);
        }
    }
}

long long ans;

void solve(int x, int f, int lv, int lm, int vm) {
    for (int y : edg[x]) {
        if (y != f) {
            solve(y, x, lv + 1, lm, vm);
        }
    }
    ans += lv + lm;
    sol.emplace_back(x, vm, x);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        edg[x].push_back(y);
        edg[y].push_back(x);
    }
    int v1 = 0, v2 = 0;
    hgt[0] = -1;
    dfs(1, 0, v1);
    dfs(v1, 0, v2);
    for (int i = v2; i; i = par[i]) {
        oki[i] = true;
    }
    for (int i = v2, l1 = 0, l2 = hgt[v2]; i; i = par[i], ++l1, --l2) {
        int lm, vm;
        (l1 >= l2) ? (lm = l1, vm = v2) : (lm = l2, vm = v1);
        for (int j : edg[i])
            if (!oki[j]) {
                solve(j, i, 1, lm, vm);
            }
    }
    for (int i = v2; i != v1; i = par[i]) {
        ans += hgt[i];
        sol.emplace_back(i, v1, i);
    }
    cout << ans << "\n";
    for (node s : sol) {
        cout << s.x << " " << s.y << " " << s.z << "\n";
    }
    return 0;
}