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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n, m, b;
vector<int> edge[100001];
vector<int> g[1001];
int par[100001];
int dep[100001];

void dfs(int x, int p) {
    par[x] = p;
    dep[x] = dep[p] + 1;
    g[dep[x] % (b - 1)].push_back(x);
    for (int i : edge[x]) {
        if (i == p) continue;
        if (dep[i]) {
            if (dep[x] - dep[i] >= b - 1) {
                printf("2\n%d\n", dep[x] - dep[i] + 1);
                for (int j = x; j != par[i]; j = par[j]) {
                    printf("%d ", j);
                }
                exit(0);
            }
            continue;
        }
        dfs(i, x);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n >> m;
    for (b = 3; b * b < n; ++b);
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 0; ; ++i) {
        if (int(g[i].size()) >= b) {
            printf("1\n");
            for (int j = 0; j < b; ++j) {
                printf("%d ", g[i][j]);
            }
            exit(0);
        }
    }
    return 1;
}