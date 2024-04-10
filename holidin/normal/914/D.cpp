#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
const long long mod = 1e9 + 7;

int m[3*N], v;
set <long long> s1;
set <pair<long long, int> > s2;

long long nod(long long a, long long b) {
    if (b > a)
        swap(a, b);
    if (b == 0)
        return a;
    else
        return nod(b, a % b);
}

long long nid(long long v, long long vl, long long vr, long long l, long long r) {
    if (l <= vl && vr <= r)
        return m[v];
    else if (vl >= r || l >= vr)
            return 0;
        else {
            long long nad = nod(nid(2*v + 1, vl, (vl + vr)/2, l, min((vl + vr)/2, r)), nid(2*v + 2, (vl + vr)/2, vr, max(l, (vl + vr)/2), r));
            return nad;
        }
}

bool can(long long v, long long vl, long long vr, long long l, long long r, long long x) {
    if (vr - vl == 1 || l >= vr || vl >= r)
        return true;
    else {
        long long a = nid(2*v + 1, vl, (vl + vr)/2, l, min(r, (vl + vr)/2)), b = nid(2*v + 2, (vl + vr)/2, vr, max(l, (vl + vr)/2), r);
        if (a % x == 0)
            if (can(2*v + 2, (vl + vr)/2, vr, max(l, (vl + vr)/2), r, x))
                return true;
        if (b % x == 0)
            if (can(2*v + 1, vl, (vl + vr)/2, l, min((vl + vr)/2, r), x))
                return true;
        return false;
    }
}

void als(int i, int j) {
    i = i + v - 2;
    m[i] = j;
    while (i > 0) {
        i = (i - 1) / 2;
        m[i] = nod(m[2*i + 1], m[2*i + 2]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    int i, j, n, k, t, l, r, x;
    cin >> n;
    v = 1;
    while (v < n) v = v * 2;
    for (i = 1; i <= n; ++i) {
        scanf("%d", &j);
        als(i, j);
    }
    cin >> k;
    for (i = 1; i <= k; ++i) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d%d", &l, &r, &x);
            if (can(0, 1, v + 1, l, r + 1, x))
                printf("%s", "YES\n");
            else
                printf("%s","NO\n");
        } else {
            s1.clear();
            s2.clear();
            scanf("%d%d", &l, &x);
            als(l, x);
        }
    }
}