#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

int n;
const int maxn = 200100;
int a[maxn];
int b[maxn];
vector<int> path;
vector<int> g[maxn];

void go(int u, int prev = -1) {
    path.push_back(u);
    if (prev != -1) {
        b[u] *= -1;
    }
    for (int v: g[u]) {
        if (v == prev)
            continue;
        go(v, u);
        path.push_back(u);
        b[u] *= -1;
        if (b[v] == -1) {
            path.push_back(v);
            b[v] *= -1;
            path.push_back(u);
            b[u] *= -1;
        }
    }
    if (prev == -1 && b[u] == -1) {
        int v = g[u][0];
        path.push_back(v);
        b[v] *= -1;
        path.push_back(u);
        b[u] *= -1;
        path.push_back(v);
        b[v] *= -1;
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("e.in", "r", stdin));
    #else
    #endif
    cin >> n;
    forn (i, n)
        scanf("%d", a + i);
    forn (i, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    forn (i, n)
        b[i] = a[i];

    go(0);

    forn (i, n)
        assert(b[i] == 1);
    for (int u: path)
        cout << u + 1 << ' ';
    cout << '\n';
}