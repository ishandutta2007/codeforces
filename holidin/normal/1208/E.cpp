#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define uniq(x) x.resize(unique(x.begin(), x.end()) - x.begin())
using namespace std;
const int N = 8e6 + 52;
const long long inf = 1e10;
int m[N], a[N], n;
bool use[N];


void maxr(int v, int vl, int vr, int l, int r, int x) {
    if (l <= vl && vr <= r)
        m[v] = max(m[v], x);
    else if (l >= vr || vl >= r)
            return;
        else {
            use[v] = 1;
            maxr(2 * v + 1, vl, (vl + vr) / 2, l, r, x);
            maxr(2 * v + 2, (vl + vr) / 2, vr, l, r, x);
        }
}

void cl(int v, int vl, int vr, int l, int r) {
    if (l <= vl && vr <= r)
        m[v] = -inf;
    else if (l >= vr || vl >= r)
            return;
        else {
            use[v] = 0;
            cl(2 * v + 1, vl, (vl + vr) / 2, l, r);
            cl(2 * v + 2, (vl + vr) / 2, vr, l, r);
        }
}

int lpos = 1, was = 0;
vector <pair<int, long long> > t;

void dfs(int v, int vl, int vr, int x) {
    x = max(x, m[v]);
    if (!use[v]) {
        if (x != was)
            t.push_back({vl, x - was});
        was = x;
    } else {
        dfs(2 * v + 1, vl, (vl + vr) / 2, x);
        dfs(2 * v + 2, (vl + vr) / 2, vr, x);
    }
}

void solve() {
    int i, j, k, b, w;
    long long p0 = 0;
    cin >> n >> w;
    for (i = 0; i < 4 * w; ++i)
        m[i] = -inf;
    for (i = 1; i <= n; ++i) {
        cin >> k;
        maxr(0, 1, w + 1, 1, w - k + 1, 0);
        maxr(0, 1, w + 1, k + 1, w + 1, 0);
        for (j = 1; j <= k; ++j) {
            cin >> a[j];
            maxr(0, 1, w + 1, j, w - (k - j) + 1, a[j]);
        }
        lpos = 1;
        was = 0;
        dfs(0, 1, w + 1, -inf);
        cl(0, 1, w + 1, 1, w - k + 1);
        cl(0, 1, w + 1, k + 1, w + 1);
        for (j = 1; j <= k; ++j)
            cl(0, 1, w + 1, j, w - (k - j) + 1);
    }
    sort(t.begin(), t.end());
    long long ans = 0;
    j = 0;
    for (i = 1; i <= w; ++i) {
        while (j < t.size() && t[j].fi <= i) {
            ans += t[j].se;
            ++j;
        }
        cout << ans << ' ';
    }
}

signed main() {
    int i, test;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}