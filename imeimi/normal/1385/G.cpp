#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<lf, lf> pff;

int n;
int A[2][200001];
vector<int> P[200001];
int par[400005];
vector<int> G[400005];

int find(int x) {
    if (par[x]) return par[x] = find(par[x]);
    return x;
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    par[y] = x;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) P[i].clear();
    for (int i = 0; i < 2; ++i) for (int j = 1; j <= n; ++j) {
        cin >> A[i][j];
        P[A[i][j]].push_back(i + j + j);
    }
    memset(par, 0, sizeof(int) * (2 * n + 5));
    for (int i = 1; i <= n; ++i) {
        if (int(P[i].size()) != 2) return (void)printf("-1\n");
        int a = P[i][0], b = P[i][1];
        merge(a, b ^ 1);
        merge(a ^ 1, b);
    }
    for (int i = 1; i <= n; ++i) {
        int x = find(i + i), y = find(i + i + 1);
        if (x == y) return (void)printf("-1\n");
        G[x].push_back(i + i);
        G[y].push_back(i + i + 1);
    }
    vector<int> ans;
    for (int i = 2; i <= n + n + 1; ++i) {
        if (G[i].empty()) continue;
        vector<int> V[2];
        for (int j : G[i]) V[j & 1].push_back(j);
        if (V[0].size() > V[1].size()) swap(V[0], V[1]);
        for (int j : V[0]) ans.push_back(j / 2);
        G[i].clear();
        G[find(i ^ 1)].clear();
    }
    printf("%u\n", ans.size());
    for (int i : ans) printf("%d ", i);
    printf("\n");
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}