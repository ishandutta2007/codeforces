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
int A[100001];
pii seg[1 << 19];

pii operator+(pii a, pii b) {
    return pii(min(a.fs, b.fs), max(a.se, b.se));
}

void init(int i, int s, int e) {
    if (s == e) {
        if (s > n) seg[i] = pii(A[s - n], A[s - n]);
        else seg[i] = pii(A[s], A[s]);
        return;
    }
    int m = (s + e) / 2;
    init(i << 1, s, m);
    init(i << 1 | 1, m + 1, e);
    seg[i] = seg[i << 1] + seg[i << 1 | 1];
}

const int inf = 1e9 + 7;
pii query(int i, int s, int e, int x, int y) {
    if (e < x || y < s) return pii(inf, -inf);
    if (x <= s && e <= y) return seg[i];
    int m = (s + e) / 2;
    return query(i << 1, s, m, x, y) + query(i << 1 | 1, m + 1, e, x, y);
}

int ans[100001];
int dfs(int x) {
    if (ans[x] > 0) return ans[x];
    int nxt;
    {
        int s = x + 1, e = x + n;
        while (s < e) {
            int m = (s + e) / 2;
            if (query(1, 1, n + n, x + 1, m).se >= A[x]) e = m;
            else s = m + 1;
        }
        nxt = s;
    }
    {
        int s = x + 1, e = nxt;
        while (s < e) {
            int m = (s + e) / 2;
            if (query(1, 1, n + n, x + 1, m).fs * 2 < A[x]) e = m;
            else s = m + 1;
        }
        if (s < nxt) return ans[x] = s - x;
    }
    return ans[x] = nxt - x + dfs(nxt > n ? nxt - n : nxt);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    init(1, 1, n + n);
    debug("%d %d\n", seg[1].fs, seg[1].se);
    if (seg[1].fs * 2 >= seg[1].se) {
        for (int i = 1; i <= n; ++i) printf("-1 ");
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", dfs(i));
    }
    return 0;
}