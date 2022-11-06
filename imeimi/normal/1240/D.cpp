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
int A[300005];
int root[300005];
map<int, int> mn[300005];
int cnt[300005];
llong solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    for (int i = 1; i <= n + 1; ++i) {
        mn[i].clear();
        root[i] = i;
        cnt[i] = 0;
    }
    llong ans = 0;
    for (int i = n - 1; i > 0; --i) {
        if (A[i] == A[i + 1]) {
            int nxt = i + 2;
            root[i] = root[i + 2];
            ans += ++cnt[root[i]];
            debug("%d, %d\n", i, cnt[root[i]]);
            if (i + 2 <= n) mn[root[i]][A[i + 2]] = i + 2;
        }
        else {
            if (mn[root[i + 1]].count(A[i]) == 0) {
                root[i] = i;
                continue;
            }
            int x = mn[root[i + 1]][A[i]];
            debug("nxt[%d]=%d\n", i, x);
            root[i] = root[x + 1];
            ans += ++cnt[root[i]];
            debug("%d, %d\n", i, cnt[root[i]]);
            if (x + 1 <= n) mn[root[i]][A[x + 1]] = x + 1;
        }
        debug("root[%d]=%d\n", i, root[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) printf("%lld\n", solve());
    return 0;
}