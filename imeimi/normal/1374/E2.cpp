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

const int mx = 1e4 + 5;
int n, m, k;
vector<pii> T[2][2];

int cnt[1 << 15];
llong sum[1 << 15];

void update(int i, int s, int e, int x, int v) {
    cnt[i] += v;
    sum[i] += x * v;
    if (s == e) return;
    int m = (s + e) / 2;
    if (x <= m) update(i << 1, s, m, x, v);
    else update(i << 1 | 1, m + 1, e, x, v);
}

llong query(int i, int s, int e, int c) {
    if (c <= 0) return 0;
    if (c >= cnt[i]) return sum[i];
    if (s == e) return llong(s) * c;
    int m = (s + e) / 2;
    return query(i << 1, s, m, c) + query(i << 1 | 1, m + 1, e, c - cnt[i << 1]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        T[a][b].emplace_back(t, i);
    }
    for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) {
        sort(T[i][j].begin(), T[i][j].end());
    }
    if (int(T[0][1].size() + T[1][1].size()) < k) {
        printf("-1\n");
        return 0;
    }
    if (int(T[1][0].size() + T[1][1].size()) < k) {
        printf("-1\n");
        return 0;
    }
    int cnt = 0;
    llong sum = 0;
    for (; cnt < k && cnt < int(T[1][1].size()); ++cnt) sum += T[1][1][cnt].fs;
    for (int i = 0; i < k - cnt; ++i) sum += T[0][1][i].fs + T[1][0][i].fs;
    for (int i = cnt; i < int(T[1][1].size()); ++i) update(1, 1, mx, T[1][1][i].fs, 1);
    for (int i = k - cnt; i < int(T[0][1].size()); ++i) update(1, 1, mx, T[0][1][i].fs, 1);
    for (int i = k - cnt; i < int(T[1][0].size()); ++i) update(1, 1, mx, T[1][0][i].fs, 1);
    for (int i = 0; i < int(T[0][0].size()); ++i) update(1, 1, mx, T[0][0][i].fs, 1);
    int all = cnt + 2 * (k - cnt);
    if (m < all) {
        printf("-1\n");
        return 0;
    }
    llong ans = sum + query(1, 1, mx, m - all);
    int mni = cnt;
    for (--cnt, ++all; cnt >= 0 && k - cnt - 1 < int(min(T[0][1].size(), T[1][0].size())) && all <= m; --cnt, ++all) {
        sum += T[0][1][k - cnt - 1].fs + T[1][0][k - cnt - 1].fs - T[1][1][cnt].fs;
        update(1, 1, mx, T[0][1][k - cnt - 1].fs, -1);
        update(1, 1, mx, T[1][0][k - cnt - 1].fs, -1);
        update(1, 1, mx, T[1][1][cnt].fs, 1);
        llong val = sum + query(1, 1, mx, m - all);
        if (val < ans) {
            mni = cnt;
            ans = val;
        }
    }
    printf("%lld\n", ans);
    cnt = mni;
    for (int i = 0; i < cnt; ++i) printf("%d ", T[1][1][i].se);
    for (int i = 0; i < k - cnt; ++i) printf("%d ", T[0][1][i].se);
    for (int i = 0; i < k - cnt; ++i) printf("%d ", T[1][0][i].se);
    vector<pii> V;
    for (int i = cnt; i < int(T[1][1].size()); ++i) V.push_back(T[1][1][i]);
    for (int i = k - cnt; i < int(T[0][1].size()); ++i) V.push_back(T[0][1][i]);
    for (int i = k - cnt; i < int(T[1][0].size()); ++i) V.push_back(T[1][0][i]);
    for (int i = 0; i < int(T[0][0].size()); ++i) V.push_back(T[0][0][i]);
    sort(V.begin(), V.end());
    for (int i = 0; i < m - (cnt + 2 * (k - cnt)); ++i) printf("%d ", V[i].se);
    return 0;
}