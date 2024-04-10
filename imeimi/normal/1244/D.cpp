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

int n;
vector<int> edge[100001];
int C[100001][3];
int ord[100001];
int ans[100001];

void dfs(int x, int p) {
    static int tp = 0;
    ord[++tp] = x;
    for (int i : edge[x]) {
        if (i == p) continue;
        dfs(i, x);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    for (int i = 0; i < 3; ++i) for (int j = 1; j <= n; ++j) {
        cin >> C[j][i];
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    int st = 0;
    for (int i = 1; i <= n; ++i) {
        if (edge[i].size() == 1) st = i;
        if (edge[i].size() > 2) {
            printf("-1\n");
            return 0;
        }
    }
    dfs(st, 0);
    llong ansv = 1e18;
    int ansi = -1, ansj = -1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) continue;
            int c[3];
            c[1] = i;
            c[2] = j;
            c[0] = i ^ j ^ 3;
            llong sum = 0;
            for (int k = 1; k <= n; ++k) {
                sum += C[ord[k]][c[k % 3]];
            }
            if (sum < ansv) {
                ansv = sum;
                ansi = i;
                ansj = j;
            }
        }
    }
    int c[3];
    c[1] = ansi;
    c[2] = ansj;
    c[0] = ansi ^ ansj ^ 3;
    printf("%lld\n", ansv);
    for (int i = 1; i <= n; ++i) {
        ans[ord[i]] = c[i % 3] + 1;
    }
    for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
    return 0;
}