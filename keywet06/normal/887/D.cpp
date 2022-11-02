#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int n, splus, sminus, dplus, dminus, start, len;
int *t, *q;

int64 *s, *ds, *ts, *tds;

void build(int64 *a, int64 *t, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, t, v * 2, tl, tm);
        build(a, t, v * 2 + 1, tm + 1, tr);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

int64 minsum(int64 *a, int64 *t, int v, int tl, int tr, int l, int r) {
    if (l > r) return 9223372036854775807ll;
    if (l == tl && r == tr) return t[v];
    int tm = (tl + tr) / 2;
    return min(minsum(a, t, v * 2, tl, tm, l, min(r, tm)),
               minsum(a, t, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int getLeft(int time, int *a, int l, int r) {
    if (a[l] >= time) return l;
    if (a[r] < time) return -1;
    while (r - l > 1) {
        int middle = (r + l) / 2;
        if (a[middle] >= time) {
            r = middle;
        } else {
            l = middle;
        }
    }
    return r;
}

int getRight(int time, int *a, int l, int r) {
    if (a[l] > time) return -1;
    if (a[r] <= time) return r;
    while (r - l > 1) {
        int middle = (r + l) / 2;
        if (a[middle] <= time) {
            l = middle;
        } else {
            r = middle;
        }
    }
    return l;
}

bool check(int time) {
    int l = getLeft(time, t, 0, n - 1);
    int r = getRight(time + len - 1, t, 0, n - 1);
    if (l == -1 || r == -1) {
        return minsum(s, ts, 1, 0, n - 1, 0, n - 1) + start >= 0;
    }
    int64 rate = start;
    if (l != 0) {
        int left = 0;
        int right = l - 1;
        int64 diff = minsum(s, ts, 1, 0, n - 1, left, right);
        if (rate + diff < 0) return false;
        rate += s[right];
    }
    {
        int left = l;
        int right = r;
        int64 diff = minsum(ds, tds, 1, 0, n - 1, left, right);
        if (left != 0) diff = diff - ds[left - 1];
        if (rate + diff < 0) return false;
        rate += diff;
    }
    return true;
}

int main() {
    cin >> n >> splus >> sminus >> dplus >> dminus >> start >> len;
    sminus *= -1;
    dminus *= -1;
    t = new int[n];
    q = new int[n];
    s = new int64[n];
    ds = new int64[n];
    for (int i = 0; i < n; ++i) cin >> t[i] >> q[i];
    s[0] = q[0] == 1 ? splus : sminus;
    ds[0] = q[0] == 1 ? dplus : dminus;
    for (int i = 1; i < n; ++i) {
        s[i] = s[i - 1] + (q[i] == 1 ? splus : sminus);
        ds[i] = ds[i - 1] + (q[i] == 1 ? dplus : dminus);
    }
    ts = new int64[(n + 1) * 4];
    tds = new int64[(n + 1) * 4];
    build(s, ts, 1, 0, n - 1);
    build(ds, tds, 1, 0, n - 1);
    vector<int> times;
    times.push_back(0);
    for (int i = 0; i < n; ++i) {
        times.push_back(t[i] + 1);
        times.push_back(t[i] + 1 - len);
    }
    sort(times.begin(), times.end());
    for (int i = 0; i < times.size(); ++i) {
        if (times[i] < 0) continue;
        if (check(times[i])) {
            cout << times[i];
            return 0;
        }
    }
    cout << -1;
    return 0;
}