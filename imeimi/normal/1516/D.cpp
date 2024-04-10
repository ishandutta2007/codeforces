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

int n, q, A[100005], D[100005];
vector<int> L[100005];
int nxt[20][100005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    for (int i = 2; i <= 100000; ++i) {
        if (D[i]) continue;
        for (int j = i; j <= 100000; j += i) D[j] = i;
    }
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        int a = A[i];
        while (a > 1) {
            int x = D[a];
            while (a % x == 0) a /= x;
            L[x].push_back(i);
        }
        nxt[0][i] = n + 1;
    }
    for (int i = 2; i <= 100000; ++i) {
        if (L[i].empty()) continue;
        int p = L[i][0];
        for (int j = 1; j < int(L[i].size()); ++j) {
            nxt[0][p] = min(nxt[0][p], L[i][j]);
            p = L[i][j];
        }
    }
    for (int i = n - 1; i > 0; --i) nxt[0][i] = min(nxt[0][i], nxt[0][i + 1]);
    for (int i = 1; i < 20; ++i) {
        nxt[i - 1][n + 1] = n + 1;
        for (int j = 1; j <= n; ++j) {
            nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = 1;
        for (int i = 20; i--; ) {
            if (nxt[i][l] <= r) ans += 1 << i, l = nxt[i][l];
        }
        printf("%d\n", ans);
    }
    return 0;
}