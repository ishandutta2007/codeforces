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
int has[100001];
int mn[100001];
int mx[100001];

struct fenwick {
    int fen[1000002];
    void update(int i) {
        ++i;
        while (i <= 1000001) {
            ++fen[i];
            i += i & -i;
        }
    }
    int query(int i) {
        ++i;
        int ret = 0;
        while (i) {
            ret += fen[i];
            i -= i & -i;
        }
        return ret;
    }
} fen;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int l;
        cin >> l;
        mn[i] = 1e7;
        while (l--) {
            int x;
            cin >> x;
            if (mn[i] < x) has[i] = 1;
            mn[i] = min(mn[i], x);
            mx[i] = max(mx[i], x);
        }
        cnt += has[i];
        if (has[i]) continue;
        fen.update(mn[i]);
    }
    llong ans = 2ll * n * cnt - (llong)cnt * cnt;
    for (int i = 1; i <= n; ++i) {
        if (has[i]) continue;
        ans += fen.query(mx[i] - 1);
    }
    printf("%lld\n", ans);
    return 0;
}