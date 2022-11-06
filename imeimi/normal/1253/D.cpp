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

int n, m;
int P[200001];
int mx[200001], mn[200001];

int find(int x) {
    if (P[x]) return P[x] = find(P[x]);
    return x;
}

int merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    P[y] = x;
    mx[x] = max(mx[x], mx[y]);
    mn[x] = min(mn[x], mn[y]);
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        mn[i] = mx[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        int x = find(i), y = find(i - 1);
        if (x == y) continue;
        if (mx[x] < mn[y]) continue;
        if (mx[y] < mn[x]) continue;
        merge(x, y);
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}