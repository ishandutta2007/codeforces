#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 2;
const int LogN = 20;
vector <int> e[N];
int t[LogN], v, a[N], ans[N];

void add(vector <int> &v, int x) {
    for (int i = LogN - 1; i >= 0; --i)
    if ((x & t[i]) > 0) {
        if (v[i] == 0)
            v[i] = x;
        x ^= v[i];
    }
}

vector <int> merg(vector <int> a, vector <int> b) {
    for (int i = 0; i < b.size(); ++i)
    if (b[i] > 0)
        add(a, b[i]);
    return a;
}

int find_mx(vector <int> v) {
    int x = 0;
    for (int i = LogN - 1; i >= 0; --i)
    if ((x & t[i]) == 0)
        x ^= v[i];
    return x;
}

int cnt = 0;
void do_w(int vl, int vr, vector <pair<pair<int, int>, int> > q) {
    ++cnt;
    int i, j;
    if (vr - vl == 1) {
        for (int i = 0; i < q.size(); ++i)
            ans[q[i].se] = a[vl];
        return;
    }
    vector <pair<pair<int, int>, int> > v1, v2, v3;
    int mid = (vl + vr) / 2;
    for (i = 0; i < q.size(); ++i)
    if (q[i].fi.se < mid)
        v1.push_back(q[i]);
    else if (q[i].fi.fi >= mid)
            v2.push_back(q[i]);
        else
            v3.push_back(q[i]);
    if (v1.size() > 0)
        do_w(vl, mid, v1);
    if (v2.size() > 0)
        do_w(mid, vr, v2);
    for (i = 0; i < LogN; ++i)
        e[mid][i] = 0;
    for (i = mid - 1; i >= vl; --i) {
        e[i] = e[i + 1];
        add(e[i], a[i]);
    }
    add(e[mid], a[mid]);
    for (i = mid + 1; i < vr; ++i) {
        e[i] = e[i - 1];
        add(e[i], a[i]);
    }
    for (i = 0; i < v3.size(); ++i) {
        ans[v3[i].se] = find_mx(merg(e[v3[i].fi.fi], e[v3[i].fi.se]));
    }
}
int main() {
    int i, j, n, k, l, r;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    v = 1;
    while (v < n) v *= 2;
    t[0] = 1;
    for (i = 1; i < LogN; ++i)
        t[i] = t[i - 1] * 2;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    for (i = 0; i <= v + 1; ++i)
        e[i].resize(LogN);
    cin >> k;
    vector <pair<pair<int, int>, int> > que;
    for (i = 0; i < k; ++i) {
        cin >> l >> r;
        que.push_back({{l, r}, i});
    }
    do_w(1, v + 1, que);
    for (i = 0; i < k; ++i)
        cout << ans[i] << "\n";
}